#ifndef INITBALL_H
#define INITBALL_H
#include "../init.h"

float BALL_SPEED  = 20;
const int BALL_HEIGHT = 16;
const int BALL_WIDTH  = 16;

void init_ball(Ball *ball, Mouse *mouse, Vaus *vaus);
void CalculateDirection(Ball *ball, float newdirx, float newdiry);
#endif 