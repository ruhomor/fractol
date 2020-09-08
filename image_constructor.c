/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:28:14 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/07 20:28:16 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_image 		*init_image(void *mlx_ptr)
{
	t_image 	*image;

	image = (t_image*)malloc(sizeof(*image));
	image->img_ptr = mlx_new_image(mlx_ptr, WINX, WINY);
	image->img_data = mlx_get_data_addr(image->img_ptr, &image->bpp, 
			&image->endian, &image->size_line);
}

void 	set_pxl(char *img_data, int line_size, t_pxl pxl)
{
	img_data += pxl.x * 4 + 4 * line_size * pxl.y
	img_data++ = pxl.color.r;
	img_data++ = pxl.color.g;
	img_data++ = pxl.color.b;
	img_data = pxl.color.alpha;
}

char	*construct_mandelbrot(void *mlx_ptr, t_image *image)
{
	if (!(image))
		image = init_image(mlx_ptr);
	//wtf?
	return (im_ptr);
}
