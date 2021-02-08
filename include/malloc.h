/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <stddef.h>

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif /* !MALLOC_H_ */
