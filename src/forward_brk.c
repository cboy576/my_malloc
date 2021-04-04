/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** forward_brk
*/

#include <assert.h>
#include <unistd.h>

#include "my_malloc.h"

void *forward_brk(size_t size)
{
    meta_t *block = sbrk(0);
    const size_t page_size = (size_t) sysconf(_SC_PAGESIZE);
    const size_t block_size = size + sizeof(meta_t);
    void *request = sbrk(block_size + page_size * 2 -
        block_size % (page_size * 2));

    assert((void *)block == request);
    if (request == (void *) -1)
        return NULL;
    return request;
}