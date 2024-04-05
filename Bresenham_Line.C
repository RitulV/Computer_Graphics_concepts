// #include<stdio.h>
// #include<graphics.h>

// void Bresenham(int x0, int y0, int x1, int y1);

// int main(){
// 	int gd,gm,x0,y0,x1,y1;
// 	gd=DETECT;
// 	initgraph(&gd,&gm,(char*)"");
// 	// printf("Enter the value of initial point");
// 	// scanf("%d %d",&x0,&y0);
// 	// printf("Enter the value of second point");
// 	// scanf("%d %d",&x1,&y1);

// 	Bresenham(1,1,8,5);

// 	return 0;
// }

// void Bresenham(int x0, int y0, int x1, int y1){

// 	int dx,dy,x,y,po,m;
// 	dy=y1-y0, dx=x1-x0;
// 	x=x0, y=y0;
// 	m=dy/dx;
// 	if(m<1){
// 		po=2*dy-dx;
// 		while(x<x1){
// 			if(po>=0){
// 				putpixel(x,y,7);
// 				y++;
// 				po = po + 2*(dy-dx);
// 			}
// 			else{
// 				putpixel(x,y,7);
// 				po=po + 2*dy;
// 				x++;
// 			}
// 		}
// 	}
// 	else if(m>1){
// 		po=2*dx-dy;
// 		while(y<y1){
// 			if(po>=0){
// 				putpixel(x,y,7);
// 				x++;
// 				po = po + 2*(dx-dy);
// 			}
// 			else{
// 				putpixel(x,y,7);
// 				po=po + 2*dx;
// 				y++;
// 			}
// 		}
// 	}
// }

// //----------------------------------------------------------------------------------------------------------------------------------------

// #include<stdio.h>  
// #include<graphics.h>  

// void drawline(int x0, int y0, int x1, int y1)  {  
//     int dx, dy, p, x, y;  
//     dx=x1-x0;  
//     dy=y1-y0;  
//     x=x0;  
//     y=y0;  
//     p=2*dy-dx;  
//     while(x<x1)  
//     {  
//         if(p>=0)  
//         {  
//             putpixel(x,y,7);  
//             y=y+1;  
//             p=p+2*dy-2*dx;  
//         }  
//         else  
//         {  
//             putpixel(x,y,7);  
//             p=p+2*dy;}  
//             x=x+1;  
//         }  
// }

// int main()  
// {  
//     int gd, gm, error, x0, y0, x1, y1; 
//     detectgraph(&gd,&gm); 
//     initgraph(&gd, &gm, (char*)"");  
//     // printf("Enter co-ordinates of first point: ");  
//     // scanf("%d%d", &x0, &y0);  
//     // printf("Enter co-ordinates of second point: ");  
//     // scanf("%d%d", &x1, &y1);
//     drawline(1,1,8,5);  
//     return 0;  
// }  

//----------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void drawLineBresenham(int x1, int y1, int x2, int y2) {

    int P = 2 * (y2 - y1) - (x2 - x1);

    while (x1 < x2 && y1 < y2)
    {
        if (P < 0)
        {
            P = 2 * (y2 - y1) + P;
            x1++;
        }
        else
        {
            P = 2 * (y2 - y1) - 2 * (x2 - x1) + P;
            x1++;
            y1++;
        }

        putpixel(x1, y1, WHITE);
    }

}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int x1 = 100, y1 = 100, x2 = 300, y2 = 250;
    drawLineBresenham(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}