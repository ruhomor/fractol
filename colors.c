/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ruslan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:09:25 by Ruslan            #+#    #+#             */
/*   Updated: 2020/10/15 18:18:53 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_color	colorfonker(int iters)
{
	double	t;
	t_color	color;

	t = (double)iters / MAXITERS;
	color.r = (int)(9 * (1 - t) * t * t * t * 255);
	color.g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	color.b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
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
	color.b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	color.alpha = 0;
	return (color);
}
