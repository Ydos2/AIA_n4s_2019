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

static const int CALL_TO_TYPE[12] =
    {1, 1, 1, 1, 1, 2, 3, 3, 3, 3, 3, 4}; 

int set_checkpoint(char *str)
{
    int result = 0;

    result = (!fae_strcmp(str, "First CP Cleared")) ? 1 : result;
    result = (!fae_strcmp(str, "CP Cleared")) ? 2 : result;
    result = (!fae_strcmp(str, "Lap Cleared")) ? 3 : result;
    result = (!fae_strcmp(str, "Track Cleared")) ? 4 : result;
    return result;
}

info_t get_code_str(char **tab, int call_code)
{
    info_t info = {0};
    int type_code = CALL_TO_TYPE[call_code];

    switch (type_code)
    {
    case 1 :
        info.action_data = tab[2];
        break;
    case 2 :
        for (int i = 0; i < 32; i++)
            info.lidar[i] = my_atof(tab[2 + i]);
        break;
    case 3 :
        info.info_data = my_atof(tab[2]);
        break;
    case 4 :
        info.symtime_data[0] = fae_stoi(tab[2], NULL);
        info.symtime_data[1] = fae_stoi(tab[3], NULL);
    }
    return info;
}

answer_t set_answer(char **tab, int len, int call_code)
{
    answer_t answer = {0};

    answer.code = fae_stoi(tab[0], NULL);
    answer.status = (!fae_strcmp(tab[1], "OK")) ? 1 : 0;
    answer.checkpoint.code = set_checkpoint(tab[len - 2]);
    answer.feedback = get_code_str(tab, call_code);
    return answer;
}

answer_t get_answer(int call_code)
{
    answer_t answer = {0};
    char *str = NULL;
    char **tab;
    int len = 0;

    str = get_next_line(0);
    tab = str_to_tab(str, ':', &len);
    answer = set_answer(tab, len, call_code);
    return answer;
}