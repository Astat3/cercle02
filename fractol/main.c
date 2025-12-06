/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:18:41 by adamgallot        #+#    #+#             */
/*   Updated: 2025/12/04 18:59:59 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main (int ac, char **av)
{
	t_fractal fractal;

	if ((ac == 2 && !ft_strncmp(av[1],"mandelbrot", 10)) || (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
        fractal.julia_x = atodouble(av[2]);
        fractal.julia_y = atodouble(av[3]);
		fractol_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connexion); // loop events listening from input even;
	}
	else
	{
		ft_putstr_fd("Error", STDERR_FILENO);
		exit(EXIT_FAILURE);  
	}
}
