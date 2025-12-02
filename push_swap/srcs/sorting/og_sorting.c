/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   og_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:19:54 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/30 17:11:18 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_on_top(t_stack **a)
{
	t_stack	*min_node;

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
	if (len_of_a-- > 3 && !stack_is_sorted(*a))
		pb(a, b, 0);
	if (len_of_a-- > 3 && !stack_is_sorted(*a))
		pb(a, b, 0);
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
	index_in_stack(*a);
	min_on_top(a);
}
