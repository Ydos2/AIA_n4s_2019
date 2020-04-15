/*
** EPITECH PROJECT, 2020
** my_atof
** File description:
** my_atof
*/

#include <stdio.h>

float my_atof(char *str)
{
    float nb = 0;
    int i = 0;
    int idx = 0;

    while (str[idx] != 0 && str[idx] >= '0' && str[idx] <= '9')
        nb = nb * 10.0 + (str[idx++] - 48);
    idx += 1;
    if (str[idx] == '.') {
        while (str[idx] != 0) {
            nb = nb * 10.0 + (str[idx] - 48);
            i -= 1;
        }
    }
    while (i++ < 0)
        nb *= 0.1;
    return (nb);
}