/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include "my_malloc.h"

meta_t *get_block_ptr(void *ptr)
{
    return (meta_t *) ptr - 1;
}

// Dark magic is at work here, idk why
static meta_t *request_space(meta_t *last, size_t size)
{
    meta_t *request = forward_brk(size);

    if (request == NULL)
        return NULL;
    if (last)
        last->next = request;
    request->size = size;
    request->next = NULL;
    request->free = 0;
    return request;
}

static void add_new_block(meta_t **last, size_t size,
    void *base, meta_t **block)
{
    *block = find_free_block(last, size, base);
    (*block)->free = 0;
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
    } else
        add_new_block(&last, size, base, &block);
    return block + 1;
}