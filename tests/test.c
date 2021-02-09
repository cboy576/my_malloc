/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** test
*/

#include <assert.h>

#include "my_malloc.h"

int main(void)
{
    assert(malloc(100));
    assert(realloc(NULL, 100));
    free(malloc(50));
    assert(malloc(100000));
    return 0;
}