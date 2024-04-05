#include <graphics.h>

void drawCircle(int xp, int yp, int r){
    int d = 1.25 - r;

    while(xp < yp){
        if(d < 0){
            d = 2*xp + 3 + d;
        }
        else{
            d = 2*xp - 2*yp + 5 + d;
            yp--;
        }
        xp++;
        putpixel(xp+300,yp+237,BLUE);
        putpixel(yp+300,xp+237,GREEN);
        putpixel(-xp+300,yp+237,YELLOW);
        putpixel(-yp+300,xp+237,WHITE);
        putpixel(xp+300,-yp+237,BLUE);
        putpixel(yp+300,-xp+237,MAGENTA);
        putpixel(-xp+300,-yp+237,GREEN);
        putpixel(-yp+300,-xp+237,RED);
    }
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x = 0;
    int y = 200;
    int r = 200;

    drawCircle(x,y,r);
    getch();
    closegraph();
    return 0;
}