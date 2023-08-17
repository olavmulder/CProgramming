#include "ball.h"

void init_ball(Ball *ball, Mouse *mouse, Vaus *vaus){
    ball->ball_texture = load_texture("init/images/ball.png");
	ball->posX = (float)mouse->x+(float)vaus->width/2;
	ball->posY = (float)vaus->posY-(float)BALL_HEIGHT;
	ball->speed = BALL_SPEED;
	ball->dirX = 1;
	ball->dirY = -1;
	ball->height = BALL_HEIGHT;
	ball->width =  BALL_WIDTH;
	ball->time = 0.16f;
	CalculateDirection(ball, ball->dirX, ball->dirY);
}