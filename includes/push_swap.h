/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:10:14 by hmorand           #+#    #+#             */
/*   Updated: 2024/04/06 18:10:17 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_stack
{
	int				x;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// stack utils

t_stack	*stack_new(int x);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack, int len);
void	stack_delfirst(t_stack **stack, int len);
t_stack	*atos(char **numbers);

// stack info

int		stack_len(t_stack *stack);
int		stack_max(t_stack *stack);
int		stack_min(t_stack *stack);
int		insert_pos(t_stack *stack, int num);
int		value_at(t_stack *stack, int index);

// stack operations

void	stack_swap(t_stack **stack);
void	stack_push(t_stack **stack_from, t_stack **stack_to);
void	stack_reverse_rotate(t_stack **stack);
void	stack_rotate(t_stack **stack);

// processing

bool	ft_strcmp(char *s1, char *s2);
bool	contains_doubles(char **numbers);
bool	ft_is_digit(char *str);
char	*join_strarr(char **argv, int argc);

// stack a operations

void	sb(t_stack **stack_b);
void	rrb(t_stack **stack_b);
void	rb(t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);
void	rrr(t_stack **stack_b, t_stack **stack_a);

// stack b operations

void	sa(t_stack **stack_a);
void	rra(t_stack **stack_a);
void	ra(t_stack **stack_a);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

// max-min functions

int		max(int count, ...);
int		min(int count, ...);

// optimal finding functions

int		optimal_cost_n(int pos, int ins_pos, t_stack *a, t_stack *b);
int		optimal_cost(t_stack *a, t_stack *b);
void	insert_i(t_stack **a, t_stack **b, int opt_ind);
void	sort_3(t_stack **a);
// inserting help

void	move_both_up(int _ra, int _rb, t_stack **a, t_stack **b);
void	move_both_down(int _rra, int _rrb, t_stack **a, t_stack **b);
void	move_a_up_b_down(int _ra, int _rrb, t_stack **a, t_stack **b);
void	move_b_up_a_down(int _rra, int _rb, t_stack **a, t_stack **b);
// display utils

void	print_stack(t_stack *stack, char *stack_name);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

#endif
