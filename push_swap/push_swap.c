/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:39:47 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/24 14:28:27 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
	}
	return (res * sign);
}


typedef struct s_node
{
	int 			content;
	struct s_node	*next;
}t_node;


int main(int ac, char **av)
{

	t_node s1;
	s1 = malloc(sizeof(t_node));
	
	char *to_fill;
	to_fill = " 1 2 3 4";
	printf("%s", to_fill);
	while (*to_fill)
	{
		/* code */
	}
	
}