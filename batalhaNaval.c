#include <stdio.h>

void title(char *text);

#define SIZE 10
#define SHIP_LENGHT 3
#define SHIP 2

int battlefield[SIZE][SIZE] = {0};
char header[SIZE] = {'A','B','C','D','E','F','G','H','I','J'};

// Functions prototipes
void print_ship_horizontal(int row, int column);
void print_ship_vertical(int row, int column);
void print_battlefield(void);

int main(void)
{   
    int row;
    int column;

    title("START GAME");

    printf("Row: ");
    scanf("%i", &row);

    printf("Column: ");
    scanf("%i", &column);

    print_ship_vertical(row, column);
    
    print_battlefield();

    return 0;
}

void title(char *text)
{
    printf("\n");
    printf("----------- %s ----------- \n", text);
    printf("\n");
}

void print_ship_vertical(int row, int column)
{
    for (int i = 0; i < SHIP_LENGHT; i++)
    {
        battlefield[row + i][column] = SHIP;
    }
}

void print_ship_horizontal(int row, int column)
{
    for (int i = 0; i < SHIP_LENGHT; i++)
    {
        battlefield[row][column + i] = SHIP;
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