/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** free
*/

#include <assert.h>

#include "my_malloc.h"

void free(void *ptr)
{
    meta_t *block_ptr = NULL;

    if (!ptr)
        return;
    block_ptr = get_block_ptr(ptr);
    assert(block_ptr->free == 0);
    block_ptr->free = 1;
}