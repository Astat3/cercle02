/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_working.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:38:36 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/30 17:21:17 by agallot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	check_double(t_stack *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == n)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	append_node(t_stack **stack, int n)
{
	t_stack	*last_node;
	t_stack	*new_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->value = n;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last_node = get_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
