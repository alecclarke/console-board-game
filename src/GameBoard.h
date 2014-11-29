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
#include <deque>
#include <iostream>
#include <random>

template <class T,class J>
class GameBoard{
public:
    enum Move {UP,DOWN,LEFT,RIGHT};
    struct square{
        std::deque<J> currentPlayers;
        T * tile;
        int numPlayers;
        friend std::ostream& operator << (std::ostream& os, const square& sq){
            os<<*sq.tile;
            os<<sq.numPlayers<<" ";
            for(int i = 0;i<sq.currentPlayers.size(); i++){
                os<<sq.currentPlayers[i];
            }
            return os;
        };
        friend std::istream& operator >> (std::istream& is,  square& sq){
            T * tile = new T();
            is>>*tile;
            sq.tile = tile->setTileType(tile);
            is>>sq.numPlayers;
            for(int i = 0; i<sq.numPlayers; i++){
                J player = *new J();
                is>>player;
                sq.currentPlayers.push_back(player);
            }
            return is;
        };
    };
    struct playerRef{
        int row;
        int col;
        J player;
        friend std::ostream& operator << (std::ostream& os, const playerRef& pr){
            os<<pr.row<<" ";
            os<<pr.col<<" ";
            os<<pr.player;
            return os;
        }
        friend std::istream& operator >> (std::istream& is,  playerRef& pr){
            is>>pr.row;
            is>>pr.col;
            is>>pr.player;
            return is;
        }
    };
    GameBoard(int r, int c, int n);
    GameBoard();
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
    void updatePlayer(J& player);
    std::vector<playerRef> getPlayerList();
    int getNumPlayers();
    
private:
    void moveUpdate(playerRef& pRef, enum Move move);
    std::vector<std::vector<square>> grid;
    std::vector<playerRef> playerList;
    int rows;
    int columns;
    int numPlayers;
};

template <class T, class J>
GameBoard<T,J>::GameBoard(){}

template <class T, class J>
GameBoard<T,J>::GameBoard(int r, int c, int n){
    rows = r;
    columns = c;
    numPlayers = n;
    grid.assign(r, std::vector<square>(c));
}

template <class T, class J>
int GameBoard<T,J>::getNumPlayers(){
    return numPlayers;
}

template <class T, class J>
std::vector<typename GameBoard<T, J>::playerRef> GameBoard<T,J>::getPlayerList(){
    return playerList;
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
    temp.player = player;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> tempRow(0,rows-1);
    std::uniform_int_distribution<> tempCol(0,columns-1);
    temp.row = tempRow(gen);
    temp.col = tempCol(gen);
    playerList.push_back(temp);
    grid.at(temp.row).at(temp.col).currentPlayers.push_back(player);
    grid.at(temp.row).at(temp.col).numPlayers++;
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
                grid.at(pRef.row).at(pRef.col).currentPlayers.pop_front();
                grid.at(pRef.row).at(pRef.col).numPlayers--;
                grid.at(pRef.row-1).at(pRef.col).currentPlayers.push_back(pRef.player);
                grid.at(pRef.row-1).at(pRef.col).numPlayers++;
                pRef.row--;
                pRef.player.eat();
            } catch (const std::out_of_range& oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
            }
            break;
        case DOWN:
            try {
                grid.at(pRef.row).at(pRef.col).currentPlayers.pop_front();
                grid.at(pRef.row).at(pRef.col).numPlayers--;
                grid.at(pRef.row+1).at(pRef.col).currentPlayers.push_back(pRef.player);
                grid.at(pRef.row+1).at(pRef.col).numPlayers++;
                pRef.row++;
                pRef.player.eat();
            } catch (const std::out_of_range& oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
            }
            break;
        case LEFT:
            try {
                grid.at(pRef.row).at(pRef.col).currentPlayers.pop_front();
                grid.at(pRef.row).at(pRef.col).numPlayers--;
                grid.at(pRef.row).at(pRef.col-1).currentPlayers.push_back(pRef.player);
                grid.at(pRef.row).at(pRef.col-1).numPlayers++;
                pRef.col--;
                pRef.player.eat();
            } catch (const std::out_of_range& oor) {
                std::cerr << "Out of Range error: " << oor.what() << '\n';
            }
            break;
        case RIGHT:
            try {
                grid.at(pRef.row).at(pRef.col).currentPlayers.pop_front();
                grid.at(pRef.row).at(pRef.col).numPlayers--;
                grid.at(pRef.row).at(pRef.col+1).currentPlayers.push_back(pRef.player);
                grid.at(pRef.row).at(pRef.col+1).numPlayers++;
                pRef.col++;
                pRef.player.eat();
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
        is>>game.rows;
        is>>game.columns;
        is>>game.numPlayers;
        game = *new GameBoard<X, Y>(game.rows,game.columns,game.numPlayers);
        for (int i = 0; i<game.rows; i++) {
            for (int j = 0; j<game.columns; j++) {
                is>>game.grid[i][j];
            }
        }
        std::vector<typename GameBoard<X,Y>::playerRef> list(game.numPlayers);
        game.playerList = list;
    for (int i = 0; i<game.numPlayers; i++) {
            is>>game.playerList[i];
        }
    return is;
}

template <class X, class Y>
std::ostream& operator << (std::ostream& os, const GameBoard<X,Y>& game){
    os<<game.rows<<" ";
    os<<game.columns<<" ";
    os<<game.numPlayers<<" ";
    for (int i = 0; i<game.rows; i++) {
        for (int j = 0; j<game.columns; j++) {
            os<<game.grid[i][j];
        }
    }
    for (int i = 0; i<game.numPlayers; i++) {
        os<<game.playerList[i];
    }
    return os;
}

template <class T, class J>
bool GameBoard<T,J>::payPlayers(J& player, int row, int col){
    bool check = true;
    if (player.getGold()>=grid[row][col].numPlayers) {
        int i = 0;
        while ((i<grid[row][col].numPlayers)&&(check)) {
            if (player.getName()!=grid[row][col].currentPlayers[i].getName()) {
                J& p2 = grid[row][col].currentPlayers[i];
                check = player.pay(p2);
                this->updatePlayer(p2);
            }
            i++;
        }
    }
    return check;
}

template <class T, class J>
void GameBoard<T,J>::updatePlayer(J& player){
    int i = 0;
    bool check = false;
    while((i<playerList.size())&&(!check)) {
        if(playerList[i].player.getName() == player.getName()){
            playerList[i].player = player;
            check = true;
        }
        if (!check) {
            i++;
        }
    }
}




#endif /* defined(__boardGameCode__GameBoard__) */
