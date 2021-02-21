/*
** EPITECH PROJECT, 2021
** malloc [WSL: Ubuntu]
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
    new_addr = ((size_t) *last - (*last)->size - sizeof(meta_t)) & -4;
    if ((size_t) new_addr - sizeof(meta_t) - size <= (size_t) current_brk)
        return NULL;
    new_addr->size = size;
    new_addr->next = NULL;
    new_addr->previous = *last;
    (*last)->next = new_addr;
    return new_addr;
}