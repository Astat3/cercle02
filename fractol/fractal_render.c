/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:31:41 by adamgallot        #+#    #+#             */
/*   Updated: 2025/12/09 23:43:25 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// check if the pixel is actually in the mandelbrot set
// LOOKING for this z = z^2 + c -> whith c the actual pixel

static void	pixel_put(int x, int y, t_img *img, int color)
{
	int skippage;

	skippage = (y * img->line_len)  + (x * (img->bytes_per_pixel / 8));
	*(unsigned int * )(img->pxl_ptr + skippage) = color;
}

static	void juliadelbrot(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x; 
		c->y = fractal->julia_y;
	}
	
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	is_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z; 
	t_complex	c;
	int			i;
	int			color;
	
	z.x = (scale(x, -2, +2, 0, WIDTH) * fractal->zoom ) + fractal->shift_x;
	z.y = (scale(y, +2, -2, 0, HEIGHT) * fractal->zoom ) + fractal->shift_y;
	i = 0;
	
	juliadelbrot(&z, &c, fractal);
	while (i < fractal->interation) // incrementing to see if diverge
	{
		z = sum_vectors(product_vector(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape)
		{
			color = scale(i, BLACK, WHITE, 0, fractal->interation);
			pixel_put(x, y , &fractal->img, color);
			return ;
		}
		i++;
	}
	// We are in madelbrot
	pixel_put(x, y , &fractal->img, WHITE);
}

void	fractal_render(t_fractal *fractal)
{
	int	y; 
	int x;
	
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			is_pixel(x, y, fractal);
		}
		
	}
	mlx_put_image_to_window(fractal->mlx_connexion,fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}