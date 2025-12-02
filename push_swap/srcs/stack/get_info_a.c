/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 20:40:52 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/30 17:16:28 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//au dessus ou en desous de la médiane + index e
void	index_in_stack(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->median_sup = 1;
		else
		{
			stack->median_sup = 0;
		}
		i++;
		stack = stack->next;
	}
}

//link all nodes from a to a b target
// target --> closest smallest
static void	target_a(t_stack *a, t_stack *b)
{
	t_stack	*target_node;
	t_stack	*current_b;
	long	current_match;

	while (a)
	{
		current_match = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value && current_b->value > current_match)
			{
			current_match = current_b->value;
			target_node = current_b;
			}
		current_b = current_b->next;
		}
		if (current_match == LONG_MIN)
			a->target = max(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

static void	how_much(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_price = a->index;
		if (!(a->median_sup))
			a->push_price = (len_a) - (a->index);
		if (a->target->median_sup)
			a->push_price += a->target->index;
		else
			a->push_price += (len_b) - (a->target->index);
		a = a->next;
	}
}

void	cheap(t_stack *a)
{
	t_stack	*cheapest_node;
	int		cheap_match;

	cheap_match = INT_MAX;
	while (a)
	{
		if (a->push_price < cheap_match)
		{
			cheap_match = a->push_price;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = 1;
}

void	info_a(t_stack *a, t_stack *b)
{
	index_in_stack(a);
	index_in_stack(b);
	target_a(a, b);
	how_much(a, b);
	cheap(a);
}
