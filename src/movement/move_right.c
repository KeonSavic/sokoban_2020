/*
** EPITECH PROJECT, 2021
** move right
** File description:
** handles the right arrow key movement
*/

#include "my.h"
#include "sokoban.h"

void handles_block_right(game_t *game, char c, int row, int line)
{
    game->map[line][row] = ' ';
    game->map[line][row + 1] = 'P';
    if (c == 'X')
        game->map[line][row + 2] = 'X';
    game->P_row++;
}

void move_right(game_t *game)
{
    int row = game->P_row;
    int line = game->P_line;

    if (game->map[line][row + 2] != NULL && game->map[line][row + 1] != '#') {
        if (game->map[line][row + 1] == 'X' && \
        (game->map[line][row + 2] == '#' || game->map[line][row + 2] == 'X'));
        else {
            handles_block_right(game, game->map[line][row + 1], row, line);
        }
    }
}