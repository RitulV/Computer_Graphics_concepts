//point matrix 
//translation matrix
// translate the line and find resultant point
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <graphics.h>

void drawQuadrants();
void drawLine(int arr[4]);
void multiplyMatrices(int mat1[3][3], int mat2[3][2], int result[3][2]);
void translateLine(int arr[4], int dx, int dy);
void scaleLine(int arr[4], int sx, int sy);
void rotateLine(int arr[4], int angle, char ch);

void drawCircle(int x, int y, double r);

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    initwindow(getmaxwidth(), getmaxheight());

    printf("Max X distance: %d Max Y distance: %d", getmaxwidth()/2, getmaxheight()/2);

    drawQuadrants();
    
    int x1 = -100, y1 = -100, x2 = 100, y2 = 100;
    
    int pts[4] = {x1,y1,x2,y2};


    // Drawing a line from (-100, -50) to (100, 50)
    drawLine(pts);
    drawCircle(0,0,141.42135);

    rotateLine(pts, 90, 'c');
    drawLine(pts);

    
    // Translating the line by a distance of 10 in X and 20 in Y
    // translateLine(pts, 10, 20);
    // drawLine(pts);

    // Scaling the line by a factor of 5 in X and 1 in Y
    // scaleLine(pts, 5, 1);
    // drawLine(pts);

    // // Rotating the line by an angle of 90 in anti-clockwise direction
    // rotateLine(pts, 90, 'c');
    // drawLine(pts);

    getch();
    closegraph();
    return 0;
}

void drawQuadrants(){
    int xmax = getmaxx(), ymax = getmaxy(), xmid = getmaxx()/2, ymid = getmaxy()/2;
    line(xmid, 0, xmid, ymax);
    line(0, ymid, xmax, ymid);
}

void drawLine(int arr[4]){
    int x1 = arr[0];
    int y1 = arr[1];
    int x2 = arr[2];
    int y2 = arr[3];
    int xmid = getmaxx()/2, ymid = getmaxy()/2;
    line(x1+xmid, ymid-y1, x2+xmid, ymid-y2);
    printf("\nCoordinate of line drawn are: (%d,%d) & (%d,%d)",x1,y1,x2,y2);
}

void drawLine(int x1, int y1, int x2, int y2){
    int xmid = getmaxx()/2, ymid = getmaxy()/2;
    line(x1+xmid, ymid-y1, x2+xmid, ymid-y2);
    printf("\nCoordinate of line drawn are: (%d,%d) & (%d,%d)",x1,y1,x2,y2);
}

