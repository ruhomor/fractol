/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:28:14 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/22 00:28:56 by kachiote         ###   ########.fr       */
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

int		mandelbrot(t_pxl pxl)
{

	pxl_to_c();
}

void 	fill_complex(t_image *image, t_color (*f)(t_complex))
{
	t_complex	c;
	size_t		i;
	size_t		j;
	t_color		color;

	j = 0;
	while (j < WINY)
	{
		i = 0;
		while (i < WINX)
		{						//TODO fractal struct borders and coords to complex number
			color = f(c);
			set_pixel(image, j, i, color);
			i++;
		}
		j++;
	}
}

void 	fill_if(t_image *image, t_color color, int (*f)(t_pxl))
{
	t_pxl 	pxl;
	size_t 	i;
	size_t 	j;

	i = 0;
	pxl.color = color;
	while (i < WINY)
	{
		j = 0;
		pxl.x = i;
		while (j < WINX)
		{
			pxl.y = j;
			if ((*f)(pxl))
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

	color.r = 125;
	color.g = 125;
	color.b = 255;
	if (!(*image))
		*image = init_image(mlx_ptr);
	//fill_if(*image, color, even);
	fill(*image, color);
	//wtf?
}
