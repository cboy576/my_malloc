#include <criterion/criterion.h>

Test(sample, is_gonna_pass)
{
    cr_assert(1);
}

Test(sample, is_not_gonna_pass)
{
    cr_assert(0);
}