/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:36:47 by kachiote          #+#    #+#             */
/*   Updated: 2020/10/09 18:49:02 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_window			*initwindow(void)
{
	t_window *meme;

	meme = (t_window *)malloc(sizeof(*meme));
	meme->win_ptr = NULL;
	meme->shift.r_flag = 0;
	meme->shift.l_flag = 0;
	meme->shift.u_flag = 0;
	meme->shift.d_flag = 0;
	meme->zoom = 2;
	return (meme);
}

void				hookhandler(t_window *meme)
{
//	mlx_hook(meme->win_ptr, 6, 0, mouse_move, meme);
	mlx_hook(meme->win_ptr, 4, 0, mouse_press, meme);
	mlx_hook(meme->win_ptr, 5, 0, mouse_release, meme);
	mlx_hook(meme->win_ptr, 2, 0, key_press1, meme);
	mlx_hook(meme->win_ptr, 3, 0, key_release1, meme);
	mlx_loop(meme->mlx_ptr);
}

void				window(t_window *meme)
{
	t_image 	*image;

	image = NULL;
	meme->img = &image;
	meme->mlx_ptr = mlx_init();
	meme->win_ptr = mlx_new_window(meme->mlx_ptr, WINX, WINY, "MEME");
	//drawmap(meme);  // out to draw fractals
	printf("gonna construct\n");
	construct_fractal(meme->mlx_ptr, meme);
//	mlx_put_image_to_window(meme->mlx_ptr, meme->win_ptr, image->img_ptr, 0, 0);
	hookhandler(meme);
}
