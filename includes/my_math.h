/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:10:28 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/09 13:03:03 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MATH_H
# define MY_MATH_H

# include <math.h>

# define MY_PI 3.14159265358979323846

/* bool type */

typedef enum e_bool
{
	false,
	true
}			t_bool;


t_bool	comp(double a, double b);
double	abs_double(double a);

/* QUADRATIC */

typedef struct s_quad_param
{
	double	a;
	double	b;
	double	c;
}			t_quad_param;

typedef struct s_quad
{
	double	det;

	double	root_a;
	double	root_b;
}			t_quad;

t_quad	quadratic(t_quad_param params);
double	discriminant(double a, double b, double c);

/* POW */

double	dpow(double base, double n);

#endif