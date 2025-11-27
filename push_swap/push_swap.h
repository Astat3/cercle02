/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:51:00 by adamgallot        #+#    #+#             */
/*   Updated: 2025/11/27 19:26:23 by adamgallot       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

/*Node arch*/
typedef struct s_stack
{
	int		value;
	int		index;
	int		push_price;
	int		median_sup; //bool
	int		cheapest; // bool
	struct s_stack *target;
	struct s_stack *prev;
	struct s_stack *next;
}				t_stack;

void	append_node(t_stack **stack, int n);
void	create_stack_a(t_stack **a, char **av);
void	error_mess_free(t_stack **a);
void	free_stack(t_stack **stack);
int		stack_is_sorted(t_stack *a);
int		stack_len(t_stack *stack);

char	**ft_split(char const *s, char c);
long	ft_long_atoi(const char *str);
t_stack	*get_last(t_stack *lst);
void	sort_for_three(t_stack **stack);
void	cheap(t_stack *a);
void	from_b_to_a(t_stack **a, t_stack **b);


t_stack *max(t_stack *stack);
void	info_a(t_stack *a,t_stack *b);
void	from_a_to_b(t_stack **a, t_stack **b);
void	index_in_stack(t_stack *stack);

void	info_b(t_stack *a,t_stack *b);
void	top_for_push(t_stack **stack, t_stack *cheapest_node, char id);
t_stack *min(t_stack *stack);

void	putstr_fd(char *s, int fd);

void	sort_bilay(t_stack **a, t_stack **b);

/*command*/
void	pa(t_stack **a, t_stack **b, int bool);
void	pb(t_stack **a, t_stack **b, int bool);
void	rra(t_stack **a, int bool);
void	rrb(t_stack **b, int bool);
void	rrr(t_stack **a, t_stack **b, int bool);
void	ra(t_stack **a, int bool);
void	rb(t_stack **b, int bool);
void	rr(t_stack **a, t_stack **b, int bool);
void	sa(t_stack **a, int bool);
void	sb(t_stack **b, int bool);
void	ss(t_stack **a, t_stack **b, int bool);


#endif