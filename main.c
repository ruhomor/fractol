/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:36:36 by kachiote          #+#    #+#             */
/*   Updated: 2020/10/09 18:49:42 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_frac	initfrac(int a)
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
	else if (a == 1)
	{
		frac.id = 1;
		frac.lt.re = -1.5;
		frac.rb.re = 1.5;
		frac.lt.im = 1;
		frac.rb.im = -1;
	}
	frac.d.re = (frac.rb.re - frac.lt.re) / WINX;
	frac.d.im = (frac.rb.im - frac.lt.im) / WINY;
	/*
	else if (a == 2)
	{
		frac.name = "burningship";
	}
	*/
	return (frac);
}

int		main(int argc, char **argv)
{
	t_window	*meme;
	t_frac		frac;

	if (argc != 2)
	{
		ft_putstr_fd("fractol: wrond number of arguments\n", 2);
		return (0);
	}
	printf("initwindow\n");
	meme = initwindow();
	printf("initfrac\n");
	frac = initfrac(ft_atoi(argv[1]));
	meme->frac = &frac;
	printf("window\n");
	//readmap(map, argv[1], meme);
	//initmap(map, argv[1], meme);
	window(meme);
	return (0);
}
