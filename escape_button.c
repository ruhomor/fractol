/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_button.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:24:06 by kachiote          #+#    #+#             */
/*   Updated: 2020/10/15 17:26:28 by Ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				escape_butt(t_window *meme)
{
	if (meme)
	{
		if (meme->win_ptr != NULL)
		{
			if (meme->img && *(meme->img))
				destroy_image(meme->mlx_ptr, *(meme->img));
			mlx_destroy_window(meme->mlx_ptr, meme->win_ptr);
		}
		free(meme);
		meme = NULL;
	}
	exit(0);
}
