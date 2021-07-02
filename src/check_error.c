/*
** EPITECH PROJECT, 2021
** check error
** File description:
** checks if file is invalid, arguments, etc...
*/

#include "my.h"
#include "sokoban.h"

int check_chars(char *buff)
{
    int j = 0;
    char *valid = " \n#XOP";

    for (int i = 0; buff[i] != '\0'; i++) {
        for (j = 0; valid[j] != '\0' && buff[i] != valid[j]; j++);
        if (valid[j] == '\0')
            return (-1);
    }
    return (0);
}

int check_error(int argc, char **argv, char **buff)
{
    int fd = 0;
    struct stat st;

    if (argc != 2)
        return (1);
    fd = open(argv[1], O_RDONLY);
    if (fd == -1 || fd == 0)
        return (1);
    stat(argv[1], &st);
    (*buff) = malloc(sizeof(char) * st.st_size);
    if (read(fd, (*buff), st.st_size) == -1)
        return (1);
    if (check_chars((*buff)) == -1)
        return (1);
    return (0);
}