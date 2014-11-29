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
    int gemBuyTime;
public:
    Player();
    Player(std::string playerName);
    std::string getName();
    int getGold()const;
    int getRuby()const;
    int getSpice()const;
    int getFabric()const;
    int getJewels()const;
    int getCart()const;
    int getFood()const;
    int getInventory()const;
    int getGemBuyTime()const;
    void setGold(int nGold);
    void setRuby(int nRuby);
    void setSpice(int nSpice);
    void setFabric(int nFabric);
    void setJewels(int nJewels);
    void setCart(int nCart);
    void setFood(int nFood);
    void setInventory(int nInv);
    void setGemBuyTime(int nGbt);
    bool canAct() const;
    bool pay(Player& player);
    void eat();
    void printStats();
    inline friend std::ostream& operator << (std::ostream& os, const Player& player){
        os<<player.name<<" ";
        os<<player.gold<<" ";
        os<<player.ruby<<" ";
        os<<player.spice<<" ";
        os<<player.fabric<<" ";
        os<<player.jewel<<" ";
        os<<player.cart<<" ";
        os<<player.food<<" ";
        os<<player.inventory<<" ";
        os<<player.gemBuyTime<<" ";
        return os;
    };
    inline friend std::istream& operator >> (std::istream& is, Player& player){
        is>>player.name;
        is>>player.gold;
        is>>player.ruby;
        is>>player.spice;
        is>>player.fabric;
        is>>player.jewel;
        is>>player.cart;
        is>>player.food;
        is>>player.inventory;
        is>>player.gemBuyTime;
        return is;
    };
};

#endif /* defined(__boardGameCode__Player__) */
