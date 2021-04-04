/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** find_free_block
*/

#include <unistd.h>

#include "my_malloc.h"

// https://stackoverflow.com/questions/4840410/how-to-align-a-pointer-in-c
meta_t *find_free_block(meta_t **last, size_t size, meta_t *current)
{
    meta_t *new_addr = NULL;
    const void *current_brk = sbrk(0);

    while (current && !(current->free && current->size >= size)) {
        *last = current;
        current = current->next;
    }
    if (current)
        return current;
    new_addr = (meta_t *)
        ((((size_t) *last + (*last)->size + sizeof(meta_t)) + 7) & -8);
    if ((size_t) new_addr + sizeof(meta_t) + size >= (size_t) current_brk)
        forward_brk(size);
    new_addr->size = size;
    new_addr->next = NULL;
    (*last)->next = new_addr;
    return new_addr;
}