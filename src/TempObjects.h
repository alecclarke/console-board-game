//
//  TempObjects.h
//  boardGameCode
//
//  Created by Alexander Clarke on 2014-11-08.
//  Copyright (c) 2014 Alexander Clarke. All rights reserved.
//

#ifndef __boardGameCode__TempObjects__
#define __boardGameCode__TempObjects__

#include <stdio.h>
#include <string>
class Player{
private:
    std::string name;
public:
    Player();
    Player(std::string nname);
    std::string getName();
};

class Tile{
};

#endif /* defined(__boardGameCode__TempObjects__) */
