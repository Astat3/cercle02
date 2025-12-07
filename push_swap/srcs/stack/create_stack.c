/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:38:50 by adamgallot        #+#    #+#             */
/*   Updated: 2025/12/07 19:10:59 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_mess_free(t_stack **a)
{
	free_stack(a);
	putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}


static int	check_error(char *str_n)
{
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9'))) 
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}
}

void	create_stack_a(t_stack **a, char **av)
{
	int		i;
	long	n;

	i = 0;
	while (av[i])
	{
		if (check_error(av[i]))
			error_mess_free(a);
		n = ft_long_atoi(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			error_mess_free(a);
		if (check_double(*a, (int)n))
			error_mess_free(a);
		append_node(a, (int)n);
		i++;
	}
}
