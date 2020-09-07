#include "fractol.h"

void				escape_map_butt(t_map *map)
{
	long int	**cell;

	if (map)
	{
		if (map->cell)
		{
			cell = map->cell;
			while (*cell)
			{
				free(*cell);
				cell++;
			}
			free(map->cell);
		}
		free(map);
		map = NULL;
	}
}

void				escape_butt(t_window *meme)
{
	t_map		*map;

	if (meme)
	{
		map = meme->map;
		escape_map_butt(map);
		if (meme->win_ptr != NULL)
			mlx_destroy_window(meme->mlx_ptr, meme->win_ptr);
		free(meme);
		meme = NULL;
	}
	exit(0);
}

t_window			*initwindow(void)
{
	t_window *meme;

	meme = (t_window *)malloc(sizeof(*meme));
	meme->win_ptr = NULL;
	meme->shift.r_flag = 0;
	meme->shift.l_flag = 0;
	meme->shift.u_flag = 0;
	meme->shift.d_flag = 0;
	meme->zoom = 2;
	return (meme);
}

void				hookhandler(t_window *meme)
{
//	mlx_hook(meme->win_ptr, 6, 0, mouse_move, meme);
//	mlx_hook(meme->win_ptr, 4, 0, mouse_press, meme);
//	mlx_hook(meme->win_ptr, 5, 0, mouse_release, meme);
//	mlx_hook(meme->win_ptr, 2, 0, key_press1, meme);
//	mlx_hook(meme->win_ptr, 3, 0, key_release1, meme);
	mlx_loop(meme->mlx_ptr);
}

void				window(t_map *map, t_window *meme)
{
	meme->shift.x = WINX / 2 - map->width / 2;
	meme->shift.y = WINY / 2 - map->height / 2;
	meme->mlx_ptr = mlx_init();
	meme->win_ptr = mlx_new_window(meme->mlx_ptr, WINX, WINY, "MEME");
	meme->map = map;
	//drawmap(meme);  // out to draw fractals
	hookhandler(meme);
}

