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

//Value_id conrrespondance
enum {
    SIMULATION_NOT_LAUNCHED = 0,
    NO_ERROR = 1,
    SIMULATION_RUNNING = 2,
    UNKNOWN_ERROR = 3,
    CHECKPOINT_ERROR = 5,
    NETWORK_FAILURE = 6,
    SERVER_ERROR = 7,
    CLIENT_ERROR = 8,
    EOF_REACHED = 9,
    SIMULATION_CORRECTLY_ENDED = 10,
    EMPTY_COMMAND = 11,
    UNKNOWN_COMMAND = 12,
    WRONG_ARGUMENT = 13,
    TOO_MANY_ARGUMENTS = 14,
    PIPELINE_ERROR = 15,
    UNEXPECTED_ARGUMENT_VALUE = 16,
    CAMERA_INFOGET_FAILURE = 17,
    COMMAND_NOT_FOUND = 18,
    SIMULATION_ALREADY_RUNNING = 19,
    CYCLE_DONE = 20,
    SENSOR_READING_FAILURE = 21,
    NOT_ENOUGHT_CP = 22,
    TIMER_INIT_FAILURE = 23,
    TIMER_GET_FAILURE = 24,
    LOAD_MAP_FAILURE = 25
};

//Code_str type
enum {
    ACTION = 1,
    LIDAR = 2,
    INFO = 3,
    SYSTIME = 4
};

//Send type
enum {
    START_SIMULATION = 0,
    STOP_SIMULATION = 1,
    CAR_FORWARD = 2,
    CAR_BACKWARD = 3,
    WHEELS_DIR = 4,
    GET_INFO_LIDAR = 5,
    GET_CURRENT_SPEED = 6,
    GET_CURRENT_WHEELS = 7,
    CYCLE_WAIT = 8,
    GET_CAR_SPEED_MAX = 9,
    GET_CAR_SPEED_MIN = 10,
    GET_INFO_SIMTIME = 11
};

//checkpoint feedback type
enum {
    NO_CHECKPOINT = 0,
    FIRST_CP_CLEARED = 1,
    CP_CLEARED = 2,
    LAP_CLEARED = 3,
    TRACK_CLEARED = 4
};

typedef struct info {
    float lidar[32];
    char *action_data;
    float info_data;
    long symtime_data[2];
} info_t;

typedef struct checkpoint_info {
    int code;
} checkpoint_info_t;

typedef struct answer {
    int code;
    int status;
    info_t feedback;
    checkpoint_info_t checkpoint;
} answer_t;

typedef struct val {
    char *buff_inter;
    int turn;
    int carac;
} val_t;

typedef struct buffer {
    char buffer[READ_SIZE];
    unsigned int size;
} buffer_t;

// get_next_line.c
char *get_next_line(int fd);

// ai_core.c
int ai_core(void);

// cmd.c
answer_t cmd_ex(int cmd_code, float additionnal_data);

//str_to_tab.c
char *check_infos(char *str);
char **str_to_tab(char *str, char lim, int *len);

//get_answer.c
answer_t get_answer(int call_code);

// set_cmd.c
answer_t set_speed(float mid, int *result);
answer_t set_dir(answer_t feedback, int reverse);

#endif /* !MAIN_H_ */
