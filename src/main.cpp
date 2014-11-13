//
//  main.cpp
//  boardGameCode
//
//  Created by Alexander Clarke on 2014-11-07.
//  Copyright (c) 2014 Alexander Clarke. All rights reserved.
//

#include <iostream>
#include "GameBoard.h"
#include "TempObjects.h"
#include "Player.h"

int main() {
    GameBoard<Tile, Player> * board = new GameBoard<Tile, Player>(10,10,2);
    for (int i = 0; i<10; i++) {
        for (int j = 0; j<10; j++) {
            Tile * t = new Tile();
            board->add(*t, i, j);
            delete t;
        }
    }
    Player * p1 = new Player("Player1");
    Player * p2 = new Player("Player2");
    board->setPlayer(*p1);
    board->setPlayer(*p2);
    int row,col;
    while(true){
        std::cout<<"Show Surrounding Squares?"<<std::endl;
        std::string input;
        getline(std::cin,input);
        if (input == "yes1") {
            board->getPlayerCoordinates(p1->getName(), &row, &col);
            board->printNeighbours(row, col);
            std::cout<<"Where do you want to move?"<<std::endl;
            getline(std::cin,input);
            if (input=="down") {
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::DOWN;
                std::string str = p1->getName();
                board->move(move, str);
            }else if (input=="up"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::UP;
                std::string str = p1->getName();
                board->move(move, str);
            }else if (input=="left"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::LEFT;
                std::string str = p1->getName();
                board->move(move, str);
            }else if (input=="right"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::RIGHT;
                std::string str = p1->getName();
                board->move(move, str);
            }
        }else if (input == "yes2"){
            board->getPlayerCoordinates(p2->getName(), &row, &col);
            board->printNeighbours(row, col);
            std::cout<<"Where do you want to move?"<<std::endl;
            getline(std::cin,input);
            if (input=="down") {
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::DOWN;
                std::string str = p2->getName();
                board->move(move, str);
            }else if (input=="up"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::UP;
                std::string str = p2->getName();
                board->move(move, str);
            }else if (input=="left"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::LEFT;
                std::string str = p2->getName();
                board->move(move, str);
            }else if (input=="right"){
                GameBoard<Tile, Player>::Move move = GameBoard<Tile, Player>::Move::RIGHT;
                std::string str = p2->getName();
                board->move(move, str);
            }

        }else{
            break;
        }
    }

}