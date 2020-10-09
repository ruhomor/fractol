/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:56:37 by kachiote          #+#    #+#             */
/*   Updated: 2020/10/09 18:58:56 by Ruslan           ###   ########.fr       */
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
# define MAXITERS 120

# define BUFF_MSIZE 4
//# define WINX 2000
//# define WINY 1000
# define WINX 600
# define WINY 400
# define ZOOMMUL 1.066666
# define ZOOMDIV 0.937500
# define ITERD 1

typedef struct			s_color
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
	unsigned char		alpha;
}						t_color;

typedef struct			s_pxl
{
	size_t			x;
	size_t			y;
	t_color				color;
}				t_pxl;

typedef struct			s_shift
{
	long int			x;
	long int			y;
	long int			u_flag;
	long int			d_flag;
	long int			l_flag;
	long int			r_flag;
}						t_shift;

typedef struct			s_image
{
	int					bpp;
	int					size_line;
	int					endian;
	void				*img_ptr;
	char				*img_data;
}						t_image;

typedef struct			s_complex
{
	double				re;
	double				im;
}						t_complex;

typedef struct			s_frac
{
	int					id;
	t_complex			lt;
	t_complex			rb;
	t_complex			d;
	double				zoom;
	int					maxiter;
}						t_frac;

typedef	struct			s_window
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					drag_flag;
	t_shift				shift;
	double				zoom;
	t_frac				*frac;
	t_image				**img;
}						t_window;

int					mouse_press(int button, int x, int y, void *p);
int					mouse_move(int x, int y, void *p);
int					mouse_release(int button, int x, int y, void *p);

int					key_press1(int keycode, void *p);
int					key_release1(int keycode, void *p);
void				kph(int keycode, t_window *meme);

void                            escape_butt(t_window *meme);
void	zoom_in(t_frac *frac, int curx, int cury);
void	zoom_out(t_frac *frac, int curx, int cury);

t_window                        *initwindow(void);
void                            hookhandler(t_window *meme);
void                            window(t_window *meme);

void	construct_fractal(void *mlx_ptr, t_window *meme);
void 	fill_if(t_image *image, t_frac frac, void (*f)(t_pxl*, t_complex, int));
void 	fill(t_image *image, t_color color);
int 	even(t_pxl pxl);
void 	set_pxl(t_image *image, t_pxl pxl);
void 			destroy_image(void *mlx_ptr, t_image *image);
t_image 		*init_image(void *mlx_ptr);

t_color	colorfonk(int iters);
#endif
