#include "vaus.h"
//extern SDL_Renderer *renderer;
void draw_vaus(Vaus *vaus){
	if(vaus->posX >= SCREEN_WIDTH-vaus->width){
		vaus->posX = SCREEN_WIDTH-vaus->width;
	}
	SDL_Rect draw_vaus = {vaus->posX, vaus->posY, vaus->width,vaus->height};
	SDL_SetRenderDrawColor(renderer, 25,78,125,255);
	SDL_RenderFillRect(renderer, &draw_vaus);
	
}