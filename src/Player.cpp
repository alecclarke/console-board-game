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

bool Player::pay(Player &player){
    //need to implement
    return true;
}

void Player::eat(){
    if (food>0) {
        food--;
    }
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

int Player::getCart(){
    return cart;
}

int Player::getFabric(){
    return fabric;
}

int Player::getFood(){
    return food;
}

int Player::getGold(){
    return gold;
}

int Player::getJewels(){
    return jewel;
}

int Player::getRuby(){
    return ruby;
}

int Player::getSpice(){
    return spice;
}





