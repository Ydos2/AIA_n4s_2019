/*
** EPITECH PROJECT, 2020
** CPE_lemin_2019
** File description:
** main
*/

#ifndef MAIN_H_
#define MAIN_H_

#include <unistd.h>

#ifndef READ_SIZE
#define READ_SIZE (3)
#endif /* READ_SIZE */

typedef struct val {
    char *buff_inter;
    int turn;
    int carac;
} val_t;

// get_next_line.c
char *get_next_line(int fd);

// ai_core.c
int ai_core(void);

// cmd.c
int cmd_ex(char *cmd);

// set_cmd.c
int set_speed(float mid);
int set_dir(char **tab, float mid);

#endif /* !MAIN_H_ */
