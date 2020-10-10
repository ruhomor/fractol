/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:28:14 by kachiote          #+#    #+#             */
/*   Updated: 2020/10/09 22:36:19 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image 		*init_image(void *mlx_ptr)
{
	t_image 	*image;

	image = (t_image*)malloc(sizeof(*image));
	image->img_ptr = mlx_new_image(mlx_ptr, WINX, WINY);
	image->img_data = mlx_get_data_addr(image->img_ptr, &(image->bpp),
			&(image->size_line), &(image->endian));
	return (image);
}

void 			destroy_image(void *mlx_ptr, t_image *image)
{
	mlx_destroy_image(mlx_ptr, image->img_ptr);
	free(image);
	image = NULL;
}

void 	set_pxl(t_image *image, t_pxl pxl)
{
	char 	*map;

	map = image->img_data + pxl.x * (image->bpp / 8) + pxl.y * image->size_line; //+= pxl.x * 4 + 4 * line_size * pxl.y;
	*map++ = pxl.color.r;
	*map++ = pxl.color.g;
	*map++ = pxl.color.b;
	*map = pxl.color.alpha;
}

int 	even(t_pxl pxl)
{
	if (pxl.x % 2 == 0)
		return (1);
	return (0);
}

/*
int 	mandelbrot_set(t_pxl &pxl, t_complex d)
{

}
*/
t_complex	c_add(t_complex a, t_complex b)
{
	t_complex	res;

	res.re = a.re + b.re;
	res.im = a.im + b.im;
	return (res);
}

t_complex	c_multiply(t_complex a, t_complex b)
{
	t_complex	res;

	res.re = a.re * b.re - a.im * b.im;
	res.im = a.re * b.im + a.im * b.re;
	return (res);
}
/*
t_complex	cre_mult(t_complex a, size_t b)
{
	a.re *= b;
	a.im *= b;

	return (a);
}
*/

t_color	colorsimp(int iters)
{
	t_color color;

	if (iters == 1)
	{
		color.r = 200;
		color.g = 100;
		color.b = 100;
	}
	if (iters == 2)
	{
		color.r = 100;
		color.g = 200;
		color.b = 100;
	}
	if (iters == 3)
	{
		color.r = 100;
		color.g = 100;
		color.b = 200;
	}
	color.alpha = 0;
	return (color);
}

t_complex	pxl_to_point(t_pxl pxl, t_complex d, t_frac frac)
{
	d.im *= pxl.y;
	d.re *= pxl.x;
	d.im += frac.lt.im;
	d.re += frac.lt.re;
	return (d);
}

void		mandelbrot(t_pxl *pxl, t_complex c, int max)
{
	int			iters;
	t_complex	z;
	t_complex	tmp;

	iters = 0;
	z.re = 0;
	z.im = 0;
	while ((z.re * z.re + z.im * z.im < 4) && (iters < max))
	{
		tmp.re = z.re * z.re - z.im * z.im + c.re;
		tmp.im = 2 * z.re * z.im + c.im;
		if (z.re == tmp.re && z.im == tmp.im)
		{
			iters = max;
			break;
		}
		z.re = tmp.re;
		z.im = tmp.im;
		iters++;
	}
	pxl->color = colorfonk(iters, max);
}

t_color	colorfonker(int iters, int max)
{
	double	t;
	t_color	color;

	t = (double)iters / (double)max;
	color.r = (int)(9 * (1 - t) * t * t * t * 255);
	color.g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	color.b = (int)(8.5 * (1 - t) * (1 - t) * ( 1 - t ) * t * 255);
	color.alpha = 0;
	return (color);
}

t_color	colorfonk(int iters, int max)
{
	double	t;
	t_color	color;

	t = (double)iters / (double)max;
	color.r = (int)(9 * (1 - t) * t * t * t * 255);
	color.g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	color.b = (int)(8.5 * (1 - t) * (1 - t) * ( 1 - t ) * t * 255);
	color.alpha = 0;
	return (color);
}

void	fill_if(t_image *image, t_frac frac, void (*f)(t_pxl*, t_complex, int))
{
	t_pxl		pxl;
	int			i;
	int			j;

	i = 0;
	printf("d.re:%f d.im:%f", frac.d.re, frac.d.im);
	while (i < WINX)
	{
		j = 0;
		pxl.x = i;
		while (j < WINY)
		{
			pxl.y = j;
			(*f)(&pxl, pxl_to_point(pxl, frac.d, frac), frac.maxiter);
			set_pxl(image, pxl);
			j++;
		}
		i++;
	}
}

void 	fill(t_image *image, t_color color)
{
	t_pxl 	pxl;
	int		i;
	int		j;

	i = 0;
	pxl.color = color;
	while (i < WINX)
	{
		j = 0;
		pxl.x = i;
		while (j < WINY)
		{
			pxl.y = j;
			set_pxl(image, pxl);
			j++;
		}
		i++;
	}
}

void	construct_fractal(void *mlx_ptr, t_window *meme)
{
	t_frac		*frac;
	t_image		**image;

	image = meme->img;
	frac = meme->frac;
	if (!(*image))
		*image = init_image(mlx_ptr);
	//zoom_frac(&frac, pxl);
	//frac->d.re = (frac->rb.re - frac->lt.re) / WINX;
	//frac->d.im = (frac->rb.im - frac->lt.im) / WINY;
	fill_if(*image, *frac, &mandelbrot);
	mlx_put_image_to_window(meme->mlx_ptr, meme->win_ptr, (*image)->img_ptr, 0, 0);
//	fill(*image, color);
	//wtf?
}
