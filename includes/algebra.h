/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:43:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/03 16:55:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

typedef struct s_t3d
{
    double  x;
    double  y;
    double  z;
    double  w;
}           t_t3d;

/* TUPLE */

t_t3d   tuple_3d(double x, double y, double z, double w);

#endif