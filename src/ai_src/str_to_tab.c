/*
** EPITECH PROJECT, 2020
** ai_core
** File description:
** ai_core
*/

#include <stdlib.h>
#include "my.h"
#include "fae.h"
#include "main.h"

char **str_to_tab(char *str, char lim, int *len)
{
    char **tab = malloc(sizeof(char **) * my_strlen(str));
    int j = 0;

    for (int k = 0, i = 0; str[i] != 0; k = 0) {
        tab[j] = malloc(sizeof(char *) * my_strlen(str));
        while (str[i] == lim && str[i++] != 0);
        while (str[i] != lim && str[i] != 0)
            tab[j][k++] = str[i++];
        tab[j++][k] = 0;
        while (str[i] == lim && str[i++] != 0);
    }
    tab[j] = NULL;
    *len = j;
    return (tab);
}