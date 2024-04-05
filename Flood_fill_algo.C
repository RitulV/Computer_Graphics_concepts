#include<stdio.h>  
#include<conio.h>  
#include<graphics.h>  

void flood(int x,int y,int fillColor, int defaultColor);

void drawCircleMidPoint(int x_center, int y_center, int r) {
    int x = 0;
    int y = r;
    int d = 1 - r;

    while (x <= y) {

        if (d < 0) {
            d = d + 2*x + 3;
        } else {
            y--;
            d = d + 2*(x - y) + 5;
        }
        x++;
        putpixel(x_center + x, y_center + y, WHITE);
        putpixel(x_center + y, y_center + x, WHITE);
        putpixel(x_center - y, y_center + x, WHITE);
        putpixel(x_center - x, y_center + y, WHITE);
        putpixel(x_center - x, y_center - y, WHITE);
        putpixel(x_center - y, y_center - x, WHITE);
        putpixel(x_center + y, y_center - x, WHITE);
        putpixel(x_center + x, y_center - y, WHITE);
    }
}

int main(){

    int gd=DETECT,gm;  
    initgraph(&gd,&gm,(char*)"");  
    //rectangle(50,50,250,250);
    // drawCircleMidPoint(250,200,100);
    circle(250,200,100);
    flood(250,200,5,0);  
    getch();

    return 0;
}

void flood(int x,int y,int fillColor, int defaultColor){

    if(getpixel(x,y)==defaultColor){

        delay(0.5);
        putpixel(x,y,fillColor);
        flood(x+1,y,fillColor,defaultColor);  
        flood(x-1,y,fillColor,defaultColor);  
        flood(x,y+1,fillColor,defaultColor);  
        flood(x,y-1,fillColor,defaultColor);  
    }
}