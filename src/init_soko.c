/*
** EPITECH PROJECT, 2021
** init sokoban
** File description:
** initializes the sokoban game
*/

#include "my.h"
#include "sokoban.h"

void launch_window_prep(game_t *game)
{
    initscr();
    noecho();
    cbreak();
    start_color();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    get_player_pos(game);
}

void save_P_pos(game_t *game)
{
    int j = 0;

    for (int i = 0; game->map[i] != NULL; i++) {
        for (j = 0; game->map[i][j] != NULL && game->map[i][j] != 'P'; j++);
        if (game->map[i][j] == 'P') {
            game->P_start.line = i;
            game->P_start.row = j;
            break;
        }
    }
}

void get_biggest_line_and_row(game_t *game)
{
    int i = 0;
    int biggest = 0;

    for (i = 0; game->map[i] != NULL; i++) {
        if (my_strlen(game->map[i]) > my_strlen(game->map[biggest]))
            biggest = i;
    }
    game->max_line = my_strlen(game->map[biggest]);
    game->max_row = i;
}

void save_O_pos(game_t *game)
{
    int o_nb = 0;
    int o_counter = 0;

    count_Os(game, &o_counter);
    game->O_pos = malloc(sizeof(pos_t) * o_counter);
    get_o_pos(game, &o_nb, o_counter);
    game->O_nb = o_nb;
}

void init_sokoban(game_t *game, char *buff)
{
    game->map = my_str_to_word_array(buff);
    game->start_map = my_arrdup(game->map);
    game->over = 0;
    game->pause = 0;
    game->blocked_box = 0;
    game->cursor_row = 0;
    game->cursor_line = 0;
    get_biggest_line_and_row(game);
    save_P_pos(game);
    save_O_pos(game);
}