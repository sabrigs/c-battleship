#include <stdio.h>
#include <stdbool.h>

// Global variables
#define SIZE 10
#define SHIP_LENGHT 3
#define SHIP 2
#define SHIPS 4

// Arrays
int battlefield[SIZE][SIZE] = {0};
char header[SIZE] = {'A','B','C','D','E','F','G','H','I','J'};

// Functions prototipes
int print_ship_horizontal(int row, int column);
int print_ship_vertical(int row, int column);
int print_ship_diagonal1(int row, int column);
int print_ship_diagonal2(int row, int column);
void print_battlefield(void);
void title(char *text);

int main(void)
{  
    // Conditional for add new ships
    char add = 'y';

    // Starting game
    title("START GAME");

    // Print battlefiel
    print_battlefield();

    // Loop for add ships
    do
    {
        // Ask for user to choose a position
        title("CHOOSE THE SHIP POSITION");
        printf("Write the row and column of the START of each ship.\n");

        int row = 0;
        int column = 0;

        printf("Row: ");
        scanf("%i", &row);

        printf("Column: ");
        scanf("%i", &column);

        // Menu
        int output;
        printf("\n");
        printf("[1] Horizontaly\n");
        printf("[2] Verticaly\n");
        printf("[3] Diagonaly (main)\n");
        printf("[4] Diagonaly (second)\n");
        printf("How to display on battlefield? ");
        scanf("%i", &output);

        switch (output)
        {
        case 1:
            // Horizontal
            print_ship_horizontal(row, column);
            break;
        case 2:
            // Vertical
            print_ship_vertical(row, column);
            break;
        case 3:
            // Diagonal (main)
            print_ship_diagonal1(row, column);
            break;
        case 4:
            // Diagonal (second)
            print_ship_diagonal2(row, column);
            break;
        default:
            printf("Invalid option.\n");
            break;
        }    

        title("BATTLEFIELD");
        print_battlefield();

        printf("\n");
        printf("Add more ships [y/n]? ");
        scanf(" %c", &add);
    }
    while (add == 'Y' || add == 'y');
    
    return 0;
}

void title(char *text)
{
    printf("\n");
    printf("----------- %s ----------- \n", text);
    printf("\n");
}

int print_ship_vertical(int row, int column)
{
    // Check
    for(int i = 0; i < SHIP_LENGHT; i++)
    {
        int temp_row = row + 1;
        int temp_column = column;

        // Check battlefield limits
        if (temp_row >= SIZE || temp_column >= SIZE)
        {
            printf("Out of battlefield limits.\n");
            return 1;
        }

        // Check if position is free
        if (battlefield[temp_row][temp_column] != 0)
        {
            printf("This position is not free.\n");
            return 1;
        }
    }

    for (int i = 0; i < SHIP_LENGHT; i++)
    {
        battlefield[row + i][column] = SHIP;
    }
}

int print_ship_horizontal(int row, int column)
{
    // Check
    for(int i = 0; i < SHIP_LENGHT; i++)
    {
        int temp_row = row;
        int temp_column = column + i;

        // Check battlefield limits
        if (temp_row >= SIZE || temp_column >= SIZE)
        {
            printf("Out of battlefield limits.\n");
            return 1;
        }

        // Check if position is free
        if (battlefield[temp_row][temp_column] != 0)
        {
            printf("This position is not free.\n");
            return 1;
        }
    }

    for (int i = 0; i < SHIP_LENGHT; i++)
    {
        battlefield[row][column + i] = SHIP;
    }
}

int print_ship_diagonal1(int row, int column)
{
    // Check
    for(int i = 0; i < SHIP_LENGHT; i++)
    {
        int temp_row = row + i;
        int temp_column = column + i;

        // Check battlefield limits
        if (temp_row >= SIZE || temp_column >= SIZE)
        {
            printf("Out of battlefield limits.\n");
            return 1;
        }

        // Check if position is free
        if (battlefield[temp_row][temp_column] != 0)
        {
            printf("This position is not free.\n");
            return 1;
        }
    }

    for (int i = 0; i < SHIP_LENGHT; i++)
    {
        battlefield[row + i][column + i] = SHIP;
    }
}

int print_ship_diagonal2(int row, int column)
{
    // Check
    for(int i = 0; i < SHIP_LENGHT; i++)
    {
        int temp_row = row + i;
        int temp_column = column - i;

        // Check battlefield limits
        if (temp_row >= SIZE || temp_column >= SIZE)
        {
            printf("Out of battlefield limits.\n");
            return 1;
        }

        // Check if position is free
        if (battlefield[temp_row][temp_column] != 0)
        {
            printf("This position is not free.\n");
            return 1;
        }
    }
    
    for (int i = 0; i < SHIP_LENGHT; i++)
    {
        battlefield[row + i][column - i] = SHIP;
    }
}

void print_battlefield(void)
{
    // Header
    printf("   ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%c", header[i]);
        printf(" ");
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++)
    {
        // Rows numbers
        printf("%i", i);
        printf("  ");
        for (int j = 0; j < SIZE; j++)
        {
            printf("%i", battlefield[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}