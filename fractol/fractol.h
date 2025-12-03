/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 20:19:01 by adamgallot        #+#    #+#             */
/*   Updated: 2025/12/03 13:37:38 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
#define FRACTOL_H

# include "mlx/mlx.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

# define WIDTH 800
# define HEIGHT 800


# ifdef __linux__
#  define K_ESC 65307
#  define K_UP 65362
#  define K_DOWN 65364
#  define K_LEFT 65361
#  define K_RIGHT 65363
#  define M_SCROLL_UP 4
#  define M_SCROLL_DOWN 5
// If we are on Mac (Your Home Computer)
# else
#  define K_ESC 53
#  define K_UP 126
#  define K_DOWN 125
#  define K_LEFT 123
#  define K_RIGHT 124
#  define M_SCROLL_UP 4 // usually same for mouse
#  define M_SCROLL_DOWN 5
# endif
/*PIXEL IMAGE BUFFER*/
typedef struct s_img
{
	void	*img_ptr; // point to image struct
	char	*pxl_ptr; // poiting to a pixel -> to 1 bit -> so char *
	int		bytes_per_pixel;
	int		endian; 
	int		line_len;
}t_img;


/*FRACTAL CORE*/
typedef struct s_fractal
{
    char    *name;
	void	*mlx_connexion;
	void	*mlx_window;
	t_img	img;
	
	//HOOKS
	
}t_fractal;

/*Prototypes*/
void	fractol_init(t_fractal *fractal);

# endif