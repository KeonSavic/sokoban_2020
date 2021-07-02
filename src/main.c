/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "my.h"
#include "sokoban.h"

void display_usage(void)
{
    my_putstr("USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap file ");
    my_putstr("representing the warehouse map, containing '#' for walls, 'P' ");
    my_putstr("for the player, 'X' for boxes and 'O' for storage locations");
}

int main(int argc, char **argv)
{
    char *buff = NULL;
    game_t *game = malloc(sizeof(game_t *));

    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        display_usage();
        return (0);
    } else if (check_error(argc, argv, &buff) == 1)
        return (84);
    init_sokoban(game, buff);
    my_sokoban(game);
    return (0);
}