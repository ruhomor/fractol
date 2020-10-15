/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kachiote <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 22:56:37 by kachiote          #+#    #+#             */
/*   Updated: 2020/10/15 18:35:49 by Ruslan           ###   ########.fr       */
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
# define WINX 900
# define WINY 600
# define ZOOMMUL 1.066666
# define ZOOMDIV 0.937500
# define ITERD 2

typedef struct			s_color
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
	unsigned char		alpha;
}						t_color;

typedef struct			s_pxl
{
	size_t				x;
	size_t				y;
	t_color				color;
}						t_pxl;

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

typedef struct			s_point
{
	long int			x;
	long int			y;
}						t_point;

typedef struct			s_frac
{
	int					id;
	t_complex			lt;
	t_complex			rb;
	t_complex			d;
	double				zoom;
	t_complex			k;
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

int						mouse_press(int button, int x, int y, void *p);
int						mouse_move(int x, int y, void *p);
int						mouse_release(int button, int x, int y, void *p);

int						key_press1(int keycode, void *p);
int						key_release1(int keycode, void *p);
void					kph(int keycode, t_window *meme);

void					escape_butt(t_window *meme);
void					zoom_in(t_frac *frac, int curx, int cury);
void					zoom_out(t_frac *frac, int curx, int cury);

t_window				*initwindow(void);
void					initfrac2(int a, t_frac *frac);
t_frac					initfrac(int a);
void					hookhandler(t_window *meme);
void					window(t_window *meme);

void					construct_fractal(void *mlx_ptr, t_window *meme);
void					fill_if(t_image *image, t_frac frac,
		void (*f)(t_pxl*, t_frac));
int						even(t_pxl pxl);
void					set_pxl(t_image *image, t_pxl pxl);
void					destroy_image(void *mlx_ptr, t_image *image);
t_image					*init_image(void *mlx_ptr);

t_color					colorfonk(int iters, int max);
t_color					colorfonker(int iters);
t_complex				pxl_to_point(t_pxl pxl, t_complex d, t_frac frac);
double					ft_fabs(double a);
t_complex				c_multiply(t_complex a, t_complex b);
t_complex				c_add(t_complex a, t_complex b);

void					burningship(t_pxl *pxl, t_frac frac);
void					julia(t_pxl *pxl, t_frac frac);
void					mandelbrot(t_pxl *pxl, t_frac frac);
#endif
