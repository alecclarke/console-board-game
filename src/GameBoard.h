//
//  GameBoard.h
//  boardGameCode
//
//  Created by Alexander Clarke on 2014-11-07.
//  Copyright (c) 2014 Alexander Clarke. All rights reserved.
//

#ifndef __boardGameCode__GameBoard__
#define __boardGameCode__GameBoard__

#include <stdio.h>
#include <vector>
#include <iostream>

template <class T,class J>
class GameBoard{
public:
    enum Move {UP,DOWN,LEFT,RIGHT};
    struct square{
        std::vector<J> currentPlayers;
        T * tile;
    };
    struct playerRef{
        int row;
        int col;
        J player;
    };
    GameBoard(int r, int c, int n);
    void add(const T& tile,int row, int col);
    const T & getTile(int row, int col)const;
    void getCoordinates(const T &tile, int * row, int * col) const;
    void setPlayer(J player);
    J getPlayer(const std::string & playerName) const;
    std::vector<J> getPlayers(const T& tile) const;
    const T& move(enum Move move, const std::string & playerName);
    void printNeighbours(int row, int col);
    void getPlayerCoordinates(const std::string& playerName, int * row, int * col);
    template<class X,class Y> friend std::istream& operator >> (std::istream& is, GameBoard<X,Y> & game);
    template<class X,class Y> friend std::ostream& operator << (std::ostream& os, const GameBoard<X,Y> & game);
    bool payPlayers(J& player, int row, int col);
private:
    void moveUpdate(playerRef& pRef, enum Move move);
    std::vector<std::vector<square>> grid;
    std::vector<playerRef> playerList;
    int rows;
    int columns;
    int numPlayers;
};

template <class T, class J>
GameBoard<T,J>::GameBoard(int r, int c, int n){
    rows = r;
    columns = c;
    numPlayers = n;
    grid.assign(r, std::vector<square>(c));
}

template <class T,class J>
void GameBoard<T,J>::add(const T& tile,int row, int col){
    try{
        grid[row][col].tile = tile.clone();
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
}

template <class T, class J>
const T & GameBoard<T,J>::getTile(int row, int col)const{
    try{
        return *grid.at(row).at(col).tile;
    }
    catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
    return *grid.at(row).at(col).tile;
}

template <class T, class J>
void GameBoard<T,J>::getCoordinates(const T& tile, int *row, int *col)const{
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<columns; j++) {
            if (&grid[i][j].tile == &tile) {
                *row = i;
                *col = j;
            }
        }
    }
}

template <class T, class J>
void GameBoard<T,J>::setPlayer(J player){
    playerRef temp;
    temp.row = 0;
    temp.col = 0;
    temp.player = player;
    playerList.push_back(temp);
    grid[0][0].currentPlayers.push_back(player);
}

template <class T, class J>
J GameBoard<T,J>::getPlayer(const std::string& playerName)const{
    for (int i = 0; i<playerList.size(); i++) {
        if (playerList[i].player.getName() == playerName) {
            return playerList[i].player;
        }
    }
    return NULL;
}

template <class T, class J>
std::vector<J> GameBoard<T,J>::getPlayers(const T& tile)const{
    for (int i = 0; i<rows; i++) {
        for (int j = 0; j<columns; j++) {
            if (&grid[i][j].tile == &tile) {
                return grid[i][j].currentPlayers;
            }
        }
    }
    
}

template <class T, class J>
const T& GameBoard<T,J>::move(enum Move move, const std::string& playerName){
    playerRef tempPlayer;
    int i = 0;
    bool check = false;
    while((i<playerList.size())&&(!check)) {
        if(playerList[i].player.getName() == playerName){
            tempPlayer = playerList[i];
            check = true;
        }
        if (!check) {
            i++;
        }
    }
    GameBoard<T,J>::moveUpdate(tempPlayer, move);
    playerList[i]=tempPlayer;
    return *grid[tempPlayer.row][tempPlayer.col].tile;
}

template <class T, class J>
void GameBoard<T,J>::printNeighbours(int row, int col){
    if(row<rows-1){
        std::cout<<"Down"<<std::endl;
        grid[row+1][col].tile->clone()->print();
    }
    if(row>0){
        std::cout<<"Up"<<std::endl;
        grid[row-1][col].tile->clone()->print();
    }
    if(col<columns-1){
        std::cout<<"Right"<<std::endl;
        grid[row][col+1].tile->clone()->print();
    }
    if(col>0){
        std::cout<<"Left"<<std::endl;
         grid[row][col-1].tile->clone()->print();
    }
}

template <class T, class J>
void GameBoard<T,J>::getPlayerCoordinates(const std::string& playerName, int *row, int *col){
    for (int i = 0; i<playerList.size(); i++) {
        if (playerList[i].player.getName() == playerName) {
            *row =  playerList[i].row;
            *col =  playerList[i].col;
        }
    }
}

template <class T, class J>
void GameBoard<T,J>::moveUpdate(GameBoard::playerRef& pRef, enum Move move){
    switch (move) {
        case UP:
            try {
                grid.at(pRef.row-1).at(pRef.col).currentPlayers.push_back(pRef.player);
                pRef.row--;
            } catch (const std::out_of_range& oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
            }
            break;
        case DOWN:
            try {
                grid.at(pRef.row++).at(pRef.col).currentPlayers.push_back(pRef.player);
                pRef.row++;
            } catch (const std::out_of_range& oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
            }
            break;
        case LEFT:
            try {
                grid.at(pRef.row).at(pRef.col-1).currentPlayers.push_back(pRef.player);
                pRef.col--;
            } catch (const std::out_of_range& oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
            }
            break;
        case RIGHT:
            try {
                grid.at(pRef.row).at(pRef.col+1).currentPlayers.push_back(pRef.player);
                pRef.col++;
            } catch (const std::out_of_range& oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
            }
            break;
        default:
            break;
    }
}

template <class X, class Y>
std::istream& operator >> (std::istream& is, GameBoard<X,Y>& game){
    is>>game;
    return is;
}

template <class X, class Y>
std::ostream& operator << (std::ostream& os, const GameBoard<X,Y>& game){
    os<< game;
    return os;
}

template <class T, class J>
bool GameBoard<T,J>::payPlayers(J& player, int row, int col){
    bool check = false;
    if (player.getGold()>=grid[row][col].currentPlayers.size()) {
        for (int i = 0; i<grid[row][col].currentPlayers.size(); i++) {
            if (grid[row][col].currentPlayers[i].getName() != player.getName()) {
                check = player.pay(grid[row][col].currentPlayers[i]);
            }
        }
    }
    return check;
}





#endif /* defined(__boardGameCode__GameBoard__) */
