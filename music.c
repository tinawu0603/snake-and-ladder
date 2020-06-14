#include "defines.h"
#include "midterm.h"

extern volatile int tick;
extern volatile int tick2;
extern volatile int *JP1_ptr;
extern volatile int *JP2_ptr;
extern int themeMusic;

void playPause()
{
    int j = 0;
    int value = 1;
    int value2 = 1;
    for (; j < 2000000; j++)
    {
        if (tick)
        {
            tick = 0;
            *(JP1_ptr) = 0;
        }
        if (tick2)
        {
            tick2 = 0;
            *(JP2_ptr) = 0;
        }
    }
}

void playTone1()
{
    config_HPS_timer(C5);
    config_interval_timer(C6);
    int i = 0;
    int j = 0;
    int value = 1;
    int value2 = 1;
    playPause();
    for (; j < 3; j++)
    {
        for (; i < 1000000; i++)
        {
            if (tick)
            {
                tick = 0;
                *(JP1_ptr) = value;
                value = value == 1 ? 0 : 1;
            }
        }
        for (; i > 0; i--)
        {
            if (tick2)
            {
                tick2 = 0;
                *(JP2_ptr) = value2;
                value2 = value2 == 1 ? 0 : 1;
            }
        }
    }
    playPause();
}

void playTone2()
{
    int i = 0;
    int value = 1;
    int value2 = 1;
    config_HPS_timer(C5);
    playPause();
    for (; i < 1000000; i++)
    {
        if (tick)
        {
            tick = 0;
            *(JP1_ptr) = value;
            value = value == 1 ? 0 : 1;
        }
    }
    config_interval_timer(E5);
    for (; i > 0; i--)
    {
        if (tick2)
        {
            tick2 = 0;
            *(JP2_ptr) = value2;
            value2 = value2 == 1 ? 0 : 1;
        }
    }
    config_HPS_timer(G5);
    for (; i < 1000000; i++)
    {
        if (tick)
        {
            tick = 0;
            *(JP1_ptr) = value;
            value = value == 1 ? 0 : 1;
        }
    }
    playPause();
}

void playTone3()
{
    int i = 0;
    int value = 1;
    int value2 = 1;
    config_HPS_timer(G5);
    playPause();
    for (; i < 1000000; i++)
    {
        if (tick)
        {
            tick = 0;
            *(JP1_ptr) = value;
            value = value == 1 ? 0 : 1;
        }
    }
    config_interval_timer(E5);
    for (; i > 0; i--)
    {
        if (tick2)
        {
            tick2 = 0;
            *(JP2_ptr) = value2;
            value2 = value2 == 1 ? 0 : 1;
        }
    }
    config_HPS_timer(C5);
    for (; i < 1000000; i++)
    {
        if (tick)
        {
            tick = 0;
            *(JP1_ptr) = value;
            value = value == 1 ? 0 : 1;
        }
    }
    playPause();
}

void playTheme(int theme)
{
    switch (theme)
    {
    case 1:
        playTone1();
        break;
    case 2:
        playTone2();
        break;
    case 3:
        playTone3();
        break;
    default:
        playTone2();
    }
}

void playToneLadder()
{
    int i = 0;
    int value = 1;
    int value2 = 1;
    config_HPS_timer(C5);
    for (; i < 1000000; i++)
    {
        if (tick)
        {
            tick = 0;
            *(JP1_ptr) = value;
            value = value == 1 ? 0 : 1;
        }
    }
    config_interval_timer(D5);
    for (; i > 0; i--)
    {
        if (tick2)
        {
            tick2 = 0;
            *(JP2_ptr) = value2;
            value2 = value2 == 1 ? 0 : 1;
        }
    }
    config_HPS_timer(E5);
    for (; i < 1000000; i++)
    {
        if (tick)
        {
            tick = 0;
            *(JP1_ptr) = value;
            value = value == 1 ? 0 : 1;
        }
    }
    config_interval_timer(F5);
    for (; i > 0; i--)
    {
        if (tick2)
        {
            tick2 = 0;
            *(JP2_ptr) = value2;
            value2 = value2 == 1 ? 0 : 1;
        }
    }
    config_HPS_timer(G5);
    for (; i < 1000000; i++)
    {
        if (tick)
        {
            tick = 0;
            *(JP1_ptr) = value;
            value = value == 1 ? 0 : 1;
        }
    }
    config_interval_timer(A5);
    for (; i > 0; i--)
    {
        if (tick2)
        {
            tick2 = 0;
            *(JP2_ptr) = value2;
            value2 = value2 == 1 ? 0 : 1;
        }
    }
    config_HPS_timer(B5);
    for (; i < 1000000; i++)
    {
        if (tick)
        {
            tick = 0;
            *(JP1_ptr) = value;
            value = value == 1 ? 0 : 1;
        }
    }
    config_interval_timer(C6);
    for (; i > 0; i--)
    {
        if (tick2)
        {
            tick2 = 0;
            *(JP2_ptr) = value2;
            value2 = value2 == 1 ? 0 : 1;
        }
    }
}

