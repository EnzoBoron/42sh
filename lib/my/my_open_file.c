/*
** EPITECH PROJECT, 2022
** my_open_file
** File description:
** open a file and return the content
*/

#include "libmy.h"

char *my_open_file(char const *filepath)
{
    int fd = 0;
    int size = 0;
    char *buffer = malloc(sizeof(char) * 4050);

    if (buffer == NULL || filepath == NULL) {
        free(buffer);
        return (NULL);
    }
    fd = open(filepath, O_RDONLY);
    size = read(fd, buffer, 4050);
    if (fd == -1 || size == -1) {
        free(buffer);
        return (NULL);
    }
    buffer[size] = '\0';
    close(fd);
    return (buffer);
}
