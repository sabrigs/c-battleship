#include <stdio.h>
#include <stdbool.h>

// GLOBAL VARIABLES

// Settings
#define SIZE 10 // Array size
#define SHIP_LENGHT 3
#define HEIGHT_DIAMOND 3
#define HEIGHT_CONE 3
#define HEIGHT_DAGGER 3

// Battlefield prints
#define SHIP 3
#define OCEAN 0
#define POWER 5
#define BUSY 1 // Ship and power overlay

// Array
int battlefield[SIZE][SIZE] = {OCEAN};

// FUNCTIONS PROTOTYPIES
void title(char *text);
void print_battlefield(void);
int print_ship_horizontal(int row, int column);
int print_ship_vertical(int row, int column);
int print_ship_diagonal1(int row, int column);
int print_ship_diagonal2(int row, int column);
int print_dagger(int row, int column);
int print_cone(int row, int column);
int print_diamond(int row, int column);

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

        do
        {
            printf("Row (0-9): ");
            scanf("%i", &row);
        } while (row >= SIZE || row < 0);
        
        do
        {
            printf("Column (0-9): ");
            scanf("%i", &column);
        } while (column > SIZE || column < 0);

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
        printf("\n");
        printf("Add more ships [y/n]? ");
        scanf(" %c", &add);
    }
    while (add == 'Y' || add == 'y');

    title("RESULT");

    print_dagger(1, 2);
    print_cone(6, 2);
    print_diamond(1, 8);
    print_battlefield();
    
    return 0;
}

void title(char *text)
{
    printf("\n");
    printf("----------- %s ----------- \n", text);
    printf("\n");
}

void print_battlefield(void)
{
    // Header
    printf("  ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", i);
    }
    printf("\n");

    for (int i = 0; i < SIZE; i++)
    {
        // Rows numbers
        printf("%i ", i);
        
        for (int j = 0; j < SIZE; j++)
        {
            printf("%i ", battlefield[i][j]);
        }
        printf("\n");
    }
}

int print_ship_vertical(int row, int column)
{
    for (int i = 0; i < SHIP_LENGHT; i++)
    {
        int temp_row = row + i;

        if (temp_row >= SIZE || temp_row < 0 || column >= SIZE || column < 0)
        {
            printf("Out of battlefield limits.\n");
            return 1;
        }
        if (battlefield[temp_row][column] != 0)
        {
            printf("This position is not free.\n");
            return 1;
        }
    }
    
    for (int i = 0; i < SHIP_LENGHT; i++)
    {
        battlefield[row + i][column] = SHIP;
    }
    return 0;
}

int print_ship_horizontal(int row, int column)
{
    for (int i = 0; i < SHIP_LENGHT; i++)
    {
        int temp_column = column + i;

        if (row >= SIZE || row < 0 || temp_column >= SIZE || temp_column < 0 )
        {
            printf("Out of battlefield limits.\n");
            return 1;
        }
        if (battlefield[row][temp_column] != 0)
        {
            printf("This position is not free.\n");
            return 1;
        }
    }

    for (int i = 0; i < SHIP_LENGHT; i++)
    {
        battlefield[row][column + i] = SHIP;
    }
    return 0;
}

int print_ship_diagonal1(int row, int column)
{
    for (int i = 0; i < SHIP_LENGHT; i++)
    {
        int temp_row = row + i;
        int temp_column = column + i;

        if (temp_row >= SIZE || temp_row < 0 || temp_column >= SIZE || temp_column < 0)
        {
            printf("Out of battlefield limits.\n");
            return 1;
        }
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
    return 0;
}

int print_ship_diagonal2(int row, int column)
{
    for (int i = 0; i < SHIP_LENGHT; i++)
    {
        int temp_row = row + i;
        int temp_column = column - i;

        if (temp_row >= SIZE || temp_row < 0 || temp_column >= SIZE || temp_column < 0)
        {
            printf("Out of battlefield limits.\n");
            return 1;
        }
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
    return 0;
}

int print_cone(int row, int column)
{
    // Rows
    for(int r = 0; r < HEIGHT_CONE; r++)
    {   
        // Columns
        for(int c = -r; c <= r; c++)
        {
            int temp_row = row + r;
            int temp_column = column + c;

            if (temp_row >= SIZE || temp_column < 0 || temp_column >= SIZE || temp_column < 0)
            {
                printf("Out of battlefield limits.\n");
                return 1;
            }
            if (battlefield[temp_row][temp_column] == SHIP)
            {
                battlefield[row + r][column + c] = BUSY;
            }
            else
            {
                battlefield[row + r][column + c] = POWER;
            }
        }
    }
    return 0;
}

int print_dagger(int row, int column)
{
    for(int r = 0; r < HEIGHT_DAGGER; r++)
    {  
        // Find the middle
        if (r == HEIGHT_DAGGER/2)
        {
            for(int c = -2; c <= 2; c++)
            {
                int temp_row = row + r;
                int temp_column = column + c;

                if (temp_row >= SIZE || temp_row < 0 || temp_column >= SIZE || temp_column < 0)
                {
                    printf("Out of battlefield limits.\n");
                    return 1;
                }
                if (battlefield[temp_row][temp_column] == SHIP)
                {
                    battlefield[row + r][column + c] = BUSY;
                }
                // Print
                else
                {
                    battlefield[row + r][column + c] = POWER;
                }
            }
        }
        // If it's not the middle
        else
        {   
            int temp_row = row + r;

            if (temp_row >= SIZE || temp_row < 0 || column >= SIZE || column < 0)
            {
                printf("Out of battlefield limits.\n");
                return 1;
            }
            if (battlefield[row + r][column] == SHIP)
            {
                battlefield[row + r][column] = BUSY;
            }
            // Print
            else
            {
                battlefield[row + r][column] = POWER;
            }
        }
    }
    return 0;
}

int print_diamond(int row, int column)
{
    for(int r = 0; r < HEIGHT_DIAMOND; r++)
    {  
        // Find the middle
        if (r == HEIGHT_DIAMOND/2)
        {
            for(int c = -1; c <= 1; c++)
            {
                int temp_row = row + r;
                int temp_column = column + c;

                if (temp_row >= SIZE || temp_row < 0 || temp_column >= SIZE || temp_column < 0)
                {
                    printf("Out of battlefield limits.\n");
                    return 1;
                }
                if (battlefield[temp_row][temp_column] == SHIP)
                {
                    battlefield[row + r][column + c] = BUSY;
                }
                // Print
                else
                {
                    battlefield[row + r][column + c] = POWER;
                }
            }
        }
        // If it's not the middle
        else
        {   
            int temp_row = row + r;

            if (temp_row >= SIZE || temp_row < 0 || column >= SIZE || column < 0)
            {
                printf("Out of battlefield limits.\n");
                return 1;
            }
            if (battlefield[row + r][column] == SHIP)
            {
                battlefield[row + r][column] = BUSY;
            }
            // Print
            else
            {
                battlefield[row + r][column] = POWER;
            }
        }
    }
    return 0;
}