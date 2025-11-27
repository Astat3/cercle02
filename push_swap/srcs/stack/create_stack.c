/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:38:50 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/27 19:14:56 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	last_check(t_stack *stack, int n)
{
	if (!stack)
		return 0;
	while (stack)
	{
		if (stack->value == n)
			return 1;
	stack = stack->next;
	}
	return 0;
}
void	free_stack(t_stack **stack)
{
	t_stack *current; 
	t_stack *tmp;
	
	if(!stack || (*stack)) /*(does the pointer exist || does the list is empty) ||| Do not reverse it, otherwise it wont work*/
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL; // last iteration
}

void	error_mess_free(t_stack **a)
{
	free_stack(a); //to clean a list we need to clean it node by node
	putstr_fd("Error", STDERR_FILENO);
	exit(1);
}

static int	is_digit(char c)
{
	if ((c >= '0' && c <= '9') || 
    c == '+' || c == -'-') // mettre aussi les signes
		return (1);
	return (0);
}

static int	check_error(char *s)
{
	if (!*s)
		return 0;
	while (*s)
	{
		if(!is_digit(*s))
			return (0);
		s++;
	}
	return 1;
}


void create_stack_a(t_stack **a, char **av)
{
	int i;
	long n;

    i = 0;
	while (av[i])
	{
	if(!check_error(av[i]))
		error_mess_free(a); // pas de besoin de mettre &a, car il est deja envoyé depuis le main.
	n = ft_long_atoi(av[i]);
	if (n < -2147483648 || n > 2147483647)
		error_mess_free(a);
	if (!last_check(*a, (int)n)) // juste check que le nombre est bon, que a est bon etc.. || psk on a un makefile || check le node;
		error_mess_free(a);
	append_node(a, (int)n); // chaque nombre correspond a un node;
	i++;
	}
}
