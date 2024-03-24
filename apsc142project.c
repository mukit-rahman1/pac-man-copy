
// APSC 142 Engineering Programming Project Starter Code
// Copyright Sean Kauffman 2024

// don't forget to update your project configuration to select "Emulate terminal in the output console"

// Make sure to include all relevant libraries
#include <stdio.h>
#include <stdlib.h>

// colours.h contains functions to change text colour and read single characters without requiring an enter
#include "colours.h"
// defines.h contains useful definitions to keep your code readable
#include "defines.h"
// map.h, game.h, and ghost.h contain prototypes of functions you must implement
#include "map.h"
#include "game.h"
#include "ghost.h"

// These global variables must be used to store map information.
// Almost every function needs these variables, so keeping them as globals helps keep things organized.
// map is a pointer to a dynamically allocated map for displaying to the user
// dot_map is a pointer to a dynamically allocated map for keeping track of what dots are left
char *map = NULL, *dot_map = NULL;
// width and height store the width and height of map, NOT counting outer walls
int width, numb, height;
FILE *mapTxt;



//functions
int check_win(int pacman_y, int pacman_x, int ghosts_y[NUM_GHOSTS], int ghosts_x[NUM_GHOSTS]);
 int check_loss(int pacman_y, int pacman_x, int ghosts_y[NUM_GHOSTS], int ghosts_x[NUM_GHOSTS]);
 char sees_pacman(int pacman_y, int pacman_x, int ghost_y, int ghost_x);
 //char * load_map(char * filename, int * map_height, int *map_width);
 int is_wall(int y, int x);
 int move_actor(int * y, int * x, char direction, int eat_dots);

char * load_map(const char *filename, int *map_height, int *map_width) {
    FILE *file;// Initializing variables
    char c;
    int current_width = 0;
    int max_width = 0;
    int lines = 0;

    file = fopen(filename, "r");//Open file
    if (file == NULL) {
        printf("Could not open the file.\n");
        return 5;
    }

    while ((c = fgetc(file)) != EOF) {//Calculating height and width until we reach the end
        if (c == '\n') {//Height
            lines++;
            if (current_width > max_width) {//Width
                max_width = current_width;
            }
            current_width = 0;
        } else {
            current_width++;
        }
    }

    if (current_width > 0) {//Add an extra line for height at the end
        lines++;
        if (current_width > max_width) {
            max_width = current_width;
        }
    }
    fclose(file);
    // Update height and width
    *map_height = lines;
    *map_width = max_width;
}




/**
 * Main entry point into your program.
 * Make sure that main returns appropriate status codes depending on what
 * happens.  The codes you must use are:
 *   NO_ERROR when no error occur
 *   //test
 *   ERR_NO_MAP when no map file is found
 *   ERR_NO_PACMAN when no pacman is found on the map
 *   ERR_NO_GHOSTS when fewer than 2 ghosts are found on the map
 *
 * Make sure that any allocated memory is freed before returning.
 * @return a status code
 */
int main(void) {
    setbuf(stdout, NULL);

    char *filename = "map.txt";

    load_map(filename, &height, &width);

    printf("Height: %d\n", height);
    printf("Width: %d\n", width);




    return NO_ERROR;
}
