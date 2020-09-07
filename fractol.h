/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:56:37 by kachiote          #+#    #+#             */
/*   Updated: 2020/03/04 07:18:04 by kachiote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "lib/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# define MIN 2147483647
# define MAX -2147483648

# define BUFF_MSIZE 4
# define WINX 2000
# define WINY 1000

typedef struct			s_color
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_color;

typedef struct			s_fcolor
{
	float				r;
	float				g;
	float				b;
}						t_fcolor;

typedef struct			s_point
{
	long int			x;
	long int			y;
	long int			z;
	t_color				color;
}						t_point;

typedef struct			s_fpoint
{
	float				x;
	float				y;
	float				z;
	t_fcolor			color;
}						t_fpoint;

typedef	struct			s_map
{
	long int			**cell;
	int					width;
	int					height;
	long int			max;
	long int			min;
	unsigned long int	colorrange;
}						t_map;

typedef	struct			s_window
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					zoom;
	int					drag_flag;
	t_map				*map;
}						t_window;

