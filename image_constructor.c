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

char	*construct_image(t_window *meme, char fractal)
{
	char	*im_ptr;

	im_ptr = (char*)mlx_new_image(meme->mlx_ptr, WINX, WINY);
	if (fractal == 'a')
		mandelbrot(&im_ptr);
	if (fractal == 'b')
		julia(&im_ptr);

	return (im_ptr);
}
