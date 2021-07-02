/*
** EPITECH PROJECT, 2021
** move up
** File description:
** handles the up key event
*/

#include "my.h"
#include "sokoban.h"

void handles_block_up(game_t *game, char c, int row, int line)
{
    game->map[line][row] = ' ';
    game->map[line - 1][row] = 'P';
    if (c == 'X')
        game->map[line - 2][row] = 'X';
    game->P_line--;
}

void move_up(game_t *game)
{
    int row = game->P_row;
    int line = game->P_line;

    if (line > 1 && game->map[line - 1][row] != '#') {
        if (game->map[line - 1][row] == 'X' && \
        (game->map[line - 2][row] == '#' || game->map[line - 2][row] == 'X'));
        else {
            handles_block_up(game, game->map[line - 1][row], row, line);
        }
    }
}