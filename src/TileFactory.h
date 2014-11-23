//
//  TileFactory.h
//  boardGameCode
//
//  Created by Alexander Clarke on 2014-11-18.
//  Copyright (c) 2014 Alexander Clarke. All rights reserved.
//

#ifndef __boardGameCode__TileFactory__
#define __boardGameCode__TileFactory__

#include <stdio.h>
#include <deque>
#include "Tile.h"

class TileFactory{
private:
    std::deque<Tile*> tiles;
    TileFactory(int _nTiles); //restrict constructor
    TileFactory(TileFactory const&); //restrict copy constructor
    TileFactory& operator=(TileFactory const&); //restrict copy constructor
public:
    static TileFactory *get(int _nTiles) {
        static TileFactory tf(_nTiles);
        return &tf;
    }
    Tile* next();
};
#endif /* defined(__boardGameCode__TileFactory__) */
