/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** Main function
*/

#include <stdio.h>
#include "my.h"
#include "main.h"

static void draw_help(void)
{
    write(1, "USAGE\n", 6);
    write(1, "\t./vrep.sh\n", 11);
}

int main(int ac, char **av)
{
    if (ac == 2)
        if (my_strcmp(av[1], "-h") == 0) {
            draw_help();
            return (0);
        }
    if (ac != 1)
        return (84);
    return (ai_core());
}