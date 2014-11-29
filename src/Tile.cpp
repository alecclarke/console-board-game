//
//  Tile.cpp
//  boardGameCode
//
//  Created by Alexander Clarke on 2014-11-18.
//  Copyright (c) 2014 Alexander Clarke. All rights reserved.
//

#include "Tile.h"
#include <random>

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
            tile = new Jeweler();
            break;
        case 6:
            tile = new CartManufacturer();
            break;
        case 7:
            tile = new SmallMarket();
            break;
        case 8:
            tile = new SpiceMarket();
            break;
        case 9:
            tile = new JewelryMarket();
            break;
        case 10:
            tile = new FabricMarket();
            break;
        case 11:
            tile = new BlackMarket();
            break;
        case 12:
            tile = new Casino();
            break;
        case 13:
            tile = new GemMerchant();
            break;
        case 14:
            tile = new Palace();
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
                    std::cout << "Not enough space on cart" << std::endl;
                    return false; //not enough space on cart
                }
            }
            player.setSpice(player.getSpice()+numSacks);
            player.setGold(player.getGold()-2);
            player.setInventory(player.getInventory()+numSacks);
            player.eat();
            return true; //successful trade
        }
        std::cout << "Not enough gold" << std::endl;
        return false; //not enough gold
    }
    std::cout << "Not enough food to act" << std::endl;
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
                    std::cout << "Not enough space on cart" << std::endl;
                    return false;//not enough space on cart
                }
            }
            player.setFabric(player.getFabric()+numTissues);
            player.setGold(player.getGold()-2);
            player.setInventory(player.getInventory()+numTissues);
            player.eat();
            return true;
        }
        std::cout << "No enough gold" << std::endl;
        return false;// not enough gold
    }
    std::cout << "Not enough food to act" << std::endl;
    return false;//not enough food
}

Jeweler::Jeweler(){setType(5);}

void Jeweler::print()const{
    std::cout<<"For 2 pieces of gold, player gets 3 pieces of jewlry (less if player does not have capacity)"<<std::endl;
}

Tile* Jeweler::clone()const{
    return new Jeweler(*this);
}

bool Jeweler::action(Player &player)const{
    if(player.canAct()){
        if (player.getGold()>1) {
            int numJewles;
            if((player.getCart()-player.getInventory())>2){
                numJewles = 3;
            }else{
                numJewles = player.getCart()-player.getInventory();
                if (numJewles==0) {
                    std::cout << "Not enough spce on cart" << std::endl;
                    return false;//not enough space on cart
                }
            }
            player.setJewels(player.getJewels() + numJewles);
            player.setGold(player.getGold()-2);
            player.setInventory(player.getInventory()+numJewles);
            player.eat();
            return true;
        }
        std::cout << "Not enough gold" << std::endl;
        return false;// not enough gold
    }
    std::cout << "Not enough food to act" << std::endl;
    return false;//not enough food
}

CartManufacturer::CartManufacturer(){setType(6);}

void CartManufacturer::print()const{
    std::cout<<"Cart Manufacturer: For 7 pieces of gold, the capacity of the cart is increased by 3"<<std::endl;
}

Tile* CartManufacturer::clone()const{
    return new CartManufacturer(*this);
}

bool CartManufacturer::action(Player &player)const{
    if(player.canAct()){
        if (player.getGold()>7) {
            int cartCapacity = player.getCart();
            cartCapacity = cartCapacity + 3;
            player.setCart(cartCapacity);
            player.setGold(player.getGold()-7);
            return true;
        }
        std::cout << "Not enough gold" << std::endl;
        return false;// not enough gold
    }
    std::cout << "Not enough food" << std::endl;
    return false;//not enough food
}

SmallMarket::SmallMarket(){setType(7);}

void SmallMarket::print()const{
    std::cout<<"Small Market: A player can sell 1 roll of fabric, 1 jewel and 1 sack of spices for 8 pieces of gold"<<std::endl;
}

Tile* SmallMarket::clone()const{
    return new SmallMarket(*this);
}

bool SmallMarket::action(Player &player)const{
    if(player.canAct()){
        if (player.getFabric()>1) {
            if(player.getJewels()>1){
                if(player.getSpice()>1){
                    int gold = 8;
                    player.setGold(player.getGold() + gold);
                    player.setFabric(player.getFabric()-1);
                    player.setJewels(player.getJewels()-1);
                    player.setSpice(player.getSpice()-1);
                    player.setInventory(player.getInventory()-3);
                    return true;
                }
                std::cout << "Not enough spices" << std::endl;
                return false;//not enough spices
            }
            std::cout << "Not enough jewel" << std::endl;
            return false;//not enough jewel
        }
        std::cout << "Not enough fabric" << std::endl;
        return false;// not enough fabric
    }
    std::cout << "Not enough food" << std::endl;
    return false;//not enough food
}

SpiceMarket::SpiceMarket(){setType(8);}

