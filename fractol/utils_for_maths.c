/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_maths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 14:39:53 by adamgallot        #+#    #+#             */
/*   Updated: 2025/12/10 01:00:27 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	scale(double unscaledNum, double minAllowed, double maxAllowed,
		double max)
{
	return (((maxAllowed - minAllowed) * (unscaledNum - 0)) / (max - 0)
		+ minAllowed);
}

double	atodouble(char *string)
{
	long	inte_part;
	double	fract_part;
	double	power;
	int		sign;

	inte_part = 0;
	fract_part = 0;
	power = 1;
	sign = 1;
	while ((*string >= 9 && *string <= 13) || *string == 32)
		++string;
	if (*string++ == '-')
		sign *= -1;
	while (*string != '.' && *string)
		inte_part = (inte_part * 10) + (*string++ - 48);
	if (*string == '.')
		++string;
	while (*string)
	{
		power /= 10;
		fract_part = fract_part + (*string++ - 48) * power;
	}
	return ((fract_part + inte_part) * sign);
}

t_complex	sum_vectors(t_complex a, t_complex b)
{
	t_complex	res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	return (res);
}

t_complex	product_vector(t_complex a)
{
	t_complex	res;

	res.x = (a.x * a.x) - (a.y * a.y);
	res.y = 2 * a.x * a.y;
	return (res);
}
