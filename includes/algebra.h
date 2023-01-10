/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:43:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/10 16:10:03 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

# include "my_math.h"

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

/* MATRIX */

typedef double t_matrix[4][4];

typedef struct s_set_matrix
{
	double	a1;
	double	a2;
	double	a3;
	double	a4;

	double	b1;
	double	b2;
	double	b3;
	double	b4;

	double	c1;
	double	c2;
	double	c3;
	double	c4;

	double	d1;
	double	d2;
	double	d3;
	double	d4;
}			t_set_matrix;

typedef union u_set_matrix_aux
{
	t_set_matrix		set;
	double				values[16];
}			t_set_matrix_aux;

typedef t_t3d	t_row;
typedef t_t3d	t_column;

void		set_matrix(t_matrix *matrix, t_set_matrix set_mx);
void		mx_identity(t_matrix *matrix);
t_bool		matrix_compare(t_matrix mx1, t_matrix mx2);
t_row		mx_get_row(t_matrix mx, int i);
t_column	mx_get_column(t_matrix mx, int j);

/* MATRIX OPERATIONS */

void	mx_transpose(t_matrix matrix, t_matrix *result);
void	mx_product(t_matrix mx1, t_matrix mx2, t_matrix *result);
t_t3d	mx_tuple_product(t_matrix mx, t_t3d tuple);

#endif