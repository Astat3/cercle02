/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:26:51 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/05 16:08:05 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	count_num(long int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		n *= -1;
	}
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	int			size;
	char		*res;

	nbr = n;
	size = count_num(nbr);
	res = malloc((sizeof(char)) * (size + 1));
	if (!res)
		return (NULL);
	res[size--] = '\0';
	if (nbr == 0)
		res[0] = '0';
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		res[size--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}
