/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstrfd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 19:00:06 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/30 17:17:29 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	puthchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		puthchar_fd(s[i], fd);
		i++;
	}
}