void SpiceMarket::print()const{
    std::cout<<"Spice Market: A player can sell 3 sacks of spices for 6 pieces of gold"<<std::endl;
}

Tile* SpiceMarket::clone()const{
    return new SpiceMarket(*this);
}

bool SpiceMarket::action(Player &player)const{
    if(player.canAct()){
        if (player.getSpice()>0) {
            int spices = 0;
            int gold = 0;
            if(player.getSpice() == 1){
                spices = 1;
                gold = 2;
            }
            if(player.getSpice() == 2){
                spices = 2;
                gold = 4;
            }
            if(player.getSpice() >= 3){
                spices = 3;
                gold = 6;
            }
            player.setSpice(player.getSpice()-spices);
            player.setGold(player.getGold()+gold);
            player.setInventory(player.getInventory()-spices);
            return true;
        }
        std::cout << "Not enough spices" << std::endl;
        return false;// not enough spices
    }
    std::cout << "Not enough food" << std::endl;
    return false;//not enough food
}

JewelryMarket::JewelryMarket(){setType(9);}

void JewelryMarket::print()const{
    std::cout<<"Jewlry Market: A player can sell 3 pieces of jewelry for 6 pieces of gold"<<std::endl;
}

Tile* JewelryMarket::clone()const{
    return new JewelryMarket(*this);
}

bool JewelryMarket::action(Player &player)const{
    if(player.canAct()){
        if (player.getJewels()>0) {
            int jewelry = 0;
            int gold = 0;
            if(player.getJewels() == 1){
                jewelry = 1;
                gold = 2;
            }
            if(player.getJewels() == 2){
                jewelry = 2;
                gold = 4;
            }
            if(player.getJewels() >= 3){
                jewelry = 3;
                gold = 6;
            }
            player.setJewels(player.getJewels()-jewelry);
            player.setGold(player.getGold()+gold);
            player.setInventory(player.getInventory()-jewelry);
            return true;
        }
        std::cout << "Not enough jewlery" << std::endl;
        return false;// not enough jewelry
    }
    std::cout << "Not enough food" << std::endl;
    return false;//not enough food
}
FabricMarket::FabricMarket(){setType(10);}

void FabricMarket::print()const{
    std::cout<<"Fabric Market: For 2 pieces of gold, th player gets 3 rolls of fabrics tissues(less if player does not have capacity)"<<std::endl;
}

Tile* FabricMarket::clone()const{
    return new FabricMarket(*this);
}

bool FabricMarket::action(Player &player)const{
    if(player.canAct()){
        if (player.getJewels()>0) {
            int fabric = 0;
            int gold = 0;
            if(player.getFabric() == 1){
                fabric = 1;
                gold = 2;
            }
            if(player.getFabric() == 2){
                fabric = 2;
                gold = 4;
            }
            if(player.getFabric() >= 3){
                fabric = 3;
                gold = 6;
            }
            player.setFabric(player.getFabric()-fabric);
            player.setGold(player.getGold()+gold);
            player.setInventory(player.getInventory()-fabric);
            return true;
        }
        std::cout << "Not enough jewelry" << std::endl;
        return false;// not enough jewelry
    }
    std::cout << "Not enough food" << std::endl;
    return false;//not enough food
}

BlackMarket::BlackMarket(){setType(11);}

void BlackMarket::print()const{
    std::cout<<"Black Market: For 1 piece of gold, a player can get between 0 and 5 goods at random(less if player does not have capacity)"<<std::endl;
}

Tile* BlackMarket::clone()const{
    return new BlackMarket(*this);
}

bool BlackMarket::action(Player &player)const{
    if(player.canAct()){
        if (player.getGold()>1) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> randomItem(1,3);
            std::uniform_int_distribution<> randomQuatity(0,5);
            int quatityAdded;
            if(randomQuatity(gen)<(player.getCart()-player.getInventory())){
                quatityAdded = (player.getCart()-player.getInventory()); // not enough room on cart
            }else{
                quatityAdded = randomQuatity(gen);
            }
            for(int i = 0; i < quatityAdded; i++){
                switch (randomItem(gen)) {
                    {case 1:
                        int totalSpices = randomQuatity(gen);
                        int spicesGained;
                        if((player.getCart()-player.getInventory())>totalSpices){
                            spicesGained = totalSpices;
                        }else{
                            spicesGained = player.getCart()-player.getInventory();
                            if (spicesGained==0) {
                                std::cout << "Not enough space on cart" << std::endl;
                                return false;//not enough space on cart
                            }
                        }
                        player.setSpice(player.getSpice()+spicesGained);
                        player.setGold(player.getGold()-1);
                        player.setInventory(player.getInventory()+spicesGained);
                        break;
                    }
                    {case 2:
                        int totalFabrics = randomQuatity(gen);
                        int fabricesGained;
                        if((player.getCart()-player.getInventory())>totalFabrics){
                            fabricesGained = totalFabrics;
                        }else{
                            fabricesGained = player.getCart()-player.getInventory();
                            if (fabricesGained==0) {
                                std::cout << "Not enough space on cart" << std::endl;
                                return false;//not enough space on cart
                            }
                        }
                        player.setFabric(player.getFabric()+fabricesGained);
                        player.setGold(player.getGold()-1);
                        player.setInventory(player.getInventory()+fabricesGained);
                        break;
                    }
                    {case 3:
                        int totalJewelry = randomQuatity(gen);
                        int jewelryGained;
                        if((player.getCart()-player.getInventory())>totalJewelry){
                            jewelryGained = totalJewelry;
                        }else{
                            jewelryGained = player.getCart()-player.getInventory();
                            if (jewelryGained==0) {
                                std::cout << "Not enough space on cart" << std::endl;
                                return false;//not enough space on cart
                            }
                        }
                        player.setJewels(player.getJewels()+jewelryGained);
                        player.setGold(player.getGold()-1);
                        player.setInventory(player.getInventory()+jewelryGained);
                        break;
                    }
                    default:
                        break;
                }
            }
            return true;
        }
        std::cout << "Not enough gold" << std::endl;
        return false;// not enough gold
    }
    std::cout << "Not enough food" << std::endl;
    return false;//not enough food
}

