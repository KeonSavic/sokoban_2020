/*
** EPITECH PROJECT, 2020
** navy
** File description:
** navy
*/

#ifndef navy
#define navy

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <ncurses.h>

typedef struct pos_s {
    int line;
    int row;
} pos_t;

typedef struct game_s {
    int over;
    int pause;
    int cursor_row;
    int cursor_line;
    int max_row;
    int max_line;
    int P_row;
    int P_line;
    int O_nb;
    int blocked_box;
    pos_t P_start;
    pos_t *O_pos;
    char **map;
    char **start_map;
} game_t;

void init_sokoban(game_t *game, char *buff);
int my_sokoban(game_t *game);
void reset(game_t *game);
void move_up(game_t *game);
void move_down(game_t *game);
void move_left(game_t *game);
void move_right(game_t *game);
void get_player_pos(game_t *game);
void launch_window_prep(game_t *game);
int check_end_condition(game_t *game);
void count_Os(game_t *game, int *o_counter);
void handle_key_press(game_t *game, int ch);
void get_o_pos(game_t *game, int *o_nb, int o_counter);

#endif /* !navy */
