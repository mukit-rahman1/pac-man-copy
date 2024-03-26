
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
int a = 0;
int max_width = 0;
int lines = 0;


//functions
/*
int check_win(int pacman_y, int pacman_x, int ghosts_y[NUM_GHOSTS], int ghosts_x[NUM_GHOSTS]);
 int check_loss(int pacman_y, int pacman_x, int ghosts_y[NUM_GHOSTS], int ghosts_x[NUM_GHOSTS]);
 char sees_pacman(int pacman_y, int pacman_x, int ghost_y, int ghost_x);
 //char * load_map(char * filename, int * map_height, int *map_width);
 int is_wall(int y, int x);
 int move_actor(int * y, int * x, char direction, int eat_dots);
 */

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

    char data[25*9 + 1]; // +1 for null terminator

    // Open the file
    file = fopen(filename, "r");

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Unable to open file %s.\n", filename);
        return 1;
    }
    int index = 0;
    while ((c = fgetc(file)) != EOF && index < max_width * lines) {
        if (c != '\n') { // Skip newline characters
            data[index++] = c;
        }
    }
    data[max_width * lines] = '\0';

    // Read data from the file into the 1D array
    printf("Contents of the file:\n");
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < max_width; j++) {

            printf("%c", data[a]);
            a++;
        }
        printf("\n");
    }

}

int makeGhosts () {
    FILE *file;
    file = fopen("map.txt","r");
    int gCounter = 0;
    int
    char c;


    while ((c = fgetc(file)) != EOF) {
        if (c == 'G') {
            gCounter++;
            counter++;
        }
        else {
            counter++;
        }
    }
    printf("%d", gCounter);

}
int ghostDirection() {

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

    makeGhosts();


    return NO_ERROR;
}
