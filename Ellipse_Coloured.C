#include <graphics.h>
#include <math.h>

void drawEllipseRegion1(int a, int b, int x, int y)
{
    int d = a * a / 4 + b * b - a * a * b;

    while (x < (a * a * y) / (b * b))
    {   
        if (d < 0)
        {
            d = b * b * (2 * x + 3) + d;
            x++;
        }
        else
        {
            d = b * b * (2 * x + 3) - 2 * a * a * (y - 1) + d;
            x++;
            y--;
        }
        putpixel(x + 319, y + 237, YELLOW);
        putpixel(-x + 319, y + 237, GREEN);

        putpixel(x + 319, -y + 237, BLUE);

        putpixel(-x + 319, -y + 237, RED);
    }
}
void drawEllipseRegion2(int a, int b)
{
    double root = sqrt(a * a + b * b);
    int x = a * a / root;
    int y = b * b / root;
    int d = a * a + b * b / 4 - (b * b * a * a) / root;

    while (y!=0)
    {
        if (d < 0)
        {
            d = 2 * b * b * (x + 1) - a * a * (2 * y - 3) + d;
            x++;
            y--;
        }
        else
        {
            d = 3 * a * a - 2 * a * a * y + d;
            y--;
        }
        putpixel(x + 319, y + 237, GREEN);
        putpixel(-x + 319, y + 237, YELLOW);
        putpixel(-x + 319, -y + 237, BLUE);
        putpixel(x + 319, -y + 237, RED);
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    int a = 300;
    int b = 150;
    int x = 0;
    int y = 150;

    drawEllipseRegion1(a, b, x, y);
    drawEllipseRegion2(a, b);

    getch();
    closegraph();
    return 0;
}