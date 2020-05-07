/*
** EPITECH PROJECT, 2020
** cmd
** File description:
** cmd
*/

#include "my.h"
#include "main.h"
#include "fae.h"

static char *char_command[12] = {
    "START_SIMULATION",
    "STOP_SIMULATION",
    "CAR_FORWARD",
    "CAR_BACKWARDS",
    "WHEELS_DIR",
    "GET_INFO_LIDAR",
    "GET_CURRENT_SPEED",
    "GET_CURRENT_WHEELS",
    "CYCLE_WAIT",
    "GET_CAR_SPEED_MAX",
    "GET_CAR_SPEED_MIN",
    "GET_INFO_SIMTIME"
};

static void put_float(float f)
{
    int left = (int)f;
    float right = f - left;

    fae_putstr(fae_itos(left));
    fae_putchar('.');
    for (int i = 0; i < 1000; i++) {
        right = right * 10;
        fae_putchar((int)right + '0');
        right = right - (int)right;
    }
}

void put_err_float(float f)
{
    int left = (int)f;
    float right = f - left;

    fae_err_putstr(fae_itos(left));
    fae_err_putchar('.');
    for (int i = 0; i < 3; i++) {
        right = right * 10;
        fae_err_putchar((int)right + '0');
        right = right - (int)right;
    }
}

answer_t cmd_ex(int cmd_code, float additionnal_data)
{
    my_putstr(char_command[cmd_code]);
    if (cmd_code == CAR_FORWARD || cmd_code == CAR_BACKWARD
        || cmd_code == WHEELS_DIR) {
            fae_putchar(':');
            if (additionnal_data < 0) {
                fae_putchar('-');
                additionnal_data = -additionnal_data;
            }
            put_float(additionnal_data);
        }
    if (cmd_code == CYCLE_WAIT)
        fae_put(":%d", (int)(additionnal_data));
    fae_putchar('\n');
    return get_answer(cmd_code);
}