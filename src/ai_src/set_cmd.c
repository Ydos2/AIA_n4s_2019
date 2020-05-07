/*
** EPITECH PROJECT, 2020
** set_cmd
** File description:
** set_cmd
*/

#include "my.h"
#include "main.h"
#include "fae.h"

void put_err_float(float f);

answer_t set_speed(float mid, int *result)
{
    if (mid >= 1500)
        return (cmd_ex(CAR_FORWARD, 1.0));
    if (mid >= 1000)
        return (cmd_ex(CAR_FORWARD, 0.8));
    if (mid >= 600)
        return (cmd_ex(CAR_FORWARD, 0.4));
    if (mid >= 400)
        return (cmd_ex(CAR_FORWARD, 0.2));
    if (mid >= 200)
        return (cmd_ex(CAR_FORWARD, 0.1));
    *result = -1;
    if (mid >= 100)
        return (cmd_ex(CAR_BACKWARD, 1));
    return (cmd_ex(CAR_BACKWARD, 1));
}

static answer_t select_direction(float f, float val)
{
    if (f < 0)
        val = -val;
    return cmd_ex(WHEELS_DIR, val);
}

static answer_t set_urgence(float left, float right, int reverse)
{
    if (left < 100)
        return (select_direction(-1, 1 * reverse));
    if (left < 200)
        return (select_direction(-1, 0.3 * reverse));
    if (right < 100)
        return (select_direction(1, 1 * reverse));
    if (right < 200)
        return (select_direction(1, 0.3 * reverse));
    return (answer_t) {0};
}

answer_t set_dir(answer_t feedback, int reverse)
{
    float mid = feedback.feedback.lidar[15];
    float right = feedback.feedback.lidar[31];
    float left = feedback.feedback.lidar[1];

    if (left < 200 || right < 200)
        return set_urgence(left, right, reverse);
    if (mid >= 1500)
        return (select_direction(left - right, 0.005 * reverse));
    if (mid >= 1000)
        return (select_direction(left - right, 0.09 * reverse));
    if (mid >= 600)
        return (select_direction(left - right, 0.1 * reverse));
    if (mid >= 400)
        return (select_direction(left - right, 0.4 * reverse));
    if (mid >= 200)
        return (select_direction(left - right, 0.8 * reverse));
    return (select_direction(left - right, 1 * reverse));
}