#include <stdio.h>

int ladders[] = {1, 4, 9, 21, 28, 36, 51, 71, 80};
int snakes[] = {16, 47, 49, 56, 62, 64, 87, 93, 95, 98};

void printSpace(int step)
{
    if (step == 1 || step == 4 || step == 9 || step == 21 ||
        step == 28 || step == 36 || step == 51 || step == 71 ||
        step == 80)
    {
        printf("L ");
    }
    else if (step == 16 || step == 47 || step == 49 ||
             step == 56 || step == 62 || step == 64 || step == 87 ||
             step == 93 || step == 95 || step == 98)
    {
        printf("S ");
    }
    else
    {
        if (step < 10)
        {
            printf("%d ", step);
        }
        else
        {
            printf("%d", step);
        }
    }
}

void printBox(int i, int player, int cpu)
{
    if (i == player && i == cpu)
    {
        printf(" OX |");
    }
    else if (i == player)
    {
        printf(" O  |");
    }
    else if (i == cpu)
    {
        printf(" X  |");
    }
    else
    {
        if (i == 100)
        {
            printf(" $$ |");
        }
        else
        {
            printf(" ");
            printSpace(i);
            printf(" |");
        }
    }
}

// Increment index
void printRowLR(int i, int player, int cpu)
{
    int threshold = i + 10;
    for (; i < threshold; i += 1)
    {
        printBox(i, player, cpu);
    }
}

// Decrement index
void printRowRL(int i, int player, int cpu)
{
    int threshold = i - 10;
    for (; i > threshold; i -= 1)
    {
        printBox(i, player, cpu);
    }
}

void printBoard(int player, int cpu)
{
    printf(" ---------------------------------------------------\n |");
    printRowRL(100, player, cpu);
    printf("\n ---------------------------------------------------\n |");
    printRowLR(81, player, cpu);
    printf("\n ---------------------------------------------------\n |");
    printRowRL(80, player, cpu);
    printf("\n ---------------------------------------------------\n |");
    printRowLR(61, player, cpu);
    printf("\n ---------------------------------------------------\n |");
    printRowRL(60, player, cpu);
    printf("\n ---------------------------------------------------\n |");
    printRowLR(41, player, cpu);
    printf("\n ---------------------------------------------------\n |");
    printRowRL(40, player, cpu);
    printf("\n ---------------------------------------------------\n |");
    printRowLR(21, player, cpu);
    printf("\n ---------------------------------------------------\n |");
    printRowRL(20, player, cpu);
    printf("\n ---------------------------------------------------\n |");
    printRowLR(1, player, cpu);
    printf("\n ---------------------------------------------------\n");
}