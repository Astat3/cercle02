/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:38:50 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/30 17:21:58 by agallot          ###   ########.fr       */
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

static int	is_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == '+' || c == '-')
		return (1);
	return (0);
}

static int	check_error(char *s)
{
	if (!*s)
		return (0);
	while (*s)
	{
		if (!is_digit(*s))
			return (0);
		s++;
	}
	return (1);
}

void	create_stack_a(t_stack **a, char **av)
{
	int		i;
	long	n;

	i = 0;
	while (av[i])
	{
		if (!check_error(av[i]))
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
