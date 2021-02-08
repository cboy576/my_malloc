/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** calloc
*/

#include <string.h>

#include "my_malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    size_t size_total = nmemb * size;
    void *ptr = malloc(size_total);

    memset(ptr, 0, size_total);
    return ptr;
}