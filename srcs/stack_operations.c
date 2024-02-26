/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:29:41 by hmorand           #+#    #+#             */
/*   Updated: 2024/02/26 11:29:45 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	*stack = (*stack)->next;
}

void	stack_push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*temp_prev;
	t_stack	*temp_next;
	t_stack	*temp;

	if (!stack_from || !(*stack_from))
		return ;
	temp = *stack_from;
	temp_next = (*stack_from)->next;
	temp_prev = (*stack_from)->prev;
	temp_next->prev = temp_prev;
	temp_prev->next = temp_next;
	temp->next = temp;
	temp->prev = temp;
	(*stack_from) = temp_next;
	if (!(*stack_to))
	{
		*stack_to = temp;
		return ;
	}
	stack_add_back(stack_to, temp);
	stack_reverse_rotate(stack_to);
}
