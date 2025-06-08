#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define MAX 200

char maze[MAX][MAX];
int rows, cols;
int startX, startY, endX, endY;

// Generate maze with a valid path from (1,1) to (rows-2, cols-2)
void generate_maze(int r, int c) {
    rows = r;
    cols = c;
    srand(time(NULL));

    // Fill maze with walls
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            maze[i][j] = '#';
        }
    }

    startX = 1; startY = 1;
    endX = rows - 2; endY = cols - 2;

    // Carve a guaranteed path (simple down and right)
    int x = startX, y = startY;
    maze[x][y] = ' ';
    while (x != endX || y != endY) {
        int dir = rand() % 2;
        if (dir == 0 && x < endX) x++;
        else if (dir == 1 && y < endY) y++;
        maze[x][y] = ' ';
    }

    // Add random extra paths for complexity
    for (int i = 0; i < (rows * cols) / 4; i++) {
        int rx = rand() % (rows - 2) + 1;
        int ry = rand() % (cols - 2) + 1;
        maze[rx][ry] = ' ';
    }
}