/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc
*/

#ifndef MALLOC_H_
    #define MALLOC_H_

    #include <stddef.h>

    typedef struct meta_s {
        size_t size;
        int free;
        struct meta_s *next;
    } meta_t;

    meta_t *find_free_block(meta_t **last, size_t size, meta_t *current);
    meta_t *get_block_ptr(void *ptr);
    void *forward_brk(size_t size);

    void *malloc(size_t size);
    void free(void *ptr);
    void *calloc(size_t nmemb, size_t size);
    void *realloc(void *ptr, size_t size);
    void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif /* !MALLOC_H_ */
