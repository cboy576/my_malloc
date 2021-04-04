/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** reallocarray
*/

#include "my_malloc.h"

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    const size_t requested_size = nmemb * size;

    if ((requested_size / size) != nmemb)
        return NULL;
    return realloc(ptr, requested_size);
}