/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button_binds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:00:24 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/07 20:00:26 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				kph(int keycode, t_window *meme)
{
	if (keycode == 126)
		meme->shift.u_flag = (meme->shift.u_flag == 1) ? 0 : -1;
	if (keycode == 125)
		meme->shift.d_flag = (meme->shift.d_flag == -1) ? 0 : 1;
	if (keycode == 124)
		meme->shift.r_flag = (meme->shift.r_flag == -1) ? 0 : 1;
	if (keycode == 123)
		meme->shift.l_flag = (meme->shift.l_flag == 1) ? 0 : -1;
//	if (keycode == 69)
//		meme->attitude += 1;
//	if (keycode == 78)
//		meme->attitude -= 1;
	if (keycode == 53)
		escape_butt(meme);
//	if (keycode == 18)
//		meme->renmod = 1;
//	if (keycode == 19)
//		meme->renmod = 2;
//	if (keycode == 20)
//		meme->renmod = 3;
//	if (keycode == 21)
//		meme->renmod = 4;
}
