/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:39:47 by adamgallot        #+#    #+#             */
/*   Updated: 2025/12/07 19:20:11 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void    free_split(char **str, int ac)
{
	if (ac == 2)
	{
    int i;

    i = 0;
    if (!str)
        return ;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);		
	}
	else
	{
		return ;
	}
}


int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL, 
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	else if (!av)
		return ((write(STDERR_FILENO, "Error\n", 6)));
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
	free_split(av, ac);
	return (free_stack(&a), 0);
}
