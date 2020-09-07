/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:36:36 by kachiote          #+#    #+#             */
/*   Updated: 2020/09/07 19:36:37 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					main(int argc, char **argv)
{
	t_map		*map;
	t_window	*meme;

	if (argc != 2)
	{
		ft_putstr_fd("fractol: wrond number of arguments\n", 2);
		return (0);
	}
	meme = initwindow();
	map = (t_map*)malloc(sizeof(*map));
	map->cell = NULL;
	//readmap(map, argv[1], meme);
	//initmap(map, argv[1], meme);
	window(map, meme);
	return (0);
}
