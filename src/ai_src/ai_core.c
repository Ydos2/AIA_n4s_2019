/*
** EPITECH PROJECT, 2020
** ai_core
** File description:
** ai_core
*/

#include <stdlib.h>
#include "my.h"
#include "main.h"

static char **str_to_tab(char *str, char lim)
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
    return (tab);
}

static char *check_infos(char *str)
{
    int a = 0;
    int b = 0;
    char *tmp = malloc(sizeof(char *) * 100);

    while (a != 3)
        if (str[b++] == ':')
            a++;
    a = 0;
    while (str[b] != 0) {
        if ((str[b] >= '0' && str[b] <= '9') 
        || str[b] == '.' || str[b] == ':') {
            tmp[a] = str[b];
            a++;
        }
        b++;
    }
    tmp[a - 1] = '\0';
    return (tmp);
}

static int select_speed(void)
{
    char *str = NULL;
    char **tab;
    float mid;

    my_putstr("get_info_lidar\n");
    str = get_next_line(0);
    str = check_infos(str);
    tab = str_to_tab(str, ':');
    mid = my_atof(tab[15]);
    set_speed(mid);
    return (0);
}

static int select_rotation(void)
{
    char *str = NULL;
    char **tab;
    float mid;

    my_putstr("get_info_lidar\n");
    str = get_next_line(0);
    str = check_infos(str);
    tab = str_to_tab(str, ':');
    mid = my_atof(tab[15]);
    set_dir(tab, mid);
    return (0);
}

int ai_core(void)
{
    cmd_ex("start_simulation\n");
    while (1) {
        select_speed();
        select_rotation();
    }
    return (0);
}