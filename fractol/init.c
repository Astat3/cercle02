/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:21:33 by adamgallot        #+#    #+#             */
/*   Updated: 2025/12/03 13:49:03 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_init(t_fractal *fractal)
{
	fractal->mlx_connexion = mlx_init();
	if (fractal->mlx_connexion == NULL)
		malloc_error();
	fractal->mlx_window = mlx_new_window(fractal->mlx_connexion, WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx_window == NULL)
		//mlx_destroy_dislpl
	
}