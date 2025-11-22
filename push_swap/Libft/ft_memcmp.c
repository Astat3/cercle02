/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:42:18 by agallot           #+#    #+#             */
/*   Updated: 2025/11/04 13:45:04 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				index;

	index = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *)s2;
	while (index < n)
	{
		if (str1[index] > str2[index])
		{
			return (1);
		}
		if (str1[index] < str2[index])
		{
			return (-1);
		}
		index++;
	}
	return (0);
}
