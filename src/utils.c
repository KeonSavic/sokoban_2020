/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#include "my.h"
#include "sokoban.h"

void count_Os(game_t *game, int *o_counter)
{
    for (int i = 0; game->map[i] != NULL; i++) {
        for (int j = 0; game->map[i][j] != NULL; j++) {
            if (game->map[i][j] == 'O') {
                (*o_counter)++;
            }
        }
    }
}

void get_o_pos(game_t *game, int *o_nb, int o_counter)
{
    for (int i = 0; game->map[i] != NULL && (*o_nb) < o_counter; i++) {
        for (int j = 0; game->map[i][j] != NULL && (*o_nb) < o_counter; j++) {
            if (game->map[i][j] == 'O') {
                game->O_pos[(*o_nb)].line = i;
                game->O_pos[(*o_nb)].row = j;
                (*o_nb)++;
            }
        }
    }
}