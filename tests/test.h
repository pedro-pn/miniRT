#ifndef TEST_H
# define TEST_H
 
# include "minunit.h"
# include "minirt.h"
# include <stdio.h>


void    mu_assert_tuple_eq(t_t3d expected, t_t3d result)
{
    mu_assert_double_eq(expected.x, result.x);
    mu_assert_double_eq(expected.y, result.y);
    mu_assert_double_eq(expected.z, result.z);
    mu_assert_double_eq(expected.w, result.w);
}

#endif