void multiplyMatrices(int mat1[3][3], int mat2[3][2], int result[3][2]) {
    int i, j, k;

    // Initialize the result matrix to all zeros
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            result[i][j] = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void multiplyMatrices(int mat1[3][3], int mat2[3][3], int result[3][3]) {
    int i, j, k;

    // Initialize the result matrix to all zeros
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            result[i][j] = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void multiplyMatrices(double mat1[3][3], double mat2[3][2], double result[3][2]) {
    int i, j, k;

    // Initialize the result matrix to all zeros
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            result[i][j] = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void multiplyMatrices(double mat1[3][3], double mat2[3][3], double result[3][3]) {
    int i, j, k;

    // Initialize the result matrix to all zeros
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            result[i][j] = 0;
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void translateLine(int arr[4], int dx, int dy) {

    printf("\nNew coordinate of line before translating are: (%d,%d) & (%d,%d)",arr[0], arr[1], arr[2], arr[3]);

    int x1 = arr[0];
    int y1 = arr[1];
    int x2 = arr[2];
    int y2 = arr[3];
    int M1[3][3] = {{1,0,dx},{0,1,dy},{0,0,1}}; 
    int M2[3][2] = {{x1,x2},{y1,y2},{1,1}}; 
    int R[3][2];
    multiplyMatrices(M1,M2,R);

    //drawLine(R[0][0], R[1][0], R[0][1], R[1][1]);

    arr[0] =  R[0][0];
    arr[1] =  R[1][0];
    arr[2] =  R[0][1];
    arr[3] =  R[1][1];

    printf("\nNew coordinate of line after translating are: (%d,%d) & (%d,%d)",R[0][0], R[1][0], R[0][1], R[1][1]);
}

void scaleLine(int arr[4], int sx, int sy) {

    printf("\nCoordinates of the line before scaling are: (%d,%d) & (%d,%d)", arr[0], arr[1], arr[2], arr[3]);

    int x1 = arr[0];
    int y1 = arr[1];
    int x2 = arr[2];
    int y2 = arr[3];

    // Calculate the midpoint of the line
    int xmid = (x1 + x2) / 2;
    int ymid = (y1 + y2) / 2;

    // Translate the line to the origin
    x1 -= xmid;
    y1 -= ymid;
    x2 -= xmid;
    y2 -= ymid;

    // Apply scaling
    x1 *= sx;
    y1 *= sy;
    x2 *= sx;
    y2 *= sy;

    // Translate the line back to its original position
    x1 += xmid;
    y1 += ymid;
    x2 += xmid;
    y2 += ymid;

    // Update the coordinates in the array
    arr[0] = x1;
    arr[1] = y1;
    arr[2] = x2;
    arr[3] = y2;

    printf("\nCoordinates of the line after scaling are: (%d,%d) & (%d,%d)", arr[0], arr[1], arr[2], arr[3]);
}

// void scaleLine(int arr[4], int sx, int sy){
//     /*
//     The entire process will be like this:
//     T = T1*S*T0
//     R1 = T1*S
//     R2 = R1*T0
//     P2 = R2*P1
//     */
//     int x1 = arr[0];
//     int y1 = arr[1];
//     int x2 = arr[2];
//     int y2 = arr[3];
//     int xmid,ymid;
//     xmid = (x1 + x2)/2;
//     ymid = (y1 + y2)/2;
//     int T0[3][3] = {{1,0,-xmid},{0,1,-ymid},{0,0,1}};
//     int S[3][3] = {{sx,0,0},{0,sy,0},{0,0,1}}; 
//     int T1[3][3] = {{1,0,xmid},{0,1,ymid},{0,0,1}};
//     int R1[3][3];
//     int R2[3][3];
//     int P1[3][2] = {{x1,x2},{y1,y2},{1,1}};
//     int P2[3][2];
//     multiplyMatrices(T1,S,R1);
//     multiplyMatrices(R1,T0,R2);
//     multiplyMatrices(R2,P1,P2);
//     arr[0] =  P2[0][0];
//     arr[1] =  P2[1][0];
//     arr[2] =  P2[0][1];
//     arr[3] =  P2[1][1];
//     //drawLine(R[0][0], R[1][0], R[0][1], R[1][1]);
//     printf("\nNew coordinate of line are: (%d,%d) & (%d,%d)",P2[0][0], P2[1][0], P2[0][1], P2[1][1]);
// }

void rotateLine(int arr[4], int angle, char ch) {
    double x1 = (double)arr[0];
    double y1 = (double)arr[1];
    double x2 = (double)arr[2];
    double y2 = (double)arr[3];
    double radians = (double)(angle * (M_PI / 180.0));
    double cos_theta = cos(radians);
    double sin_theta = sin(radians);

    double x1_rotated, y1_rotated, x2_rotated, y2_rotated;

    if (ch == 'c') {
        x1_rotated = x1 * cos_theta - y1 * sin_theta;
        y1_rotated = x1 * sin_theta + y1 * cos_theta;
        x2_rotated = x2 * cos_theta - y2 * sin_theta;
        y2_rotated = x2 * sin_theta + y2 * cos_theta;
    } else if (ch == 'a') {
        x1_rotated = x1 * cos_theta + y1 * sin_theta;
        y1_rotated = -x1 * sin_theta + y1 * cos_theta;
        x2_rotated = x2 * cos_theta + y2 * sin_theta;
        y2_rotated = -x2 * sin_theta + y2 * cos_theta;
    }

    arr[0] = (int)x1_rotated;
    arr[1] = (int)y1_rotated;
    arr[2] = (int)x2_rotated;
    arr[3] = (int)y2_rotated;

    printf("\nNew coordinates of the line are: (%d,%d) & (%d,%d)", arr[0], arr[1], arr[2], arr[3]);
}

void drawCircle(int x, int y, double r){
    int xmid = getmaxx()/2, ymid = getmaxy()/2;
    circle(x+xmid, ymid-y, r);    
}

// void rotateLine(int arr[4], int angle, char ch){
//     /*
//     The entire process will be like this:
//     T = T1*R*T0
//     R1 = T1*R
//     R2 = R1*T0
//     P2 = R2*P1
//     */
//     double x1 = double(arr[0]);
//     double y1 = double(arr[1]);
//     double x2 = double(arr[2]);
//     double y2 = double(arr[3]);
//     double radians = double(angle * (M_PI / 180.0));
//     double cos_theta = cos(radians);
//     double sin_theta = sin(radians);
//     double T0[3][3] = {{1,0,-x1},{0,1,-y1},{0,0,1}}; 
//     double T1[3][3] = {{1,0,x1},{0,1,y1},{0,0,1}};
//     double R[3][3];
//     double R1[3][3];
//     double R2[3][3];
//     double P1[3][2] = {{x1,x2},{y1,y2},{1,1}};
//     double P2[3][2];
//     if (ch == 'c') {
//         R[0][0] = cos_theta;
//         R[0][1] = sin_theta;
//         R[0][2] = 0;
//         R[1][0] = -sin_theta;
//         R[1][1] = cos_theta;
//         R[1][2] = 0;
//         R[2][0] = 0;
//         R[2][1] = 0;
//         R[2][2] = 1;
//     } else if (ch == 'a') {
//         R[0][0] = cos_theta;
//         R[0][1] = -sin_theta;
//         R[0][2] = 0;
//         R[1][0] = sin_theta;
//         R[1][1] = cos_theta;
//         R[1][2] = 0;
//         R[2][0] = 0;
//         R[2][1] = 0;
//         R[2][2] = 1;
//     }
//     multiplyMatrices(T1,R,R1);
//     multiplyMatrices(R1,T0,R2);
//     multiplyMatrices(R2,P1,P2);
//     arr[0] =  int(P2[0][0]);
//     arr[1] =  int(P2[1][0]);
//     arr[2] =  int(P2[0][1]);
//     arr[3] =  int(P2[1][1]);
//     //drawLine(R[0][0], R[1][0], R[0][1], R[1][1]);
//     printf("\nNew coordinate of line are: (%d,%d) & (%d,%d)",P2[0][0], P2[1][0], P2[0][1], P2[1][1]);
// }