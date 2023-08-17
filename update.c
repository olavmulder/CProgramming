#include "update.h"
int current_blocks;
int current_level = 1;
int max_level = 3;
void update(Ball *ball, Block *block, Vaus *vaus)
{
    
    draw_vaus(vaus);
	detection(ball, block, vaus);
    draw_field(block);
	draw_ball(ball);

}

void blit(SDL_Texture *txtr, int x, int y, int center, int width, int height)
{
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = width;
	dest.h = height;
	SDL_QueryTexture(txtr, NULL, NULL, &dest.w, &dest.h);
	if (center)
	{
		dest.x -= dest.w / 2;
		dest.y -= dest.h / 2;
	}
		SDL_RenderCopy(renderer, txtr, NULL, &dest);
}
void check_next_level(Ball *ball, Vaus *vaus, Block *block){
	if(current_blocks <= 0 ){
		current_blocks = total_blocks;
	}
	current_blocks -=1;				
	if(current_blocks == 0){
		current_level +=1;
		if(current_level <= max_level){
			ball->dirX = -1;
			ball->dirY = -1;
			
			ball->posY = (float)vaus->posY - (float)ball->height/2;
			ball->posX = (float)vaus->posX;
			generate_field(block, current_level);
			SDL_RenderPresent(renderer);
			SDL_Delay(1000);
			CalculateDirection(ball, ball->dirX, ball->dirY);
			current_blocks = total_blocks;
			printf("Level %d starts!\n",current_level);
		}else{
			printf("congrats!!\n");
			exit(0);
		}
	}
}
