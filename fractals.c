/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:06:50 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/15 18:20:12 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		mandelbrot(t_pxl *pxl, t_frac frac)
{
	int				iters;
	t_complex		z;
	t_complex		tmp;
	const t_complex	c = pxl_to_point(*pxl, frac.d, frac);

	iters = 0;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re + z.im * z.im < 4) && (iters < frac.maxiter))
	{
		tmp.re = z.re * z.re - z.im * z.im + c.re;
		tmp.im = 2 * z.re * z.im + c.im;
		if (z.re == tmp.re && z.im == tmp.im)
		{
			iters = frac.maxiter;
			break ;
		}
		z.re = tmp.re;
		z.im = tmp.im;
		iters++;
	}
	pxl->color = colorfonk(iters, frac.maxiter);
}

void		julia(t_pxl *pxl, t_frac frac)
{
	int				iters;
	t_complex		z;
	t_complex		tmp;
	const t_complex	k = frac.k;
	const t_complex	c = pxl_to_point(*pxl, frac.d, frac);

	iters = 0;
	z.re = k.re + c.re;
	z.im = k.im + c.im;
	while ((z.re * z.re + z.im * z.im < 32) && (iters < frac.maxiter))
	{
		tmp.re = z.re * z.re - z.im * z.im + k.re;
		tmp.im = 2 * z.re * z.im + k.im;
		if (z.re == tmp.re && z.im == tmp.im)
		{
			iters = frac.maxiter;
			break ;
		}
		z.re = tmp.re;
		z.im = tmp.im;
		iters++;
	}
	pxl->color = colorfonk(iters, frac.maxiter);
}

void		burningship(t_pxl *pxl, t_frac frac)
{
	int				iters;
	t_complex		z;
	t_complex		tmp;
	const t_complex	c = pxl_to_point(*pxl, frac.d, frac);

	iters = 0;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re + z.im * z.im < 4) && (iters < frac.maxiter))
	{
		tmp.re = z.re * z.re - z.im * z.im + c.re;
		tmp.im = -2 * ft_fabs(z.re * z.im) + c.im;
		if (z.re == tmp.re && z.im == tmp.im)
		{
			iters = frac.maxiter;
			break ;
		}
		z.re = tmp.re;
		z.im = tmp.im;
		iters++;
	}
	pxl->color = colorfonk(iters, frac.maxiter);
}
