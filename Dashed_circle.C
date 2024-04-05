#include <graphics.h>

void drawCircle(int xp, int yp, int r){
    int d = 1.25 - r;

    while(xp < yp){
        if(d < 0){
            d = 2*xp + 3 + d;
        }
        else{
            d = 2*xp - 2*yp + 5 + d;
            yp-=4;
        }
        xp+=4;

        putpixel(xp+r,yp+r,WHITE);
        putpixel(yp+r,xp+r,WHITE);
        putpixel(-xp+r,yp+r,WHITE);
        putpixel(-yp+r,xp+r,WHITE);
        putpixel(xp+r,-yp+r,WHITE);
        putpixel(yp+r,-xp+r,WHITE);
        putpixel(-xp+r,-yp+r,WHITE);
        putpixel(-yp+r,-xp+r,WHITE);
    }
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x = 0;
    int y = 100;
    int r = 100;

    drawCircle(x,y,r);
    getch();
    closegraph();
    return 0;
}