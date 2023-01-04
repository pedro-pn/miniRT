/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:04:32 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/04 11:32:27 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double  abs_double(int a)
{
    if (a < 0)
        return (-a);
    return (a);
}

t_bool    comp(double a, double b)
{
    double  diff;

    diff = abs_double(a) - abs_double(b);
    if (abs_double(diff) < EPSILON)
        return (true);
    return (false);
}