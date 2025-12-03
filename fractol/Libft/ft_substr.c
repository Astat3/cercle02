/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:21:24 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/04 18:59:39 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	give_size(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (start >= give_size(s))
		len = 0;
	if (len > give_size(s))
		len = give_size(s);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while ((i < len) && (s[start]))
	{
		res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}

// int main (void)
// {
//     printf("%s\n", ft_substr("tripouille", 0, 420000));
// }