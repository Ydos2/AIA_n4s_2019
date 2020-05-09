/*
** EPITECH PROJECT, 2020
** ai_core
** File description:
** ai_core
*/

#include <stdlib.h>
#include "my.h"
#include "main.h"
#include "fae.h"

static answer_t select_speed(answer_t feedback, int *reverse)
{
    float mid;

    mid = feedback.feedback.lidar[15];
    *reverse = 1;
    return set_speed(mid, reverse);
}

static answer_t select_rotation(answer_t feedback, int reverse)
{
    return set_dir(feedback, reverse);
}

int ai_core(void)
{
    answer_t feedback = {0};
    answer_t tmp = {0};
    int check = 0;
    int reverse = 1;

    feedback = cmd_ex(START_SIMULATION, 0);
    if (feedback.status == 0) {
        fae_err_put("Launch failed\n");
        return 84;
    }
    check = feedback.checkpoint.code;
    while (feedback.checkpoint.code != TRACK_CLEARED) {
        feedback = cmd_ex(GET_INFO_LIDAR, 0);
        check = feedback.checkpoint.code;
        tmp = select_speed(feedback, &reverse);
        check = (check < tmp.checkpoint.code) ? tmp.checkpoint.code : check;
        tmp = select_rotation(feedback, reverse);
        check = (check < tmp.checkpoint.code) ? tmp.checkpoint.code : check;
        tmp = cmd_ex(CYCLE_WAIT, 1);
        check = (check < tmp.checkpoint.code) ? tmp.checkpoint.code : check;
    }
    cmd_ex(STOP_SIMULATION, 0);
    return (0);
}