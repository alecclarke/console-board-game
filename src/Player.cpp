//
//  Player.cpp
//  boardGameCode
//
//  Created by Alexander Clarke on 2014-11-13.
//  Copyright (c) 2014 Alexander Clarke. All rights reserved.
//

#include "Player.h"

Player::Player(std::string playerName){
    name = playerName;
    gold = 5;
    ruby = 0;
    spice = 1;
    fabric = 1;
    jewel = 1;
    food = 10;
    cart = 9;
    inventory = 3;
}

Player::Player(){
}

std::string Player::getName(){
    return name;
}

bool Player::canAct()const{
    if (food>0) {
        return true;
    }else{
        return false;
    }
}

void Player::eat(){
    if (food>0) {
        food--;
    }
}

bool Player::pay(Player &player){
    if(this->getGold()>0){
        player.setGold(player.getGold()+1);
        this->setGold(this->getGold()-1);
        return true;
    }
    return false;
}

void Player::setCart(int nCart){
    cart = nCart;
}

void Player::setFabric(int nFabric){
    fabric = nFabric;
}

void Player::setFood(int nFood){
    food = nFood;
}

void Player::setGold(int nGold){
    gold = nGold;
}

void Player::setJewels(int nJewels){
    jewel = nJewels;
}

void Player::setRuby(int nRuby){
    ruby = nRuby;
}

void Player::setSpice(int nSpice){
    spice = nSpice;
}

void Player::setInventory(int nInv){
    inventory = nInv;
}

int Player::getCart()const{
    return cart;
}

int Player::getFabric()const{
    return fabric;
}

int Player::getFood()const{
    return food;
}

int Player::getGold()const{
    return gold;
}

int Player::getJewels()const{
    return jewel;
}

int Player::getRuby()const{
    return ruby;
}

int Player::getSpice()const{
    return spice;
}

int Player::getInventory()const{
    return inventory;
}

void Player::printStats(){
    std::cout<<name<<" Stats:"<<std::endl;
    std::cout<<"--Inventory Size = "<<inventory<<std::endl;
    std::cout<<"--Cart = "<<cart<<std::endl;
    std::cout<<"--Gold = "<<gold<<std::endl;
    std::cout<<"--Ruby = "<<ruby<<std::endl;
    std::cout<<"--Food = "<<food<<std::endl;
    std::cout<<"--Jewel = "<<jewel<<std::endl;
    std::cout<<"--Fabric = "<<fabric<<std::endl;
    std::cout<<"--Spice = "<<spice<<std::endl;
}





