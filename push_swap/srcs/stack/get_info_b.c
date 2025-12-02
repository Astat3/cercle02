/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 00:35:20 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/30 17:16:40 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*min(t_stack *stack)
{
	t_stack	*min_node;
	long	min;

	if (!stack)
		return (NULL);
	min_node = stack;
	min = LONG_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min_node = stack;
			min = stack->value;
		}
		stack = stack->next;
	}
	return (min_node);
}

static void	target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	current_match;

	while (b)
	{
		current_match = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < current_match)
			{
				current_match = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (current_match == LONG_MAX)
			b->target = min(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	info_b(t_stack *a, t_stack *b)
{
	index_in_stack(a);
	index_in_stack(b);
	target_b(a, b);
}
