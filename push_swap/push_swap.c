/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 23:39:47 by adamgallot        #+#    #+#             */
/*   Updated: 2025/12/08 17:31:57 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	sort_stack(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 2)
		sa(a, 0);
	else if (stack_len(*a) == 3)
		sort_for_three(a);
	else
		sort_bilay(a, b);
}

static int	check_num(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return 0;
	while (s[i])
	{
		if ((s[i] <= '0' && s[i] >='9') || s[i] != '+' || s[i]!= '-')
			return 0;
		i++;
	}
	return (1);
}

static char	**parse_args(int ac, char **av)
{
	if (ac == 1)
		exit(1);
	if (ac == 2 && !av[1][0])
		exit((write(STDERR_FILENO, "Error\n", 6), 1));
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (!check_num(av[1]))
		{
			free_split(av);	
			exit((write(STDERR_FILENO, "Error\n", 6), 1));	
		}
		return (av);
	}
	return (av + 1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = NULL;
	b = NULL;
	args = parse_args(ac, av);
	create_stack_a(&a, args);
	if (!stack_is_sorted(a))
		sort_stack(&a, &b);
	free_stack(&a);
	if (ac == 2)
		free_split(args);
	return (0);
}
