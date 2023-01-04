/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:48:39 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/04 00:46:34 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_t3d   tuple_3d(double x, double y, double z, double w)
{
    t_t3d   tuple;

    tuple.x = x;
    tuple.y = y;
    tuple.z = z;
    tuple.w = w;
    return (tuple);
}
