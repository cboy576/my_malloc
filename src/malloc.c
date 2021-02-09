/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <stdio.h>
#include <assert.h>
#include <unistd.h>

#include "my_malloc.h"

meta_t *get_block_ptr(void *ptr)
{
    return (meta_t *) ptr - 1;
}

static meta_t *find_free_block(meta_t **last, size_t size, meta_t *current)
{
    while (current && !(current->free && current->size >= size)) {
        *last = current;
        current = current->next;
    }
    return current;
}

static meta_t *request_space(meta_t *last, size_t size)
{
    meta_t *block = sbrk(0);
    void *request = sbrk(size + sizeof(meta_t));

    assert((void *)block == request);
    if (request == (void *) -1)
        return NULL;

    if (last)
        last->next = block;
    block->size = size;
    block->next = NULL;
    block->free = 0;
    return block;
}

static int add_new_block(meta_t **last, size_t size,
    void *base, meta_t **block)
{
    *block = find_free_block(last, size, base);
    if (!*block) {
        *block = request_space(*last, size);
        if (!*block)
            return 1;
    }
    else
        (*block)->free = 0;
    return 0;
}

void *malloc(size_t size)
{
    static void *base = NULL;
    meta_t *block = NULL;
    meta_t *last = base;

    if (!base) {
        block = request_space(NULL, size);
        if (!block)
            return NULL;
        base = block;
    }
    else
        if (add_new_block(&last, size, base, &block))
            return NULL;
    return block + 1;
}