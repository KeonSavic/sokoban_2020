/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** task 03
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return (count);
}