/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:05:19 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/30 17:18:23 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_func(t_stack **stack)
{
	t_stack	*last;
	t_stack	*first;

	if (!stack)
		return ;
	if (!*stack || !(*stack)->next)
		return ;
	last = get_last(*stack);
	first = *stack;
	*stack = first->next;
	first->next->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack **a, int bool)
{
	rotate_func(a);
	if (bool == 0)
		putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_stack **b, int bool)
{
	rotate_func(b);
	if (bool == 0)
		putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_stack **a, t_stack **b, int bool)
{
	rotate_func(a);
	rotate_func(b);
	if (bool == 0)
		putstr_fd("rr\n", STDOUT_FILENO);
}
