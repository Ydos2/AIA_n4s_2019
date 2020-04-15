/*
** EPITECH PROJECT, 2020
** set_cmd
** File description:
** set_cmd
*/

#include "my.h"
#include "main.h"

int set_speed(float mid)
{
    if (mid >= 2000)
        return (cmd_ex("car_forward:1.0\n"));
    if (mid >= 1500)
        return (cmd_ex("car_forward:0.8\n"));
    if (mid >= 1000)
        return (cmd_ex("car_forward:0.5\n"));
    if (mid >= 600)
        return (cmd_ex("car_forward:0.4\n"));
    if (mid >= 400)
        return (cmd_ex("car_forward:0.2\n"));
    return (cmd_ex("car_forward:0.1\n"));
}

static int select_direction(float f, char *val)
{
    my_putstr("wheels_dir:");
    if (f < 0.0)
        my_putchar('-');
    my_putstr(val);
    val = get_next_line(0);
    return (0);
}

int set_dir(char **tab, float mid)
{
    float right = my_atof(tab[31]);
    float left = my_atof(tab[1]);

    if (mid >= 1500)
        return (select_direction(left - right, "0.005\n"));
    if (mid >= 1000)
        return (select_direction(left - right, "0.05\n"));
    if (mid >= 600)
        return (select_direction(left - right, "0.1\n"));
    if (mid >= 400)
        return (select_direction(left - right, "0.2\n"));
    if (mid >= 200)
        return (select_direction(left - right, "0.3\n"));
    return (select_direction(left - right, "0.5\n"));
}