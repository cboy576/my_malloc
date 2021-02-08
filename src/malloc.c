/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#include <unistd.h>

#include "malloc.h"

void *malloc(size_t size)
{
    return sbrk(size);
}