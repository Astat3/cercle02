/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:06:22 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/27 20:26:00 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// être sur le max is bottom
// swap the 2first if needed

void	sort_for_three(t_stack **stack)
{
	t_stack	*max_node;

    if (!stack || !(*stack))
        return ;
	max_node = max(*stack);
	if (max_node == *stack)
		ra(stack, 0);
	if (max_node == (*stack)->next)
		rra(stack, 0);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, 0);
}
