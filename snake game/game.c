#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *replicate_string(const char *str, int times)
{
    if (times <= 0)
    {
        return NULL;
    }

    // Allocate memory for the new string
    char *result = (char *)malloc(times + 1); // +1 for the null terminator
    if (result == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Initialize the new string
    result[0] = '\0';

    // Concatenate the original string to the new string 'times' times
    for (int i = 0; i < times; i++)
    {
        strcat(result, str);
    }

    return result;
}

void main()
{
    WINDOW *win = initscr();
    keypad(win, true);
    nodelay(win, true);
    int posX = 0;
    int posY = 0;
    int foodX = rand() % 20;
    int foodY = rand() % 20;
    int dirX = 1;
    int dirY = 0;
    int score = 0;
    while (true)
    {
        int pressed = wgetch(win);
        if (pressed == KEY_LEFT)
        {
            dirX = -1;
            dirY = 0;
        }
        if (pressed == KEY_RIGHT)
        {
            dirX = 1;
            dirY = 0;
        }
        if (pressed == KEY_UP)
        {
            dirX = 0;
            dirY = -1;
        }
        if (pressed == KEY_DOWN)
        {
            dirX = 0;
            dirY = 1;
        }

        posX += dirX;
        posY += dirY;
        erase();
        char *snake = replicate_string("*", score + 1);
        mvaddstr(posY, posX, snake);
        mvaddstr(foodY, foodX, "&");
        if (foodX == posX && foodY == posY)
        {
            foodX = rand() % 20;
            foodY = rand() % 20;
            score += 1;
         
        }
        usleep(100000);
    }
    endwin();
}