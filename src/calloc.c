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
    const size_t size_total = nmemb * size;
    void *ptr = NULL;

    if (size_total / size != nmemb)
        return NULL;
    ptr = malloc(size_total);
    memset(ptr, 0, size_total);
    return ptr;
}