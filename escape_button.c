/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_button.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:24:06 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/07 20:24:11 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				escape_butt(t_window *meme)
{
	if (meme)
	{
		if (meme->win_ptr != NULL)
			mlx_destroy_window(meme->mlx_ptr, meme->win_ptr);
		free(meme);
		meme = NULL;
	}
	exit(0);
}
