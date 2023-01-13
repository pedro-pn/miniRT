/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:43:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/13 12:46:35 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGEBRA_H
# define ALGEBRA_H

# include "my_math.h"
# include "libft.h"

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
t_t3d	null_tuple(void);


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
void		mx_copy(t_matrix matrix, t_matrix *result);
void		mx_identity(t_matrix *matrix);
void		mx_switch_rows(t_matrix *matrix, int row_1, int row_2);
void		mx_switch_columns(t_matrix *matrix, int column_1, int column_2);
t_bool		matrix_compare(t_matrix mx1, t_matrix mx2);
t_row		mx_get_row(t_matrix mx, int i);
t_column	mx_get_column(t_matrix mx, int j);
void		mx_submatrix(t_matrix mx, int row, int column, t_matrix *result);

/* MATRIX OPERATIONS */

void	mx_transpose(t_matrix matrix, t_matrix *result);
void	mx_product(t_matrix mx1, t_matrix mx2, t_matrix *result);
t_t3d	mx_tuple_product(t_matrix mx, t_t3d tuple);

// determinant
double	mx_2by2_determinant(t_matrix matrix);
double	mx_minor(t_matrix matrix, int row, int column);
double	mx_3by3_cofactor(t_matrix matrix, int row, int column);
double	mx_determinant(t_matrix matrix, int size);
double	mx_cofactor(t_matrix matrix, int size, int row, int column);

// inverse

t_bool	mx_is_invertible(t_matrix matrix, int size);
void	mx_inverse(t_matrix matrix, t_matrix *result);

/* TRANSFORMATION */

typedef struct s_shearing
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
}			t_shearing;

void	translation(t_v3d direction, t_matrix *transform);
void	scaling(t_v3d direction, t_matrix *transform);
void	rotation_x(double ang, t_matrix *result);
void	rotation_y(double ang, t_matrix *result);
void	rotation_z(double ang, t_matrix *result);
void	shearing(t_shearing shear, t_matrix *result);

/* TO DELETE*/

void	inspect_matrix(t_matrix matrix);

#endif