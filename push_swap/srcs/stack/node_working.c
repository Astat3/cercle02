/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_working.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:38:36 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/28 16:26:44 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *get_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	append_node(t_stack **stack, int n)
{
	t_stack *last_node;
	t_stack	*new_node;

	if (!stack)
		return; 
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

