/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 01:18:17 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/27 18:59:54 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// pas besoin de faire toute la merde du premier parce que la stack est presque triée
void	from_b_to_a(t_stack **a, t_stack **b)
{
	top_for_push(a, (*b)->target, 'a'); // on veut être sur que b->target dans A est on top
	pa(a, b, 0);
}