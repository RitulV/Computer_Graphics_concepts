#include <stdio.h>
#include <graphics.h>
#include <math.h>

void matrixMultiplication(double matrix1[4][4], double matrix2[4][1], double result[4][1])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main(){

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    double angle = 0.60925063;

    double Xmax = getmaxx();
    double Ymax = getmaxy();
    double Xcenter = Xmax / 2;
    double Ycenter = Ymax / 2;

    setcolor(YELLOW);
    line(Xcenter, 0, Xcenter, Ycenter); //y-axis
    line(Xcenter, Ycenter, Xmax, Ycenter); //x-axis
    line(0,Ymax,Xcenter,Ycenter); //z-axis

    setcolor(WHITE);

    line(Xcenter,Ycenter-100,Xcenter+100,Ycenter-100); //back-top
    line(Xcenter+100,Ycenter-100,Xcenter+100,Ycenter); //back-right
    line(Xcenter,Ycenter-100,Xcenter-100*sin(angle),Ycenter-100*sin(angle)); //top-left
    line(Xcenter+100,Ycenter-100,Xcenter+100-100*sin(angle),Ycenter-100*sin(angle)); //top-right
    line(Xcenter-100*sin(angle),Ycenter-100*sin(angle),Xcenter+100-100*sin(angle),Ycenter-100*sin(angle)); //front-top
    line(Xcenter+100-100*sin(angle),Ycenter-100*sin(angle),Xcenter+100-100*sin(angle),Ycenter+100-100*sin(angle)); //front-right
    line(Xcenter+100,Ycenter,Xcenter+100-100*sin(angle),Ycenter+100-100*sin(angle)); //bottom-right
    line(Xcenter,Ycenter,Xcenter-100*sin(angle),Ycenter+100-100*sin(angle)); //bottom-left
    line(Xcenter-100*sin(angle),Ycenter-100*sin(angle),Xcenter-100*sin(angle),Ycenter+100-100*sin(angle)); //front-bottom
    line(Xcenter,Ycenter,Xcenter+100,Ycenter); //back-bottom
    line(Xcenter,Ycenter-100,Xcenter,Ycenter); //back-left
    line(Xcenter+100-100*sin(angle),Ycenter+100-100*sin(angle),Xcenter-100*sin(angle),Ycenter+100-100*sin(angle)); //front-left

    // double mat1[4][4] = {{cos(angle),0,sin(angle),0},{0,1,0,0},{-sin(angle),0,cos(angle),0},{0,0,0,1}};
    // double mat2[4][1] = {{Xcenter+100},{Ycenter-100},{0},{1}};
    // double result[4][1];
    // matrixMultiplication(mat1,mat2,result);

    // line(Xcenter,Ycenter-100,result[0][0],result[1][0]);

    char maxXmax[100], maxYmax[100];
    sprintf(maxXmax, "Xmax: %f", Xmax);
    sprintf(maxYmax, "Ymax: %f", Ymax);
    
    outtextxy(10, 10, maxXmax);
    outtextxy(10, 30, maxYmax);

    getch();
    closegraph();
    return 0;
}