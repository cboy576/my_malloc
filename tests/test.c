#include <assert.h>

#include "my_malloc.h"

int main()
{
    assert(malloc(100));
    assert(realloc(NULL, 100));
    free(malloc(50));
    assert(malloc(100000));
    return 0;
}