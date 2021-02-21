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

static void *forward_brk(size_t size)
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

//if (base)
//   return find_free_block(&last, size, base);
// To add after the NULL request check, to correctly implement Best Fit
// Currently ain't working for whatever god damn dark magic reason
static meta_t *request_space(meta_t *last, size_t size, meta_t *base)
{
    meta_t *request = forward_brk(size);

    if (request == NULL)
        return NULL;
    if (last)
        last->next = request;
    request->size = size;
    request->next = NULL;
    request->previous = last;
    request->free = 0;
    return request;
}

static int add_new_block(meta_t **last, size_t size,
    void *base, meta_t **block)
{
    *block = find_free_block(last, size, base);
    if (!*block) {
        *block = request_space(*last, size, base);
        if (!*block)
            return 1;
    }
    (*block)->free = 0;
    return 0;
}

void *malloc(size_t size)
{
    static void *base = NULL;
    meta_t *block = NULL;
    meta_t *last = base;

    if (!base) {
        block = request_space(NULL, size, NULL);
        if (!block)
            return NULL;
        base = block;
    } else if (add_new_block(&last, size, base, &block))
        return NULL;
    return block + 1;
}