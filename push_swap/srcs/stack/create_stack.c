/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agallot <agallot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:38:50 by adamgallot        #+#    #+#             */
/*   Updated: 2025/12/13 17:06:07 by agallot          ###   ########.fr       */
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

static int	is_empty_or_space(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

static int	check_error(char *str_n)
{
	if (is_empty_or_space(str_n))
		return (1);
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

void	create_stack_a(t_stack **a, char **av)
{
	int		i;
	long	n;

	i = 0;
	if (!av || !av[0])
		error_mess_free(a);
	while (av[i])
	{
		if (check_error(av[i]))
		{
			free_split(av);
			error_mess_free(a);
		}
		n = ft_long_atoi(av[i]);
		if (n < INT_MIN || n > INT_MAX)
		{
			free_split(av);
			error_mess_free(a);
		}
		if (check_double(*a, (int)n))
			(free_split(av), error_mess_free(a));
		append_node(a, (int)n);
		i++;
	}
}
