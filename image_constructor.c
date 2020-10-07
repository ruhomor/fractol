/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:28:14 by kachiote          #+#    #+#             */
/*   Updated: 2020/10/08 01:29:08 by Ruslan           ###   ########.fr       */
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

t_complex	c_multiply(t_complex a, t_complex b)
{
	t_complex	res;

	res.re = a.re * b.re - a.im * b.im;
	res.im = a.re * b.im + a.im * b.re;
	return (res);
}

void		mandelbrot(t_pxl *pxl, t_complex c)
{
	size_t		iters;
	t_complex	z;
	t_complex	tmp;

	iters = 0;
	c.im *= pxl->y;
	c.re *= pxl->x;
	while ((z.re * z.re + z.im * z.im < 4) && (iters < MAXITERS))
	{
		tmp.re = z.re * z.re - z.im * z.im + c.re;
		tmp.im = 2 * z.re * z.im + c.im;
		if (z.re == tmp.re && z.im == tmp.im)
		{
			iters = MAXITERS;
			break;
		}
		iters++;
	}
	pxl->color = colorfonk(iters);
}

t_color	colorfonk(size_t iters)
{
	double	t;
	t_color	color;

	t = iters / MAXITERS;

	color.r = (int)(9 * (1 - t) * t * t * t * 255);
	color.g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	color.b = (int)(8.5 * (1 - t) * (1 - t) * ( 1 - t ) * t * 255);
	return (color);
}

void	fill_if(t_image *image, t_frac frac, void (*f)(t_pxl*, t_complex))
{
	t_pxl		pxl;
	size_t		i;
	size_t		j;
	t_complex	d;

	i = 0;
	d.re = (frac.lt.re - frac.rb.re) / WINX;
	d.im = (frac.rb.im - frac.lt.im) / WINY;
	while (i < WINX)
	{
		j = 0;
		pxl.x = i;
		while (j < WINY)
		{
			pxl.y = j;
			/*
			if ((*f)(&pxl, d) != 0)
				set_pxl(image, pxl);
			*/
			(*f)(&pxl, d);
			set_pxl(image, pxl);
			j++;
		}
		i++;
	}
}

void 	fill(t_image *image, t_color color)
{
	t_pxl 	pxl;
	size_t 	i;
	size_t 	j;

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
	printf("x:%zu y:%zu", i, j);
}

void	construct_mandelbrot(void *mlx_ptr, t_image **image)
{
	t_color 	color;
	t_frac		frac;

	color.r = 125;
	color.g = 125;
	color.b = 255;
	if (!(*image))
		*image = init_image(mlx_ptr);
	printf("gav");
	frac.lt.re = -2;
	frac.lt.im = 1;
	frac.rb.re = 1;
	frac.lt.im = -1;
	fill_if(*image, frac, &mandelbrot);
//	fill(*image, color);
	//wtf?
}
