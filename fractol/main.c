/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:18:41 by adamgallot        #+#    #+#             */
/*   Updated: 2025/12/10 00:20:12 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || (ac == 4
			&& !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		if (!ft_strncmp(av[1], "julia", 5))
		{
			fractal.julia_x = atodouble(av[2]);
			fractal.julia_y = atodouble(av[3]);
			if (fractal.julia_x + fractal.julia_y > 4
				|| fractal.julia_x + fractal.julia_y < -4)
				(ft_putstr_fd("Wrong interval value \nYou could use 0.3 0.5",
						STDERR_FILENO), exit(EXIT_FAILURE));
		}
		(fractol_init(&fractal), fractal_render(&fractal));
		mlx_loop(fractal.mlx_connexion);
	}
	else
	{
		ft_putstr_fd("./fractol mandelbrot\njulia with: 0.3 0.5 |-0.4 0.6", 2);
		exit(EXIT_FAILURE);
	}
}
