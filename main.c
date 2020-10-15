/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:36:36 by kachiote          #+#    #+#             */
/*   Updated: 2020/10/15 18:46:50 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_frac		initfrac(int a)
{
	t_frac	frac;

	frac.maxiter = MAXITERS;
	frac.zoom = 1;
	if (a == 0)
	{
		frac.id = 0;
		frac.lt.re = -2;
		frac.rb.re = 1;
		frac.lt.im = 1;
		frac.rb.im = -1;
	}
	initfrac2(a, &frac);
	frac.d.re = (frac.rb.re - frac.lt.re) / WINX;
	frac.d.im = (frac.rb.im - frac.lt.im) / WINY;
	return (frac);
}

void		initfrac2(int a, t_frac *frac)
{
	if (a == 2)
	{
		frac->id = 2;
		frac->lt.re = -3;
		frac->rb.re = 1.5;
		frac->lt.im = 1.5;
		frac->rb.im = -1.5;
	}
	else if (a == 1)
	{
		frac->id = 1;
		frac->lt.re = -1.5;
		frac->rb.re = 1.5;
		frac->lt.im = 1;
		frac->rb.im = -1;
		frac->k.re = 2;
		frac->k.im = 2;
	}
}

static void	usage(void)
{
	ft_putstr_fd("usage: ./fractol id[a]\n"
			"0 - mandelbrot\n"
			"1 - julia\n"
			"2 - burning ship\n", 2);
}

int			main(int argc, char **argv)
{
	t_window	*meme;
	t_frac		frac;

	if (argc != 2)
	{
		ft_putstr_fd("fractol: wrond number of arguments\n", 2);
		usage();
		return (0);
	}
	if ((ft_atoi(argv[1]) < 0) || (ft_atoi(argv[1]) > 2))
	{
		ft_putstr_fd("fractol: invalid fractal id\n", 2);
		usage();
		return (0);
	}
	meme = initwindow();
	frac = initfrac(ft_atoi(argv[1]));
	meme->frac = &frac;
	window(meme);
	return (0);
}
