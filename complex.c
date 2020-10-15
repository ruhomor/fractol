/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:11:57 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/15 18:19:30 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	c_multiply(t_complex a, t_complex b)
{
	t_complex	res;

	res.re = a.re * b.re - a.im * b.im;
	res.im = a.re * b.im + a.im * b.re;
	return (res);
}

t_complex	c_add(t_complex a, t_complex b)
{
	t_complex	res;

	res.re = a.re + b.re;
	res.im = a.im + b.im;
	return (res);
}

double		ft_fabs(double a)
{
	if (a < 0)
		return (-a);
	return (a);
}

t_complex	pxl_to_point(t_pxl pxl, t_complex d, t_frac frac)
{
	d.im *= pxl.y;
	d.re *= pxl.x;
	d.im += frac.lt.im;
	d.re += frac.lt.re;
	return (d);
}

int			even(t_pxl pxl)
{
	if (pxl.x % 2 == 0)
		return (1);
	return (0);
}
