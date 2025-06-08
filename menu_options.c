#include <stdio.h>
#include <stdbool.h>
#include "menu_functions/menu_functions.h"
#include "menu_functions/rwh_apfa/rwh_apfa.h"

void menu_options() {

    int choice;
    char filename[100];
    do {
        printf("Maze Menu:\n");
        printf("1. Generate maze\n");
        printf("2. Print maze\n");
        printf("3. Save maze to file\n");
        printf("4. Load maze from file\n");
        printf("5. Run Right-Wall Hugging\n");
        printf("6. Run BFS\n");
        printf("7. Move manually\n");
        printf("0. Exit\n");
        printf("Choose a number 0-7: ");
        scanf("%d", &choice);

    } while (choice < 0 || choice > 7);

        switch (choice) {
            case 1: {
                int rows, cols;
                printf("Enter number of rows: ");
                scanf("%d", &rows);
                printf("Enter number of columns: ");
                scanf("%d", &cols);
                generate_maze(rows, cols);
                break;
            }
            case 2:
                print_maze();
                break;
            case 3:
                printf("Filename to save: ");
                scanf("%s", filename);
                save_maze_to_file(filename);
                break;
            case 4:
                printf("Filename to load: ");
                scanf("%s", filename);
                load_maze_from_file(filename);
                break;
            case 5:
                int startX, startY; 
                right_wall_hugging(startX, startY, 1);
                break;
            case 6:
                bfs();
                break;
            case 7:
                user_move();
                break;
            case 0:
                return;
            default:
                printf("Invalid option!\n");
        }
}