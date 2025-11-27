/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:39:47 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/27 19:16:33 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;
	// check valid arg
	if (ac == 1 || (ac == 2 && (!av[1][0])))
		return 1; //error
	else if (ac == 2) // if string is sent
		av = ft_split(av[1], ' '); // split function sans static ATTENTION
	else
		av++;
	/*how we are not missing the av[0]*/
	create_stack_a(&a, av);
	if (!stack_is_sorted(a)) // 0 -> is not sorted. | donc 
	{
		if(stack_len(a) == 2)
			sa(&a, 0);
		else if (stack_len(a) == 3)
			sort_for_three(&a);
		else
			sort_bilay(&a, &b);
	}
	free_stack(&a);
	return (0);
}
