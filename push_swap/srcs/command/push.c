/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 22:03:37 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/28 15:50:40 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void    push_func(t_stack **dst, t_stack **src)//
{
	t_stack *pushed_node;

	if (!*src)
		return ;
	pushed_node = *src;
	*src = (*src)->next;
	if(*src)
		(*src)->prev = NULL;
	pushed_node->prev = NULL;
	if (!*dst) // stack is empty
	{
		*dst = pushed_node;
		pushed_node->next = NULL;
	}
	else //stack is not empty 
	{
		pushed_node->next = *dst;
		(*dst)->prev = pushed_node;
		*dst = pushed_node; //PAS OUBLIER POUR METTRE A JOUR LE POINTEUR
	}
}


void	pa(t_stack **a, t_stack **b, int bool)
{
	push_func(a ,b);
	if (bool == 0)
	{
        putstr_fd("pa\n", STDOUT_FILENO);
	}
}

void	pb(t_stack **a, t_stack **b, int bool)
{
	push_func(b, a);
	if (bool == 0)
	{
		putstr_fd("pb\n", STDOUT_FILENO);
	}
}