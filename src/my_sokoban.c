/*
** EPITECH PROJECT, 2021
** my sokoban
** File description:
** my sokoban game
*/

#include "my.h"
#include "sokoban.h"

void rewrite_Os(game_t *game)
{
    for (int i = 0; i < game->O_nb; i++) {
        if (game->map[game->O_pos[i].line][game->O_pos[i].row] == ' ')
            game->map[game->O_pos[i].line][game->O_pos[i].row] = 'O';
    }
}

void check_terminal_size(game_t *game)
{
    int x = 0;
    int y = 0;

    getmaxyx(stdscr, y, x);
    if (y < game->max_row || x < game->max_line) {
        clear();
        refresh();
        game->pause = 1;
        mvaddstr(LINES/2, COLS/2, "Please enlarge the terminal.");
    } else {
        if (game->pause == 1)
            clear();
        game->pause = 0;
    }
}

void get_player_pos(game_t *game)
{
    int j = 0;

    for (int i = 0; game->map[i] != NULL; i++) {
        for (j = 0; game->map[i][j] != '\0' && game->map[i][j] != 'P'; j++);
        if (game->map[i][j] != '\0') {
            game->P_line = i;
            game->P_row = j;
            break;
        }
    }
}

void game_loop(game_t *game)
{
    int ch = 0;

    while (game->over == 0) {
        check_terminal_size(game);
        rewrite_Os(game);
        if ((ch = getch()) != ERR) {
            handle_key_press(game, ch);
        }
        for (int i = 0; game->map[i] != NULL && game->pause != 1; i++) {
            mvaddstr(game->cursor_row, game->cursor_line, game->map[i]);
            game->cursor_row++;
        }
        game->cursor_row = 0;
        refresh();
        game->over = check_end_condition(game);
    }
}

int my_sokoban(game_t *game)
{
    launch_window_prep(game);
    game_loop(game);
    endwin();
    delwin(stdscr);
    return (0);
}