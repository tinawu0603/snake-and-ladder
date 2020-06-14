#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "midterm.h"
#include "address_map_arm.h"
#include "defines.h"
#include "interrupt_ID.h"

int playerPos;
int cpuPos;
volatile int tick = 0; // set to 1 every time the HPS timer expires
volatile int tick2 = 0;
volatile int key_dir = 0;
volatile int pattern = 0x0F0F0F0F; // pattern for LED lights
volatile int *JP1_ptr = (int *)JP1_BASE;
volatile int *JP2_ptr = (int *)JP2_BASE; // JP2 address
int themeMusic;

void init()
{
    // initialize random seed
    srand(time(0));
    playerPos = 0;
    cpuPos = 0;
}

// Returns a random value between 1 and 6
int rollDice()
{
    return rand() % 6 + 1;
}

void movePlayer(int roll)
{
    int dest;
    dest = nextMove(playerPos + roll);
    playerPos = dest;
    printf("Your position is now %d\n", playerPos);
}

void moveCPU(int roll)
{
    int dest;
    dest = nextMove(cpuPos + roll);
    cpuPos = dest;
    printf("The computer's position is now %d\n", cpuPos);
}

void playerTurn()
{
    int roll;
    volatile int *KEY_ptr = (int *)KEY_BASE;
    int KEY_value = *(KEY_ptr);
    // Player turn
    printf("\nPlease roll dice by pressing one of the push buttons: \n");
    while (KEY_value != 1 && KEY_value != 2 && KEY_value != 4 && KEY_value != 8)
    {
        KEY_value = *(KEY_ptr);
    }
    roll = rollDice();
    printf("You rolled %d\n", roll);
    playRoll(roll);
    movePlayer(roll);
    printBoard(playerPos, cpuPos);
    while (roll == 6)
    {
        KEY_value = *(KEY_ptr);
        printf("You rolled a 6, extra roll!\n");
        printf("\nPlease roll dice by pressing one of the push buttons: \n");
        while (KEY_value != 1 && KEY_value != 2 && KEY_value != 4 && KEY_value != 8)
        {
            KEY_value = *(KEY_ptr);
        }
        roll = rollDice();
        printf("You rolled %d\n", roll);
        playRoll(roll);
        movePlayer(roll);
        printBoard(playerPos, cpuPos);
    }
}

void cpuTurn()
{
    int roll;
    // Computer turn
    roll = rollDice();
    printf("The computer rolled %d\n", roll);
    playRoll(roll);
    moveCPU(roll);
    printBoard(playerPos, cpuPos);
    while (roll == 6)
    {
        printf("The computer rolled a 6, extra roll!\n");
        roll = rollDice();
        printf("The computer rolled %d\n", roll);
        playRoll(roll);
        moveCPU(roll);
        printBoard(playerPos, cpuPos);
    }
}

void welcome()
{
    char playerName[20];
    printf("What is your name? ");
    scanf("%s", &playerName);
    printf("\nHello %s! We're so excited to be with you on this journey. May the best player wins.\n", playerName);
}

int main()
{
    init();
    // Declarations
    int roll;
    // JP1 address
    volatile int *JP1_direction = (int *)0xFF200064; // JP1 direction
    volatile int *JP2_direction = (int *)0xFF200074; // JP2 direction
    volatile int value = 1;
    volatile int value2 = 1;
    *(JP1_direction) = 1;
    *(JP1_ptr) = value;
    *(JP2_direction) = 1;
    *(JP2_ptr) = value2;
    set_A9_IRQ_stack();
    config_GIC();
    config_HPS_timer(C5);
    config_interval_timer(C6);
    enable_A9_interrupts();

    welcome();
    selectThemeMusic();

    while (playerPos != 100 && cpuPos != 100)
    {
        playTheme(themeMusic);
        playerTurn();
        playTheme(themeMusic);
        cpuTurn();
    }

    // End of game
    if (playerPos == 100)
    {
        printPlayerWon();
    }
    else if (cpuPos == 100)
    {
        printComputerWon();
    }
    return 0;
}
