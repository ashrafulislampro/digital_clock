#include <stdio.h>

#ifdef _WIN32
#include <conio.h>
#else
#include <ncurses.h>
#define clrscr() printf("\e[1;1H\e[2J");
#endif

void zero();

int main()
{
    int i, j;
#ifdef _WIN32
    clrscr(); // screen clear for Windows
#else
    initscr(); // initialize ncurses
    clrscr();  // screen clear for Linux
#endif
    zero();
#ifdef _WIN32
    getch(); // getch() for Windows
#else
    getch();  // getch() for Linux
    endwin(); // end ncurses mode
#endif
    return 0;
}

void zero()
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            if (i == 1 || i == 9 || j == 1 || j == 5)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}