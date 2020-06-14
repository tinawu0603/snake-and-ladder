#include <stdio.h>
#include <stdlib.h>
#include "midterm.h"

int nextMove(int dest)
{
    if (dest > 100)
    {
        dest = 100 - (dest - 100);
    }
    switch (dest)
    {
    case 1:
        printf("Woah, first try and you got a ladder!!\n");
        playToneLadder();
        return 38;
    case 4:
        printf("A ladder! Not bad, not bad.\n");
        playToneLadder();
        return 14;
    case 9:
        printf("You've landed on a ladder. Let's hope the good luck stays with you!\n");
        playToneLadder();
        return 31;
    case 16:
        printf("Oh no, a snake ... it's just a small setback.\n");
        playToneSnake();
        return 6;
    case 21:
        printf("A ladder. Keep it up. You got this!!\n");
        playToneLadder();
        return 42;
    case 28:
        printf("You've landed on the biggest ladder in the game. Congratulations!\n");
        playToneLadder();
        return 84;
    case 36:
        printf("A small ladder, we'll take all the wins we can get :)\n");
        playToneLadder();
        return 44;
    case 47:
        printf("You've landed on a snake. Better luck next time.\n");
        playToneSnake();
        return 26;
    case 49:
        printf("Oops, it's a snake. Keep your head up! The game is not over!\n");
        playToneSnake();
        return 11;
    case 51:
        printf("Yesss, go climb that ladder!\n");
        playToneLadder();
        return 67;
    case 56:
        printf("Just a few steps back with this snake, nothing to worry about.\n");
        playToneSnake();
        return 53;
    case 62:
        printf("You've landed on a big snake. Don't give up though.\n");
        playToneSnake();
        return 19;
    case 64:
        printf("You've landed on a small snake, you'll make it up next roll!\n");
        playToneSnake();
        return 60;
    case 71:
        printf("You've made it this far. Another ladder!!\n");
        playToneLadder();
        return 91;
    case 80:
        printf("THE JACKPOT!!! CONGRATULATIONS! You've landed on ladder to the finish line!!!\n");
        playToneLadder();
        return 100;
    case 87:
        printf("Oh no :( Looks like you stepped on the biggest snake in the game... Sorry!\n");
        playToneSnake();
        return 24;
    case 93:
        printf("You got a snake. Don't worry though, if winning was easy it wouldn't feel worth it.\n");
        playToneSnake();
        return 73;
    case 95:
        printf("So close... Yet, so far... Another snake.\n");
        playToneSnake();
        return 75;
    case 98:
        printf("Guess you drew the short straw and got a snake. Don't give up though!\n");
        playToneSnake();
        return 78;
    default:
        return dest;
    }
}
