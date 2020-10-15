/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:56:24 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/15 17:57:40 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_in(t_frac *frac, int curx, int cury)
{
	t_complex	d;

	d.re = curx * frac->d.re * (1 - 1 / ZOOMMUL);
	d.im = cury * frac->d.im * (1 - 1 / ZOOMMUL);
	frac->lt.re += d.re;
	frac->rb.re += d.re;
	frac->lt.im += d.im;
	frac->rb.im += d.im;
	frac->d.im /= ZOOMMUL;
	frac->d.re /= ZOOMMUL;
}

void	zoom_out(t_frac *frac, int curx, int cury)
{
	t_complex	d;

	d.re = curx * frac->d.re * (1 - 1 / ZOOMDIV);
	d.im = cury * frac->d.im * (1 - 1 / ZOOMDIV);
	frac->lt.re += d.re;
	frac->rb.re += d.re;
	frac->lt.im += d.im;
	frac->rb.im += d.im;
	frac->d.im /= ZOOMDIV;
	frac->d.re /= ZOOMDIV;
}
