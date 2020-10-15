/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:28:14 by kachiote          #+#    #+#             */
/*   Updated: 2020/10/15 18:17:09 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image			*init_image(void *mlx_ptr)
{
	t_image		*image;

	image = (t_image*)malloc(sizeof(*image));
	image->img_ptr = mlx_new_image(mlx_ptr, WINX, WINY);
	image->img_data = mlx_get_data_addr(image->img_ptr, &(image->bpp),
			&(image->size_line), &(image->endian));
	return (image);
}

void			destroy_image(void *mlx_ptr, t_image *image)
{
	mlx_destroy_image(mlx_ptr, image->img_ptr);
	free(image);
	image = NULL;
}

void			set_pxl(t_image *image, t_pxl pxl)
{
	char		*map;

	map = image->img_data + pxl.x * (image->bpp / 8) + pxl.y * image->size_line;
	*map++ = pxl.color.r;
	*map++ = pxl.color.g;
	*map++ = pxl.color.b;
	*map = pxl.color.alpha;
}

void			fill_if(t_image *image, t_frac frac, void (*f)(t_pxl*, t_frac))
{
	t_pxl		pxl;
	int			i;
	int			j;

	i = 0;
	while (i < WINX)
	{
		j = 0;
		pxl.x = i;
		while (j < WINY)
		{
			pxl.y = j;
			(*f)(&pxl, frac);
			set_pxl(image, pxl);
			j++;
		}
		i++;
	}
}

void			construct_fractal(void *mlx_ptr, t_window *meme)
{
	t_frac		*frac;
	t_image		**image;

	image = meme->img;
	frac = meme->frac;
	if (!(*image))
		*image = init_image(mlx_ptr);
	if (meme->frac->id == 1)
		fill_if(*image, *frac, &julia);
	else if (meme->frac->id == 0)
		fill_if(*image, *frac, &mandelbrot);
	else if (meme->frac->id == 2)
		fill_if(*image, *frac, &burningship);
	mlx_put_image_to_window(meme->mlx_ptr,
			meme->win_ptr, (*image)->img_ptr, 0, 0);
}
