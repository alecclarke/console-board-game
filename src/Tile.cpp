//
//  Tile.cpp
//  boardGameCode
//
//  Created by Alexander Clarke on 2014-11-18.
//  Copyright (c) 2014 Alexander Clarke. All rights reserved.
//

#include "Tile.h"

Tile* Tile::setTileType(Tile *tile){
    switch (tile->type) {
        case 1:
            tile = new Tile();
            break;
        case 2:
            tile = new Restaurant();
            break;
        case 3:
            tile = new SpiceMerchant();
            break;
        case 4:
            tile = new FabricManufacturer();
            break;
        case 5:
            tile = new Jewler();
            break;
    }
    return tile;
}

Tile* Tile::clone()const{
    return new Tile(*this);
}

Tile::Tile(){type = 1;}

bool Tile::action(Player &player)const{
    return true;
}

void Tile::print()const{
    std::cout<<"Desert: No action is possible on this tile."<<std::endl;
}

void Tile::setType(int i){type = i;}

int Tile::getType(){return type;}

std::ostream& operator << (std::ostream& os, const Tile& tile){
    os<<tile.type<<" ";
    return os;
};

std::istream& operator >> (std::istream& is, Tile& tile){
    is>>tile.type;
    return is;
}

Restaurant::Restaurant(){setType(2);}

bool Restaurant::action(Player &player)const{
    if (player.canAct()) {
        player.setFood(10);
        return true;
    }
    return false;
}

Tile * Restaurant::clone()const{
    return new Restaurant(*this);
}

void Restaurant::print()const{
    std::cout<<"Restaurant: Replenish player's food."<<std::endl;
}

SpiceMerchant::SpiceMerchant(){setType(3);}

bool SpiceMerchant::action(Player &player)const{
    if (player.canAct()) {
        if (player.getGold()>1) {
            int numSacks;
            if ((player.getCart()-player.getInventory())>2) {
                numSacks=3;
            }else{
                numSacks = player.getCart() - player.getInventory();
                if (numSacks==0) {
                    return false; //not enough space on cart
                }
            }
            player.setSpice(player.getSpice()+numSacks);
            player.setGold(player.getGold()-2);
            player.setInventory(player.getInventory()+numSacks);
            player.eat();
            return true; //successful trade
        }
        return false; //not enough gold
    }
    return false; //not enough food to act
}

Tile* SpiceMerchant::clone()const{
    return new SpiceMerchant(*this);
}

void SpiceMerchant::print()const{
    std::cout<<"Spice Merchant: For 2 pieces of gold, purchase 3 sacks of spices (less if player does not have capacity)."<<std::endl;
}

FabricManufacturer::FabricManufacturer(){setType(4);}

void FabricManufacturer::print()const{
 std::cout<<"For 2 pieces of gold, player gets 3 rolls of fabrics tissues (less if player does not have capacity)"<<std::endl;
}

Tile* FabricManufacturer::clone()const{
    return new FabricManufacturer(*this);
}

bool FabricManufacturer::action(Player &player)const{
    if(player.canAct()){
        if (player.getGold()>1) {
            int numTissues;
            if((player.getCart()-player.getInventory())>2){
                numTissues = 3;
            }else{
                numTissues = player.getCart()-player.getInventory();
                if (numTissues==0) {
                    return false;//not enough space on cart
                }
            }
            player.setFabric(player.getFabric()+numTissues);
            player.setGold(player.getGold()-2);
            player.setInventory(player.getInventory()+numTissues);
            player.eat();
            return true;
        }
        return false;// not enough gold
    }
    return false;//not enough food
}

Jewler::Jewler(){setType(5);}

void Jewler::print()const{
    std::cout<<"For 2 pieces of gold, player gets 3 pieces of jewlry (less if player does not have capacity)"<<std::endl;
}

Tile* Jewler::clone()const{
    return new Jewler(*this);
}

bool Jewler::action(Player &player)const{
    if(player.canAct()){
        if (player.getGold()>1) {
            int numJewles;
            if((player.getCart()-player.getInventory())>2){
                numJewles = 3;
            }else{
                numJewles = player.getCart()-player.getInventory();
                if (numJewles==0) {
                    return false;//not enough space on cart
                }
            }
            player.setJewels(player.getJewels() + numJewles);
            player.setGold(player.getGold()-2);
            player.setInventory(player.getInventory()+numJewles);
            player.eat();
            return true;
        }
        return false;// not enough gold
    }
    return false;//not enough food
}


