Casino::Casino(){setType(12);}

void Casino::print()const{
    std::cout<<"Casino: For 1 piece of gold, the player has 2 in 5 chance to loose, ie, win 0 pieces of gold, a 3 out of 10 chance to get 2 pieces of gold, a 2 out out 10 chance to get 3 pieces of gold and a 1 in 10 chance to win 10 pieces of gold"<<std::endl;
}

Tile* Casino::clone()const{
    return new Casino(*this);
}

bool Casino::action(Player &player)const{
    if(player.canAct()){
        if (player.getGold()>1) {
            int goldEarned = 0;
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> roll(1,10);
            if(roll(gen) == 1 || roll(gen) == 2 || roll(gen) == 3 || roll(gen) == 4){
                goldEarned = 0;
            }
            if(roll(gen) == 5 || roll(gen) == 6 || roll(gen) == 7){
                goldEarned = 2;
            }
            if(roll(gen) == 8 || roll(gen) == 9){
                goldEarned = 3;
            }
            if(roll(gen) == 10){
                goldEarned = 10;
            }
            player.setGold(player.getGold()-1+goldEarned);
            player.setInventory(player.getInventory());
            return true;
        }
        std::cout << "Not enough gold" << std::endl;
        return false;// not enough gold
    }
    std::cout << "Not enough food" << std::endl;
    return false;//not enough food
}

GemMerchant::GemMerchant(){setType(13);}

void GemMerchant::print()const{
    std::cout<<"Gem Merchnat: A player can buy a ruby. THe first ruby costs 12 gold coins, the second ruby to be purchased costs 13, the third 14, etc."<<std::endl;
}

Tile* GemMerchant::clone()const{
    return new GemMerchant(*this);
}

bool GemMerchant::action(Player &player)const{
    if(player.canAct()){
        int cost = player.getGemBuyTime() + 12;
        if (player.getGold()>cost) {
            if(player.getCart()-player.getInventory()>1){
                int numRuby = 1;
                player.setRuby(player.getRuby()+numRuby);
                player.setGemBuyTime(player.getGemBuyTime()+1);
                player.setGold(player.getGold()-cost);
                player.setInventory(player.getInventory()+numRuby);
                return true;
            }
            std::cout << "Not enough space on cart" << std::endl;
            return false;//not enough room in cart
        }
        std::cout << "Not enough food" << std::endl;
        return false;// not enough gold
    }
    std::cout << "Not enough food" << std::endl;
    return false;//not enough food
}

Palace::Palace(){setType(14);}

void Palace::print()const{
    std::cout<<"Palace: A player can get a ruby in exchange for 5 rolls of fabrics, 5 pieces of jewelry and 5 sacks of spices"<<std::endl;
}

Tile* Palace::clone()const{
    return new Palace(*this);
}

bool Palace::action(Player &player)const{
    if(player.canAct()){
        if (player.getFabric()>5) {
            if(player.getJewels()>5){
                if(player.getSpice()>5){
                    if((player.getCart()-(player.getInventory()-15))>=1){
                        int numRuby = 1;
                        player.setRuby(player.getRuby()+numRuby);
                        player.setFabric(player.getFabric()-5);
                        player.setJewels(player.getJewels()-5);
                        player.setSpice(player.getSpice()-5);
                        player.setInventory(player.getInventory()+numRuby-15);
                        return true;
                    }
                    std::cout << "Not enough space on cart" << std::endl;
                    return false;//not enough room in cart
                }
                std::cout << "Not enough spices" << std::endl;
                return false;//not enough spices
            }
            std::cout << "Not enough jewelry" << std::endl;
            return false;//not enough jewelry
        }
        std::cout << "Not enough fabric" << std::endl;
        return false;// not enough fabric
    }
    std::cout << "Not enough food" << std::endl;
    return false;//not enough food
}


















