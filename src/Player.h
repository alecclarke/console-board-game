//
//  Player.h
//  boardGameCode
//
//  Created by Alexander Clarke on 2014-11-13.
//  Copyright (c) 2014 Alexander Clarke. All rights reserved.
//

#ifndef __boardGameCode__Player__
#define __boardGameCode__Player__

#include <stdio.h>
#include <iostream>

class Player{
private:
    std::string name;
    int gold;
    int ruby;
    int spice;
    int fabric;
    int jewel;
    int cart;
    int food;
    int inventory;//size of current inventory<=capacity
public:
    Player();
    Player(std::string playerName);
    std::string getName();
    int getGold();
    int getRuby();
    int getSpice();
    int getFabric();
    int getJewels();
    int getCart();
    int getFood();
    int getInventory();
    void setGold(int nGold);
    void setRuby(int nRuby);
    void setSpice(int nSpice);
    void setFabric(int nFabric);
    void setJewels(int nJewels);
    void setCart(int nCart);
    void setFood(int nFood);
    void setInventory(int nInv);
    bool canAct() const;
    bool pay(Player& player);
    void eat();
    void printStats();
};

#endif /* defined(__boardGameCode__Player__) */
