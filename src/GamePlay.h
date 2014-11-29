//
//  GamePlay.h
//  boardGameCode
//
//  Created by Alexander Clarke on 2014-11-28.
//  Copyright (c) 2014 Alexander Clarke. All rights reserved.
//

#ifndef boardGameCode_GamePlay_h
#define boardGameCode_GamePlay_h
#include "Player.h"
#include "GameBoard.h"

void play();
void getWinPlayer(Player player, GameBoard<class Tile, class Player> * board);

#endif
