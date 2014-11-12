//
//  TempObjects.cpp
//  boardGameCode
//
//  Created by Alexander Clarke on 2014-11-08.
//  Copyright (c) 2014 Alexander Clarke. All rights reserved.
//

#include "TempObjects.h"
Player::Player(std::string nname){
    name = nname;
}
Player::Player(){

}
std::string Player::getName(){
    return name;
}