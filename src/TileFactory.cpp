//
//  TileFactory.cpp
//  boardGameCode
//
//  Created by Alexander Clarke on 2014-11-18.
//  Copyright (c) 2014 Alexander Clarke. All rights reserved.
//

#include "TileFactory.h"
#include <stdlib.h>
#include <algorithm>

TileFactory::TileFactory(int _nTiles){
    int ratio = _nTiles/14;
    for (int i = 0; i<ratio; i++) {
        tiles.push_back(new Jewler());
        tiles.push_back(new FabricManufacturer());
        tiles.push_back(new SpiceMerchant());
        tiles.push_back(new Restaurant());
    }
    for (int j = 0; j<(_nTiles-(ratio*2)); j++) {
        tiles.push_back(new Tile());
    }
    std::random_shuffle(tiles.rbegin(), tiles.rend()); //shuffle tiles
}

Tile* TileFactory::next(){
    Tile * tile = tiles.front();
    tiles.pop_front();
    return tile;
}

