/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:51:59 by kachiote          #+#    #+#             */
/*   Updated: 2020/10/15 17:58:30 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					mouse_move(int x, int y, void *p)
{
	t_complex	k;
	t_window	*meme;

	meme = (t_window*)p;
	if (meme->frac->id != 1)
		return (0);
	k.re = -0.702693;
	k.im = -0.384201;
	meme->frac->k.re = k.re - (6.28 * x * k.re) / WINX;
	meme->frac->k.im = k.im - (3.14 * y * k.im) / WINY;
	construct_fractal(meme->mlx_ptr, meme);
	return (0);
}

int					mouse_press(int button, int x, int y, void *p)
{
	t_window *meme;

	meme = (t_window *)p;
	if (button == 1)
	{
		meme->drag_flag = 1;
	}
	if (button == 4)
	{
		meme->frac->maxiter += ITERD;
		zoom_in(meme->frac, x, y);
		mlx_clear_window(meme->mlx_ptr, meme->win_ptr);
		construct_fractal(meme->mlx_ptr, meme);
	}
	if (button == 5)
	{
		meme->frac->maxiter -= ITERD;
		zoom_out(meme->frac, x, y);
		mlx_clear_window(meme->mlx_ptr, meme->win_ptr);
		construct_fractal(meme->mlx_ptr, meme);
	}
	return (0);
}

int					mouse_release(int button, int x, int y, void *p)
{
	t_window *meme;

	x++;
	x--;
	y++;
	y--;
	meme = (t_window *)p;
	if (button == 1)
		meme->drag_flag = 0;
	return (0);
}

int					key_press1(int keycode, void *p)
{
	t_window *meme;

	meme = (t_window *)p;
	kph(keycode, meme);
	if (keycode == 35)
		meme->shift.x += meme->shift.r_flag + meme->shift.l_flag;
	meme->shift.y += meme->shift.u_flag + meme->shift.d_flag;
	mlx_clear_window(meme->mlx_ptr, meme->win_ptr);
	construct_fractal(meme->mlx_ptr, meme);
	return (0);
}

int					key_release1(int keycode, void *p)
{
	t_window *meme;

	meme = (t_window *)p;
	if (keycode == 126)
		meme->shift.u_flag = (meme->shift.u_flag == -1) ? 0 : 1;
	if (keycode == 125)
		meme->shift.d_flag = (meme->shift.d_flag == 1) ? 0 : -1;
	if (keycode == 124)
		meme->shift.r_flag = (meme->shift.r_flag == 1) ? 0 : -1;
	if (keycode == 123)
		meme->shift.l_flag = (meme->shift.l_flag == -1) ? 0 : 1;
	return (0);
}
