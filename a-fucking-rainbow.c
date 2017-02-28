#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

/*
 *
 * It's a fucking rainbow.
 *
 */

int main(int argc, char *argv[])
{
    char red[] = "\e[48;5;1m";
    char orange[] = "\e[48;5;208m";
    char yellow[] = "\e[48;5;226m";
    char green[] = "\e[48;5;10m";
    char blue[] = "\e[48;5;27m";
    char indigo[] = "\e[48;5;57m";
    char violet[] = "\e[48;5;54m";

    char *all_the_fucking_colors[] = {red, orange, yellow, green, blue, indigo, violet};
    int number_of_all_the_fucking_colors = 6;
    int the_current_fucking_color = 0;
    while(1)
    {
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        for(int i = 0; i < w.ws_col; i++)
        {
            printf("%s%c\e[49m", all_the_fucking_colors[the_current_fucking_color], ' ');
        }

        if(the_current_fucking_color < number_of_all_the_fucking_colors)
            the_current_fucking_color++;
        else
            the_current_fucking_color = 0;
        sleep(0.3);
    }
    return 0;
}
