#include <graphics.h>
#include <conio.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

// Function to draw a cube with given 3D vertices
void drawCube(int vertices[8][3]) {
    // Define the edges of the cube
    line(vertices[0][0], vertices[0][1], vertices[1][0], vertices[1][1]);
    line(vertices[1][0], vertices[1][1], vertices[2][0], vertices[2][1]);
    line(vertices[2][0], vertices[2][1], vertices[3][0], vertices[3][1]);
    line(vertices[3][0], vertices[3][1], vertices[0][0], vertices[0][1]);

    line(vertices[4][0], vertices[4][1], vertices[5][0], vertices[5][1]);
    line(vertices[5][0], vertices[5][1], vertices[6][0], vertices[6][1]);
    line(vertices[6][0], vertices[6][1], vertices[7][0], vertices[7][1]);
    line(vertices[7][0], vertices[7][1], vertices[4][0], vertices[4][1]);

    line(vertices[0][0], vertices[0][1], vertices[4][0], vertices[4][1]);
    line(vertices[1][0], vertices[1][1], vertices[5][0], vertices[5][1]);
    line(vertices[2][0], vertices[2][1], vertices[6][0], vertices[6][1]);
    line(vertices[3][0], vertices[3][1], vertices[7][0], vertices[7][1]);
}

int main() {
    // int gd = DETECT, gm;
    // initgraph(&gd, &gm, (char*)"");

    DWORD screenwidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenwidth, screenHeight, "cube", -3);

    // Define 3D vertices of the cube
    int vertices[8][3] = {
        {250, 150, -50},
        {350, 150, -50},
        {350, 250, -50},
        {250, 250, -50},
        {250, 150, 50},
        {350, 150, 50},
        {350, 250, 50},
        {250, 250, 50}
    };

    double angle = 0.00001;  // Adjust this angle increment for the desired speed

    while (!kbhit()) {
        // Clear the screen
        cleardevice();

        // Apply rotation transformation around the Y-axis
        for (int i = 0; i < 8; i++) {
            int x = vertices[i][0]-300; // Translate to the origin
            int z = vertices[i][2];
            
            int new_x = x * cos(angle) - z * sin(angle);
            int new_z = x * sin(angle) + z * cos(angle);

            // Apply rotation and translate back
            vertices[i][0] = new_x + 300;
            vertices[i][2] = new_z;
        }
 
        // Draw the cube
        setcolor(YELLOW);
        drawCube(vertices);

        // Delay to control the rotation speed
        delay(50);

        // Increment the rotation angle with a constant value
        angle += 0.005;
    }
    getch();
    // closegraph();
    return 0;
}