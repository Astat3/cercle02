/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 18:03:32 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/27 20:24:33 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	stack_is_sorted(t_stack *stack)
{
	if (!stack)
		return 2;
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_len(t_stack *stack)
{
	int count;
	
	if (!stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack *max(t_stack *stack)
{
	long	max;
	t_stack *res;
	
	if(!stack)
		return (NULL);
	res = stack;
	max = stack->value;
	while (stack->next)
	{
		if (max < stack->next->value)
		{
			max = stack->next->value;
			res = stack->next;
		}
		stack = stack->next;
	}
	return (res);
}