#include "ball.h"
//extern SDL_Renderer *renderer;
void draw_ball(Ball *ball){
	ball->posX += ball->dirX * ball->time;
	ball->posY += ball->dirY * ball->time;
    
	blit(ball->ball_texture, (int)ball->posX, (int)ball->posY, 1, ball->width, ball->height);
}

void CalculateDirection(Ball *ball, float newdirx, float newdiry){
    double length = sqrt(newdirx * newdirx + newdiry * newdiry);
    ball->dirX = ball->speed * (newdirx / (float)length);
    ball->dirY = ball->speed * (newdiry / (float)length);
}
