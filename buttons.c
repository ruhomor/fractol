/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:51:59 by kachiote          #+#    #+#             */
/*   Updated: 2020/10/15 16:52:27 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
t_point				ft_xy(int x, int y)
{
	static t_point point0;
	static t_point point;

	point = point0;
	point0.x = x;
	point0.y = y;
	return (point);
}
*/
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
	printf("k.re: %f k.im: %f\n", k.re, k.im);
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
		//ft_xy(x, y);
	}
	if (button == 4)
	{
		printf("\ninnn");
		//meme->frac->zoom *= ZOOMMUL;
		meme->frac->maxiter += ITERD;
		zoom_in(meme->frac, x, y);
		mlx_clear_window(meme->mlx_ptr, meme->win_ptr);
		construct_fractal(meme->mlx_ptr, meme);
	}
	if (button == 5)
	{
		printf("\nout");
		//meme->frac->zoom *= ZOOMDIV;
		meme->frac->maxiter -= ITERD;
		zoom_out(meme->frac, x, y);
		mlx_clear_window(meme->mlx_ptr, meme->win_ptr);
		construct_fractal(meme->mlx_ptr, meme);
	}
	return (0);
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
	{
	//	meme->prjk += 1;
	//	meme->prjk %= 2;
	}
	meme->shift.x +=
			meme->shift.r_flag + meme->shift.l_flag;
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
