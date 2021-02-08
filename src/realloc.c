/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** realloc
*/

#include <string.h>

#include "my_malloc.h"

void *realloc(void *ptr, size_t size)
{
    void *new_ptr = NULL;
    meta_t *block_ptr = NULL;

    if (!ptr)
        return malloc(size);
    block_ptr = get_block_ptr(ptr);
    if (block_ptr->size >= size)
        return ptr;
    new_ptr = malloc(size);
    if (!new_ptr)
        return NULL;
    memcpy(new_ptr, ptr, block_ptr->size);
    free(ptr);
    return new_ptr;
}