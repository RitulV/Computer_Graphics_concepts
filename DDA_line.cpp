// //DDA Line ALgorithm
// #include<graphics.h>
// #include <stdio.h>

// int main()
// {
//     int gd, gm;
//     detectgraph(&gd,&gm);
//     initgraph(&gd, &gm, (char*)"");
//     printf("%d %d",gd,gm);
//     putpixel(100, 200, COLOR(255,255,255));
//     closegraph();

//     return 0; 
// }

//----------------------------------------------------------------------------------------------------------------------------------------

#include <stdio.h>
#include <graphics.h>
#include <math.h>

void drawDDALine(int x1, int y1, int x2, int y2) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = x1, y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), WHITE);
        x += xIncrement;
        y += yIncrement;
    }

    delay(5000);
    closegraph();
}

int main() {
    int x1 = 100, y1 = 100, x2 = 300, y2 = 250;
    drawDDALine(x1, y1, x2, y2);

    return 0;
}
