/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:30:59 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/27 19:05:08 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rr_func(t_stack **stack)
{
	t_stack *first;
	t_stack *last;
	if (!stack || !*stack || !(*stack)->next)
		return ;

	first = *stack; 
	last = get_last(*stack);
	last->prev->next = NULL;
	last->next = first;
	first->prev = last;
	*stack = last;
	last->prev = NULL;
}

void	rra(t_stack **a, int bool)
{
	rr_func(a);
	if (bool == 0)
		putstr_fd("rra\n", STDOUT_FILENO);
}
void	rrb(t_stack **b, int bool)
{
	rr_func(b);
	if (bool == 0)
		putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_stack **a, t_stack **b, int bool)
{
	rr_func(a);
	rr_func(b);
	if (bool == 0)
		putstr_fd("rrr\n", STDOUT_FILENO);
}