//
//  main.cpp
//  boardGameCode
//
//  Created by Alexander Clarke on 2014-11-07.
//  Copyright (c) 2014 Alexander Clarke. All rights reserved.
//

#include <iostream>
#include "GameBoard.h"
#include "Tile.h"
#include "Player.h"
#include "TileFactory.h"
#include <fstream>

int main() {
    GameBoard<class Tile, class Player> * board;
    Player p1;
    Player p2;
    //std::ifstream is("savedGame.txt");
    //if (is) {
      //  is>>*board;
        //is.close();
        
    //}else{
    board = new GameBoard<Tile, Player>(5,5,2);
    TileFactory * tf = TileFactory::get(25);
    for (int i = 0; i<5; i++) {
        for (int j = 0; j<5; j++) {
            board->add(*tf->next(), i, j);
        }
    }
    p1 = *new Player("Player1");
    p2 = *new Player("Player2");
    board->setPlayer(p1);
    board->setPlayer(p2);
    //}
    int row,col;
    while(true){
        std::cout<<"Show Surrounding Squares?"<<std::endl;
        std::string input;
        getline(std::cin,input);
        if (input == "yes1") {
            p1.printStats();
            board->getPlayerCoordinates(p1.getName(), &row, &col);
            board->printNeighbours(row, col);
            std::cout<<"Where do you want to move?"<<std::endl;
            getline(std::cin,input);
            if (input=="down") {
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::DOWN;
                std::string str = p1.getName();
                board->move(move, str);
            }else if (input=="up"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::UP;
                std::string str = p1.getName();
                board->move(move, str);
            }else if (input=="left"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::LEFT;
                std::string str = p1.getName();
                board->move(move, str);
            }else if (input=="right"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::RIGHT;
                std::string str = p1.getName();
                board->move(move, str);
            }
            std::cout<<"Commit Action"<<std::endl;
            getline(std::cin,input);
            if(input =="yes"){
                board->getPlayerCoordinates(p1.getName(), &row, &col);
                //if(board->payPlayers(p1, row, col)){
                    board->getTile(row, col).clone()->action(p1);
                //}
            }
           // std::cout<<"Save and Quit?"<<std::endl;
            //getline(std::cin,input);
            //if(input =="yes"){
             //   std::ofstream os("savedGame.txt");
               // os<<*board;
                //os.close();
                //delete board;
                //break;
            //}
        }else if (input == "yes2"){
            board->getPlayerCoordinates(p2.getName(), &row, &col);
            board->printNeighbours(row, col);
            std::cout<<"Where do you want to move?"<<std::endl;
            getline(std::cin,input);
            if (input=="down") {
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::DOWN;
                std::string str = p2.getName();
                board->move(move, str);
            }else if (input=="up"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::UP;
                std::string str = p2.getName();
                board->move(move, str);
            }else if (input=="left"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::LEFT;
                std::string str = p2.getName();
                board->move(move, str);
            }else if (input=="right"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::RIGHT;
                std::string str = p2.getName();
                board->move(move, str);
            }

        }else{
            break;
        }
    }

}