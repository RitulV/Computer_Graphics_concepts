// #include<stdio.h>  
// #include<conio.h>  
// #include<graphics.h>

// void boundaryFill4(int x, int y, int fill_color,int boundary_color);

// int main(){
      
//     int gd=DETECT,gm;  
//     initgraph(&gd,&gm,(char*)"");  
//     rectangle(50,50,250,250);  
//     boundaryFill4(55,55,10,0);  
//     getch();

//     return 0;
// } 

// void boundaryFill4(int x, int y, int fill_color,int boundary_color)
// {
//     if(getpixel(x, y) != boundary_color &&
//        getpixel(x, y) != fill_color)
//     {
//         putpixel(x, y, fill_color);
//         boundaryFill4(x + 1, y, fill_color, boundary_color);
//         boundaryFill4(x, y + 1, fill_color, boundary_color);
//         boundaryFill4(x - 1, y, fill_color, boundary_color);
//         boundaryFill4(x, y - 1, fill_color, boundary_color);
//     }
// }

#include<stdio.h>  
#include<conio.h>  
#include<graphics.h>  

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

// Function for 4 connected Pixels
void boundaryFill4(int x, int y, int fill_color,int boundary_color)
{
	if(getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color)
	{
        delay(0.5);
		putpixel(x, y, fill_color);
		boundaryFill4(x + 1, y, fill_color, boundary_color);
		boundaryFill4(x, y + 1, fill_color, boundary_color);
		boundaryFill4(x - 1, y, fill_color, boundary_color);
		boundaryFill4(x, y - 1, fill_color, boundary_color);
	}
}

//driver code
int main()
{
	// gm is Graphics mode which is a computer display mode that generates image using pixels.
	// DETECT is a macro defined in "graphics.h" header file
	int gd = DETECT, gm;

	// initgraph initializes the graphics system by loading a graphics driver from disk
	initgraph(&gd, &gm, (char*)"");

	int x = 250, y = 200, radius = 100;

	putpixel(radius,0,WHITE);
	putpixel(0,radius,WHITE);
	putpixel(-radius,0,WHITE);
	putpixel(0,-radius,WHITE);
	
	// drawCircleMidPoint(x, y, radius);
	circle(x,y,radius);

	// Function calling
	boundaryFill4(x, y, 6, 15);

	delay(10000);

	getch();

	// closegraph function closes the graphics mode and deallocates all memory allocated by graphics system .
	closegraph();

	return 0;
}