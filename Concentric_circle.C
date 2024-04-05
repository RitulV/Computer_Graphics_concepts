#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void drawCircleMidPoint(int x_center, int y_center, int r, int c) {
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
        putpixel(x_center + x, y_center + y, c);
        putpixel(x_center + y, y_center + x, c);
        putpixel(x_center - y, y_center + x, c);
        putpixel(x_center - x, y_center + y, c);
        putpixel(x_center - x, y_center - y, c);
        putpixel(x_center - y, y_center - x, c);
        putpixel(x_center + y, y_center - x, c);
        putpixel(x_center + x, y_center - y, c);
    }
}

int main()
{
    int gdriver = DETECT,gmode;
    int x,y,i;
	initgraph(&gdriver,&gmode,(char *)"");
	for(i=30;i<200;i++)
	{
		delay(100);
		int x = i/10;
        drawCircleMidPoint(250,250,i-10,x);
        //arc(x,y,0,180,i-10);
	}

    return 0;
}