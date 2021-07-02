/*
** EPITECH PROJECT, 2021
** move left
** File description:
** handles the left arrow key movement
*/

#include "my.h"
#include "sokoban.h"

void handles_block_left(game_t *game, char c, int row, int line)
{
    game->map[line][row] = ' ';
    game->map[line][row - 1] = 'P';
    if (c == 'X')
        game->map[line][row - 2] = 'X';
    game->P_row--;
}

void move_left(game_t *game)
{
    int row = game->P_row;
    int line = game->P_line;

    if (row > 1 && game->map[line][row - 1] != '#') {
        if (game->map[line][row - 1] == 'X' && \
        (game->map[line][row - 2] == '#' || game->map[line][row - 2] == 'X'));
        else {
            handles_block_left(game, game->map[line][row - 1], row, line);
        }
    }
}