void playToneSnake()
{
    int i = 0;
    int value = 1;
    int value2 = 1;
    config_HPS_timer(C6);
    for (; i < 1000000; i++)
    {
        if (tick)
        {
            tick = 0;
            *(JP1_ptr) = value;
            value = value == 1 ? 0 : 1;
        }
    }
    config_interval_timer(B5);
    for (; i > 0; i--)
    {
        if (tick2)
        {
            tick2 = 0;
            *(JP2_ptr) = value2;
            value2 = value2 == 1 ? 0 : 1;
        }
    }
    config_HPS_timer(A5);
    for (; i < 1000000; i++)
    {
        if (tick)
        {
            tick = 0;
            *(JP1_ptr) = value;
            value = value == 1 ? 0 : 1;
        }
    }
    config_interval_timer(G5);
    for (; i > 0; i--)
    {
        if (tick2)
        {
            tick2 = 0;
            *(JP2_ptr) = value2;
            value2 = value2 == 1 ? 0 : 1;
        }
    }
    config_HPS_timer(F5);
    for (; i < 1000000; i++)
    {
        if (tick)
        {
            tick = 0;
            *(JP1_ptr) = value;
            value = value == 1 ? 0 : 1;
        }
    }
    config_interval_timer(E5);
    for (; i > 0; i--)
    {
        if (tick2)
        {
            tick2 = 0;
            *(JP2_ptr) = value2;
            value2 = value2 == 1 ? 0 : 1;
        }
    }
    config_HPS_timer(D5);
    for (; i < 1000000; i++)
    {
        if (tick)
        {
            tick = 0;
            *(JP1_ptr) = value;
            value = value == 1 ? 0 : 1;
        }
    }
    config_interval_timer(C5);
    for (; i > 0; i--)
    {
        if (tick2)
        {
            tick2 = 0;
            *(JP2_ptr) = value2;
            value2 = value2 == 1 ? 0 : 1;
        }
    }
}

void playRoll(int count)
{
    int value = 1;
    int value2 = 1;
    int rollCount = 0;
    for (; rollCount < count; rollCount += 1)
    {
        config_HPS_timer(C6);
        config_interval_timer(C5);
        int i = 0;
        for (; i < 1000000; i++)
        {
            if (tick)
            {
                tick = 0;
                *(JP1_ptr) = value;
                value = value == 1 ? 0 : 1;
            }
            if (tick2)
            {
                tick2 = 0;
                *(JP2_ptr) = value2;
                value2 = value2 == 1 ? 0 : 1;
            }
        }
        int j = 0;
        for (; j < 1000000; j++)
        {
            if (tick)
            {
                tick = 0;
                *(JP1_ptr) = 0;
            }
            if (tick2)
            {
                tick2 = 0;
                *(JP2_ptr) = 0;
            }
        }
    }
}

void selectThemeMusic()
{
    themeMusic = 4;
    while (themeMusic != 1 && themeMusic != 2 && themeMusic != 3)
    {
        if (themeMusic < 1 || themeMusic > 4)
        {
            printf("Invalid option, please select one of the options below.");
        }
        printf("Please select a theme music:\n");
        printf("1. Tone 1\n");
        playTone1();
        printf("2. Tone 2\n");
        playTone2();
        printf("3. Tone 3\n");
        playTone3();
        printf("4. Play tones again\n");
        printf("You selected: ");
        scanf("%d", &themeMusic);
    }
}
