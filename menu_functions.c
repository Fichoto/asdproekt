#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

extern char maze[MAX][MAX];
extern int rows, cols;
extern int startX, startY, endX, endY;
extern void right_wall_hugging(int x, int y, int dir);
extern void bfs();
extern void generate_maze(int r, int c);

// Print maze to console
void print_maze() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Save maze to file
void save_maze_to_file(const char* filename) {
    FILE* f = fopen(filename, "w");
    if (!f) {
        printf("Could not open file for writing.\n");
        return;
    }
    fprintf(f, "%d %d\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        fprintf(f, "%.*s\n", cols, maze[i]);
    }
    fclose(f);
    printf("Maze saved to %s\n", filename);
}

// Load maze from file
void load_maze_from_file(const char* filename) {
    FILE* f = fopen(filename, "r");
    if (!f) {
        printf("Could not open file.\n");
        return;
    }
    fscanf(f, "%d %d\n", &rows, &cols);
    for (int i = 0; i < rows; i++) {
        fgets(maze[i], MAX, f);
        maze[i][strcspn(maze[i], "\n")] = 0;
    }
    fclose(f);
    printf("Maze loaded from %s\n", filename);
}

// Move manually through the maze
void user_move() {
    int x = startX;
    int y = startY;
    char command;
    printf("Manual movement. Use W/A/S/D to move, Q to quit.\n");
    while (1) {
        printf("You are at (%d, %d)\n", x, y);
        scanf(" %c", &command);
        int nx = x, ny = y;
        if (command == 'w') nx--;
        else if (command == 's') nx++;
        else if (command == 'a') ny--;
        else if (command == 'd') ny++;
        else if (command == 'q') break;
        else continue;

        if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && maze[nx][ny] == ' ') {
            x = nx; y = ny;
        } else {
            printf("Blocked!\n");
        }

        if (x == endX && y == endY) {
            printf("You reached the exit!\n");
            break;
        }
    }
}
