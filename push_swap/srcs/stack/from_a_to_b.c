/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 23:13:55 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/27 00:32:09 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void double_rotation(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
	{
		rr(a, b, 0);
		index_in_stack(*a);
		index_in_stack(*b);
	}
}
static void double_inverse_rotation(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node->target && *a != cheapest_node)
	{
		rrr(a, b, 0);
		index_in_stack(*a);
		index_in_stack(*b);
	}
}

t_stack *get_cheapest(t_stack *stack)
{
	t_stack *cheapest;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest == 1)
		{
			cheapest = stack;
			return (cheapest);			
		}

		stack = stack->next;
	}
	return (NULL);
}
void	top_for_push(t_stack **stack, t_stack *cheapest_node, char id)
{
	while (*stack != cheapest_node)
	{
		if (id == 'a')
		{
			if (cheapest_node->median_sup)
				ra(stack, 0);
			else
				rra(stack, 0);			
		}
		else if (id == 'b')
		{
			if (cheapest_node->median_sup)
				rb(stack, 0);
			else
				rrb(stack, 0);
		}
	}
}
void	from_a_to_b(t_stack **a, t_stack **b) //get the cheapest, put it on top, also for b, then push
{
	t_stack *cheapest_node;
	
	cheapest_node = get_cheapest(*a);
	if (cheapest_node->median_sup && cheapest_node->target->median_sup) //deux sont médian supp, il faut donc les rr
		double_rotation(a, b, cheapest_node);
	if (!(cheapest_node->median_sup) && !(cheapest_node->target->median_sup)) // resp median inf
		double_inverse_rotation(a, b, cheapest_node);
	top_for_push(a, cheapest_node, 'a');
	top_for_push(b, cheapest_node->target, 'b');
	pb(a, b, 0);
}