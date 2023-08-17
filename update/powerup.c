#include "powerup.h"

void powerup(Vaus *vaus, Ball *ball, int pownr){
    switch (pownr)
    {
    case 0:
        vaus->width +=20;
        break;
    case 1:
        ball->speed +=10;
        break;
    case 2:
        vaus->width = 300;
        break;
    case 3:
        vaus->width = 50;
        ball->speed = 25;
        break;
    case 4:
        vaus->width -=20;
        if(vaus->width < 20){
            vaus->width = 20;
        }
        break;
    default:
        break;
    }
}