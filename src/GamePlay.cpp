//
//  GamePlay.cpp
//  boardGameCode
//
//  Created by Alexander Clarke on 2014-11-28.
//  Copyright (c) 2014 Alexander Clarke. All rights reserved.
//
#include "GamePlay.h"
#include <iostream>
#include "GameBoard.h"
#include "Tile.h"
#include "Player.h"
#include "TileFactory.h"
#include <fstream>

void play() {
    GameBoard<class Tile, class Player> * board = new GameBoard<class Tile, class Player>();
    std::string input;
    std::cout<<"Load Game?"<<std::endl;
    getline(std::cin,input);
    if (input == "yes") {
        std::ifstream is("savedGame.txt");
        //check is file exists
        is>>*board;
        is.close();
    }else{
        std::cout<<"New Game"<<std::endl;
        std::cout<<"Select number of rows"<<std::endl;
        getline(std::cin,input);
        int row = std::stoi(input);
        std::cout<<"Select number of columns"<<std::endl;
        getline(std::cin,input);
        int col =  std::stoi(input);
        std::cout<<"Select number of players"<<std::endl;
        getline(std::cin,input);
        int numPlayers = std::stoi(input);
        board = new GameBoard<class Tile, class Player>(row,col,numPlayers);
        TileFactory * tf = TileFactory::get(row*col);
        for (int i = 0; i<row; i++) {
            for (int j = 0; j<col; j++) {
                board->add(*tf->next(), i, j);
            }
        }
        for (int i = 0; i<numPlayers; i++) {
            std::cout<<"Enter name for Player "<<i+1<<std::endl;
            getline(std::cin,input);
            board->setPlayer(*new Player(input));
        }
    }
    bool endGame = false;
    while (!endGame) {
        for (int i = 0; i<board->getNumPlayers(); i++) {
            Player player = board->getPlayerList()[i].player;
            std::cout<<"Show Surrounding Squares(yes/no)?"<<std::endl;
            getline(std::cin,input);
            int row;
            int col;
            if (input == "yes") {
                player.printStats();
                board->getPlayerCoordinates(player.getName(), &row, &col);
                board->printNeighbours(row, col);
                std::cout<<"Where do you want to move?"<<std::endl;
                getline(std::cin,input);
                if (input=="down") {
                    GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::DOWN;
                    std::string str = player.getName();
                    board->move(move, str);
                }else if (input=="up"){
                    GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::UP;
                    std::string str = player.getName();
                    board->move(move, str);
                }else if (input=="left"){
                    GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::LEFT;
                    std::string str = player.getName();
                    board->move(move, str);
                }else if (input=="right"){
                    GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::RIGHT;
                    std::string str = player.getName();
                    board->move(move, str);
                }
                std::cout<<"Commit Action"<<std::endl;
                getline(std::cin,input);
                if(input =="yes"){
                    board->getPlayerCoordinates(player.getName(), &row, &col);
                    if(board->payPlayers(player, row, col)){
                        board->getTile(row, col).clone()->action(player);
                        board->updatePlayer(player);
                    }else{
                        std::cout<<"Can't pay the players currently on that square. Action aborted."<<std::endl;
                    }
                }
                std::cout<<"Save and Quit?"<<std::endl;
                getline(std::cin,input);
                if(input =="yes"){
                    std::ofstream os;
                    os.open("savedGame.txt");
                    os<<*board;
                    os.close();
                    delete board;
                    endGame = true;
                    break;
                }
                else{
                
                }
            }
        }
    }
}

