/*
** EPITECH PROJECT, 2020
** cmd
** File description:
** cmd
*/

#include "my.h"
#include "main.h"

int cmd_ex(char *cmd)
{
    my_putstr(cmd);
    cmd = get_next_line(0);
    return (0);
}