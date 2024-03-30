#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#include <dos.h>
#define sleep(x) Sleep(x * 1000)
#define clrscr() system("cls")
#else
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#define clrscr() printf("\e[1;1H\e[2J")
#define gotoxy(x, y) printf("\e[%d;%dH", y, x)
#endif

void zero(int x, int y);
void one(int x, int y);
void two(int x, int y);
void three(int x, int y);
void four(int x, int y);
void five(int x, int y);
void six(int x, int y);
void seven(int x, int y);
void eight(int x, int y);
void nine(int x, int y);
void colon(int x, int y);
void call(int digit, int x, int y);
int getTime();
int main()
{
    while (1)
    {

        getTime();
        sleep(1);
    }

    return 0; // indicate successful program termination
}

int getTime()
{
    int hour = 78;
    int minute = 56;
    int second = 10;

    clrscr(); //  screen clear

#ifdef _WIN32
    struct dostime_t time;
    _dos_gettime(&time);

    hour = time.hour;
    minute = time.minute;
    second = time.second;
#else

    struct timeval tv;
    struct tm *tm_info;
    gettimeofday(&tv, NULL);
    tm_info = localtime(&tv.tv_sec);

    // check if tm_info is NULL (error checking)
    if (tm_info == NULL)
    {
        perror("localtime");
        return 1;
    }

    hour = tm_info->tm_hour;
    minute = tm_info->tm_min;
    second = tm_info->tm_sec;
#endif

    call(hour / 10, 40, 7);
    call(hour % 10, 47, 7);
    colon(54, 7);
    call(minute / 10, 61, 7);
    call(minute % 10, 68, 7);
    colon(75, 7);
    call(second / 10, 82, 7);
    call(second % 10, 89, 7);
    printf("\n\n\n");
    return 0;
}

void call(int digit, int x, int y)
{
    switch (digit)
    {
    case 1:
        one(x, y);
        break;
    case 2:
        two(x, y);
        break;
    case 3:
        three(x, y);
        break;
    case 4:
        four(x, y);
        break;
    case 5:
        five(x, y);
        break;
    case 6:
        six(x, y);
        break;
    case 7:
        seven(x, y);
        break;
    case 8:
        eight(x, y);
        break;
    case 9:
        nine(x, y);
        break;
    default:
        zero(x, y);
    }
}
void colon(int x, int y)
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            gotoxy(x, y);
            if ((j == 3 && i == 3) || (j == 3 && i == 7))
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
            x++;
        }
        y++;
        x = x - 5;
        printf("\n");
    }
}
void nine(int x, int y)
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            gotoxy(x, y);
            if (j == 5 || i == 5 || i == 9 || i == 1 || (j == 1 && i < 5))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
            x++;
        }
        y++;
        x = x - 5;
        printf("\n");
    }
}
void eight(int x, int y)
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            gotoxy(x, y);
            if (i == 1 || i == 5 || i == 9 || j == 1 || j == 5)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
            x++;
        }
        y++;
        x = x - 5;
        printf("\n");
    }
}
void seven(int x, int y)
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            gotoxy(x, y);
            if (i == 1 || j == 5)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
            x++;
        }
        y++;
        x = x - 5;
        printf("\n");
    }
}
void six(int x, int y)
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            gotoxy(x, y);
            if (i == 1 || i == 5 || i == 9 || j == 1 || (j == 5 && i > 5))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
            x++;
        }
        y++;
        x = x - 5;
        printf("\n");
    }
}

void five(int x, int y)
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            gotoxy(x, y);
            if (i == 1 || i == 5 || i == 9 || (i > 5 && j == 5) || (j == 1 && i < 5))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
            x++;
        }
        y++;
        x = x - 5;
        printf("\n");
    }
}

void four(int x, int y)
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            gotoxy(x, y);
            if (i == 5 || j == 5 || (j == 1 && i < 5))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
            x++;
        }
        y++;
        x = x - 5;
        printf("\n");
    }
}

void three(int x, int y)
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            gotoxy(x, y);
            if (i == 1 || i == 5 || i == 9 || j == 5)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
            x++;
        }
        y++;
        x = x - 5;
        printf("\n");
    }
}
void two(int x, int y)
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            gotoxy(x, y);
            if (i == 1 || i == 5 || i == 9 || (i < 5 && j == 5) || (j == 1 && i > 5))
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
            x++;
        }
        y++;
        x = x - 5;
        printf("\n");
    }
}
void one(int x, int y)
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            gotoxy(x, y);
            if (j == 3)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
            x++;
        }
        y++;
        x = x - 5;
        printf("\n");
    }
}
void zero(int x, int y)
{
    int i, j;
    for (i = 1; i <= 9; i++)
    {
        for (j = 1; j <= 5; j++)
        {
            gotoxy(x, y);
            if (i == 1 || i == 9 || j == 1 || j == 5)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
            x++;
        }
        y++;
        x = x - 5;
        printf("\n");
    }
}