/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:30:09 by hmorand           #+#    #+#             */
/*   Updated: 2024/04/22 18:30:09 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_swap(t_stack **stack)
{
	int	a;

	if (stack_len(*stack) >= 2)
	{
		a = (*stack)->x;
		(*stack)->x = (*stack)->next->x;
		(*stack)->next->x = a;
	}
}

void	stack_reverse_rotate(t_stack **stack)
{
	*stack = (*stack)->prev;
}

void	stack_rotate(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	stack_push(t_stack **stack_from, t_stack **stack_to)
{
	int	n;

	if (!stack_from || !(*stack_from))
		return ;
	n = (*stack_from)->x;
	stack_delfirst(stack_from, stack_len(*stack_from));
	if (*stack_to == NULL)
	{
		*stack_to = stack_new(n);
		return ;
	}
	stack_add_front(stack_to, stack_new(n));
}

void	max_at_top(t_stack **b)
{
	int		i;
	int		max;
	t_stack	*current_r;
	t_stack	*current;

	max = stack_max(*b);
	i = 0;
	current = *b;
	current_r = *b;
	while (current->x != max && current_r->x)
	{
		current = current->next;
		current_r = current_r->prev;
		i++;
	}
	if (current->x == max)
	{
		while (i--)
			rb(b);
	}
	else
	{
		while (i--)
			rrb(b);
	}
}
