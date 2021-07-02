/*
** EPITECH PROJECT, 2021
** end condition
** File description:
** handles the ending condition for winning or losing the game
*/

#include "my.h"
#include "sokoban.h"

int get_adjacent_tiles(game_t *game, int line, int row)
{
    char adj[4];

    for (int i = 0; i < game->O_nb; i++) {
        if (line == game->O_pos[i].line && row == game->O_pos[i].row )
            return (1);
    }
    adj[0] = game->map[line - 1][row];
    adj[1] = game->map[line][row + 1];
    adj[2] = game->map[line + 1][row];
    adj[3] = game->map[line][row - 1];
    if ((adj[0] == '#' || adj[0] == 'X') && (adj[3] == '#' || adj[3] == 'X'))
        return (1);
    for (int i = 0; i < 3; i++) {
        if ((adj[i] == '#' || adj[i] == 'X') && \
        (adj[i + 1] == '#' || adj[i + 1] == 'X'))
            return (1);
    }
    return (0);
}

void check_lose(game_t *game, int line)
{
    for (int i = 0; game->map[line][i] != NULL; i++) {
        if (game->map[line][i] == 'X') {
            game->blocked_box += get_adjacent_tiles(game, line, i);
        }
    }
}

int game_lost(game_t *game)
{
    if (game->blocked_box == game->O_nb) {
        mvaddstr(LINES / 2, COLS / 3, \
        "One or more box(es) are blocked. YOU LOST.");
        refresh();
        usleep(4000000);
        return (1);
    }
    return (0);
}

int check_end_condition(game_t *game)
{
    int box_placed_counter = 0;

    for (int i = 0; i < game->O_nb; i++) {
        if (game->map[game->O_pos[i].line][game->O_pos[i].row] == 'X')
            box_placed_counter++;
    }
    if (box_placed_counter == game->O_nb) {
        mvaddstr(LINES / 2, COLS / 2, "YOU WON !GG !");
        refresh();
        usleep(3000000);
        return (1);
    } else {
        game->blocked_box = 0;
        for (int i = 0; game->map[i + 1] != NULL; i++) {
            check_lose(game, i);
        }
    }
    return (game_lost(game));
}