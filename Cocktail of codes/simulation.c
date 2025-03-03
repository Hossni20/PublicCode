#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define WIDTH 80
#define HEIGHT 24
#define PI 3.14159265358979323846

void clearScreen() {
    printf("\033[H\033[J");
}

void displayFrame(char screen[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            putchar(screen[y][x]);
        }
        putchar('\n');
    }
}

void resetScreen(char screen[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            screen[y][x] = ' ';
        }
    }
}

void drawCube(char screen[HEIGHT][WIDTH], float angleX, float angleY) {
    float cubeSize = 10.0;
    float points[8][3] = {
        {-1, -1, -1},
        {1, -1, -1},
        {1, 1, -1},
        {-1, 1, -1},
        {-1, -1, 1},
        {1, -1, 1},
        {1, 1, 1},
        {-1, 1, 1}
    };

    int edges[12][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0},
        {4, 5}, {5, 6}, {6, 7}, {7, 4},
        {0, 4}, {1, 5}, {2, 6}, {3, 7}
    };

    float rotationX[3][3] = {
        {1, 0, 0},
        {0, cos(angleX), -sin(angleX)},
        {0, sin(angleX), cos(angleX)}
    };

    float rotationY[3][3] = {
        {cos(angleY), 0, sin(angleY)},
        {0, 1, 0},
        {-sin(angleY), 0, cos(angleY)}
    };

    float projected[8][2];

    for (int i = 0; i < 8; i++) {
        float x = points[i][0] * cubeSize;
        float y = points[i][1] * cubeSize;
        float z = points[i][2] * cubeSize;

        // Rotate around X-axis
        float tempY = y * rotationX[1][1] + z * rotationX[1][2];
        float tempZ = y * rotationX[2][1] + z * rotationX[2][2];
        y = tempY;
        z = tempZ;

        // Rotate around Y-axis
        float tempX = x * rotationY[0][0] + z * rotationY[0][2];
        tempZ = x * rotationY[2][0] + z * rotationY[2][2];
        x = tempX;
        z = tempZ;

        // Project onto 2D screen
        float distance = 20.0;
        float factor = distance / (distance - z);
        projected[i][0] = x * factor + WIDTH / 2;
        projected[i][1] = -y * factor + HEIGHT / 2;
    }

    // Draw edges
    for (int i = 0; i < 12; i++) {
        int p1 = edges[i][0];
        int p2 = edges[i][1];

        int x1 = (int)projected[p1][0];
        int y1 = (int)projected[p1][1];
        int x2 = (int)projected[p2][0];
        int y2 = (int)projected[p2][1];

        // Simple line drawing (Bresenham's Algorithm)
        int dx = abs(x2 - x1), sx = x1 < x2 ? 1 : -1;
        int dy = -abs(y2 - y1), sy = y1 < y2 ? 1 : -1;
        int err = dx + dy, e2;

        while (1) {
            if (x1 >= 0 && x1 < WIDTH && y1 >= 0 && y1 < HEIGHT) {
                screen[y1][x1] = '#';
            }
            if (x1 == x2 && y1 == y2) break;
            e2 = 2 * err;
            if (e2 >= dy) { err += dy; x1 += sx; }
            if (e2 <= dx) { err += dx; y1 += sy; }
        }
    }
}

int main() {
    char screen[HEIGHT][WIDTH];
    float angleX = 0, angleY = 0;

    while (1) {
        resetScreen(screen);
        drawCube(screen, angleX, angleY);
        clearScreen();
        displayFrame(screen);

        angleX += 0.05;
        angleY += 0.03;

        usleep(50000); // Delay for smooth animation
    }

    return 0;
}
