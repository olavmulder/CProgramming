#include "block.h"

void draw_field(Block *block){
	for(int i=0;i< ROW; i++){
		for (int j=0; j < COL; j++)
		{
			if(block->blocks[i][j].state == true){
				blit(block->blocks[i][j].block_texture, block->blocks[i][j].posX, block->blocks[i][j].posY, 0, BLOCK_WIDTH, BLOCK_HEIGHT);
				
			}
		}
	}	
}

