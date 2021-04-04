/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** find_free_block
*/

#include <unistd.h>

#include "my_malloc.h"

// https://stackoverflow.com/questions/4840410/how-to-align-a-pointer-in-c
// Is this the norm ?
// idk
meta_t *find_free_block(meta_t **last, size_t size, meta_t *current)
{
    meta_t *new_addr = NULL;
    const void *current_brk = sbrk(0);
    meta_t *found_ptr = NULL;

    while (current) {
        if (current->free && current->size >= size &&
            (!found_ptr || current->size < found_ptr->size))
            found_ptr = current;
        *last = current;
        current = current->next;
    }
    if (found_ptr)
        return found_ptr;
    new_addr = (meta_t *)
        ((((size_t) *last + (*last)->size + sizeof(meta_t)) + 7) & -8);
    if ((size_t) new_addr + sizeof(meta_t) + size >= (size_t) current_brk)
        forward_brk(size);
    new_addr->size = size;
    new_addr->next = NULL;
    (*last)->next = new_addr;
    return new_addr;
}