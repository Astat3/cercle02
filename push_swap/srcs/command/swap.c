/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:04:02 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/27 19:06:55 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	swap_func(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack = second;
	
}
void	sa(t_stack **a, int bool)
{
	swap_func(a);
	if (bool == 0)
		putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_stack **b, int bool)
{
	swap_func(b);
	if (bool == 0)
		putstr_fd("sb\n", STDOUT_FILENO);
}

void	ss(t_stack **a, t_stack **b, int bool)
{
	swap_func(a);
	swap_func(b);
	if (bool == 0)
		putstr_fd("ss\n", STDOUT_FILENO);
}
