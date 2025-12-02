/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:39:47 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/30 16:49:29 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && (!av[1][0])))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	if (!av)
		return (1);
	else
		av++;
	create_stack_a(&a, av);
	if (!stack_is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 0);
		else if (stack_len(a) == 3)
			sort_for_three(&a);
		else
			sort_bilay(&a, &b);
	}
	free_stack(&a);
	return (0);
}
