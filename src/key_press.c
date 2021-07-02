/*
** EPITECH PROJECT, 2021
** key press
** File description:
** the player pressed a key
*/

#include "my.h"
#include "sokoban.h"

void reset(game_t *game)
{
    free(game->map);
    game->P_line = game->P_start.line;
    game->P_row = game->P_start.row;
    game->map = my_arrdup(game->start_map);
}

void handle_key_press(game_t *game, int ch)
{
    int codes[] = {258, 259, 260, 261, 32};
    void (*fptr[])(game_t *) = \
    {move_down, move_up, move_left, move_right, reset};

    for (int i = 0; i < 5; i++) {
        if (ch == codes[i]) {
            fptr[i](game);
            break;
        }
    }
}