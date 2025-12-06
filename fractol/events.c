/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 17:40:48 by adamgallot        #+#    #+#             */
/*   Updated: 2025/12/04 18:31:59 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connexion, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connexion, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connexion);
	free(fractal->mlx_connexion);
	exit(EXIT_FAILURE);	
}

//keypress
// GET EVERY KEY PRESSED
int	keyhandler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_ESCAPE)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= 0.5 * fractal->zoom;
	else if (keysym == XK_Up)
		fractal->shift_y += 0.5 * fractal->zoom;
	else if (keysym == XK_Down)
		fractal->shift_y -= 0.5 * fractal->zoom;
	else if (keysym == XK_plus)
		fractal->interation += 10;
	else if (keysym == XK_minus)
		fractal->interation -= 10;
	fractal_render(fractal);
	return (0);

}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
		fractal->zoom *= 0.95; 
	else if (button == Button4)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}