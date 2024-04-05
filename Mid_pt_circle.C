#include <stdio.h>
#include <graphics.h>

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

int main() {
    int gd, gm;
    detectgraph(&gd,&gm);
    initgraph(&gd, &gm, (char*)"");

    // printf("Enter the radius of the circle: ");
    // scanf("%d", &radius);

    drawCircleMidPoint(250, 250, 100);

    delay(5000);
    closegraph();
    return 0;
}