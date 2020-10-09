/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:51:59 by kachiote          #+#    #+#             */
/*   Updated: 2020/10/09 19:03:29 by Ruslan           ###   ########.fr       */
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

int					mouse_move(int x, int y, void *p)
{
	t_window	*meme;
	t_point		point;
	double		da;
	double		db;

	meme = (t_window*)p;
	point = ft_xy(x, y);
	db = (point.x != 0) ? (double)(x - point.x) / point.x : 0;
	da = (point.y != 0) ? (double)(y - point.y) / point.y : 0;
	if (meme->drag_flag == 1)
	{
		//meme->angle.a += da;
		//meme->angle.b += db;
		mlx_clear_window(meme->mlx_ptr, meme->win_ptr);
		//drawmap(meme);
	}
	return (0);
}
*/
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
		meme->frac->zoom *= ZOOMMUL;
		meme->frac->maxiter += ITERD;
		zoom_in(meme->frac, x, y);
		mlx_clear_window(meme->mlx_ptr, meme->win_ptr);
		construct_fractal(meme->mlx_ptr, meme);
	}
	if (button == 5)
	{
		printf("\nout");
		meme->frac->zoom /= ZOOMDIV;
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

	d.re = curx * frac->d.re * (1 - 1 / frac->zoom);
	d.im = cury * frac->d.im * (1 - 1 / frac->zoom);

	frac->lt.re -= d.re;
	frac->rb.re -= d.re;
	frac->lt.im -= d.im;
	frac->rb.im -= d.im;
	frac->d.im /= frac->zoom;
	frac->d.re /= frac->zoom;
}

void	zoom_in(t_frac *frac, int curx, int cury)
{
	t_complex	d;

	d.re = curx * frac->d.re * (1 - 1 / frac->zoom);
	d.im = cury * frac->d.im * (1 - 1 / frac->zoom);

	frac->lt.re += d.re;
	frac->rb.re += d.re;
	frac->lt.im += d.im;
	frac->rb.im += d.im;
	frac->d.im /= frac->zoom;
	frac->d.re /= frac->zoom;
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
