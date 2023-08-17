#ifndef UPDATECOLLISION_H
#define UPDATECOLLISION_H
#include "../update.h"

extern  int BLOCK_HEIGHT; 
extern  int BLOCK_WIDTH ;
extern  int ROW ;
extern  int COL ;
extern  int total_powerups;
int score = 3;


void detection(Ball *ball, Block *block, Vaus *vaus);
static void VausCollision(Ball *ball, Vaus *vaus);
static void ResponseBall(Ball *ball, int side);

void CalculateDirection(Ball *ball, float newdirx, float newdiry);
void powerup(Vaus *vaus, Ball *ball, int pownr);
void check_next_level(Ball *ball, Vaus *vaus, Block *block);
#endif