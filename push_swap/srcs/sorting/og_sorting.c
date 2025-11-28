/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   og_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:19:54 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/28 15:59:27 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_on_top(t_stack **a)
{
	t_stack *min_node;

	min_node = min(*a);
	while (*a != min_node)
	{
		if (min_node->median_sup)
			ra(a, 0);
		else
			rra(a, 0);
	}
}

void	sort_bilay(t_stack **a, t_stack **b)
{
	int	len_of_a;

	len_of_a = stack_len(*a);
	// push the 2 first element of a into a
	if (len_of_a-- > 3 && !stack_is_sorted(*a))
		pb(b, a, 0);
	if (len_of_a-- > 3 && !stack_is_sorted(*a))
		pb(b, a, 0);
	while (len_of_a-- > 3 && !stack_is_sorted(*a))
	{
		info_a(*a, *b);
		from_a_to_b(a, b);
	}
	sort_for_three(a);
	while (*b)
	{
		info_b(*a, *b);
		from_b_to_a(a, b);
	}
	index_in_stack(*a); //permet de refresh les value de la liste
	min_on_top(a);
}
