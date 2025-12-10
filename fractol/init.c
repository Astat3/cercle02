/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:21:33 by adamgallot        #+#    #+#             */
/*   Updated: 2025/12/10 01:04:57 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Problem detected\n");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractal *fractal)
{
	fractal->escape = 4;
	fractal->interation = 50;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}
/*NEED TO INCLUDE THE LIB*/

static void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, keyhandler, fractal);
	mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
	mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
	mlx_hook(fractal->mlx_window, MotionNotify, PointerMotionMask,
		trackjulia, fractal);
}

void	fractol_init(t_fractal *fractal)
{
	fractal->mlx_connexion = mlx_init();
	if (fractal->mlx_connexion == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connexion, WIDTH,
			HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
	{
		mlx_destroy_display(fractal->mlx_connexion);
		free(fractal->mlx_connexion);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_connexion, WIDTH, HEIGHT);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_connexion, fractal->mlx_window);
		mlx_destroy_display(fractal->mlx_connexion);
		free(fractal->mlx_connexion);
		malloc_error();
	}
	fractal->img.pxl_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			fractal->img.bytes_per_pixel,
			&fractal->img.line_len, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
