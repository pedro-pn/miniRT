/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:43:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/09 23:11:00 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

# include <math.h>



/* TUPLE */

typedef struct s_t3d
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_t3d;

typedef t_t3d	t_p3d;

t_t3d	tuple_3d(double x, double y, double z, double w);
t_p3d	point(double x, double y , double z);


/* OPERATIONS */

t_t3d	add(t_t3d t1, t_t3d t2);
t_t3d	sub(t_t3d t1, t_t3d t2);
t_t3d	neg(t_t3d tuple);
t_t3d	scalar_times(double scalar, t_t3d tuple);
t_t3d	scalar_div(double scalar, t_t3d tuple);

/* Vectors */

typedef t_t3d	t_v3d;

t_v3d	vector(double x, double y , double z);
t_v3d	normalize(t_v3d vector);
t_v3d	cross(t_v3d v1, t_v3d v2);
double	magnitude(t_v3d vector);
double	dotp(t_v3d v1, t_v3d v2);

/* COLORS */

typedef t_t3d	t_c3d;

t_c3d	tcolor(double red, double green, double blue);
t_c3d	haddamard(t_c3d c1, t_c3d c2);

#endif