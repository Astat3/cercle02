/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:19:01 by adamgallot        #+#    #+#             */
/*   Updated: 2025/12/10 00:21:28 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define BLACK 0x000000 // The Mandelbrot Set (Center)
# define WHITE 0xFFFFFF // High contrast
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

# define MAGENTA_BURST 0xFF00FF // A classic "glitch" purple
# define LIME_SHOCK 0xCCFF00    // Acid green
# define NEON_ORANGE 0xFF6600   // Bright safety orange
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM 0x33CCCC // Bright cyan/turquoise
# define HOT_PINK 0xFF69B4
# define ELECTRIC_BLUE 0x0066FF
# define LAVA_RED 0xFF3300

/*PIXEL IMAGE BUFFER*/
typedef struct s_img
{
	void	*img_ptr;
	char	*pxl_ptr;
	int		bytes_per_pixel;
	int		endian;
	int		line_len;
}			t_img;

/*NUMBER STRUCT*/

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

/*FRACTAL CORE*/
typedef struct s_fractal
{
	char	*name;
	void	*mlx_connexion;
	void	*mlx_window;
	t_img	img;

	double	escape;
	int		interation;
	double	shift_x;
	double	shift_y;
	double	zoom;

	double	julia_x;
	double	julia_y;
}			t_fractal;

void		fractol_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
int			trackjulia(int x, int y, t_fractal *fractal);

/*MATHS*/
double		scale(double unscaledNum, double minAllowed, double maxAllowed,
				double max);
t_complex	sum_vectors(t_complex a, t_complex b);
t_complex	product_vector(t_complex a);
double		atodouble(char *string);

/*HANDLING EVENTS*/
int			keyhandler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);

#endif