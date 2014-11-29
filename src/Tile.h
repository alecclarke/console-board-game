//
//  Tile.h
//  boardGameCode
//
//  Created by Alexander Clarke on 2014-11-18.
//  Copyright (c) 2014 Alexander Clarke. All rights reserved.
//

#ifndef __boardGameCode__Tile__
#define __boardGameCode__Tile__

#include <stdio.h>
#include "Player.h"

class Tile{
private:
    int type; //used to specify type of tile, int type because of use in switch statement
public:
    Tile();
    bool operator==(const Tile &t);
    virtual bool action(Player& player)const;
    virtual Tile* clone()const;
    virtual void print()const;
    friend std::ostream& operator << (std::ostream& os, const Tile& tile);
    friend std::istream& operator >> (std::istream& is, Tile& tile);
    void setType(int i);
    int getType();
    Tile * setTileType(Tile * tile);
};

class Restaurant: public Tile{
public:
    Restaurant();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class SpiceMerchant: public Tile{
public:
    SpiceMerchant();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class FabricManufacturer: public Tile{
public:
    FabricManufacturer();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class Jeweler: public Tile{
public:
    Jeweler();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class CartManufacturer: public Tile{
public:
    CartManufacturer();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class SmallMarket: public Tile{
public:
    SmallMarket();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class SpiceMarket: public Tile{
public:
    SpiceMarket();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class JewelryMarket: public Tile{
public:
    JewelryMarket();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class FabricMarket: public Tile{
public:
    FabricMarket();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class BlackMarket: public Tile{
public:
    BlackMarket();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class Casino: public Tile{
public:
    Casino();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class GemMerchant: public Tile{
public:
    GemMerchant();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};

class Palace: public Tile{
public:
    Palace();
    bool action(Player& player)const;
    Tile* clone()const;
    void print()const;
};




#endif /* defined(__boardGameCode__Tile__) */
