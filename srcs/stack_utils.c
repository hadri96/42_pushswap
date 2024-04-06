/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:09:23 by hmorand           #+#    #+#             */
/*   Updated: 2024/04/06 17:12:49 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int x)
{
	t_stack	*element;

	element = (t_stack *)galloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->next = element;
	element->prev = element;
	element->x = x;
	return (element);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	new->prev = (*stack)->prev->prev;
	(*stack)->prev->next = new;
	(*stack)->prev = new;
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	new->prev = (*stack)->prev;
	(*stack)->prev->next = new;
	(*stack)->prev = new;
	*stack = new;
}

void	stack_clear(t_stack **stack, int len)
{
	t_stack	*current;

	if (!stack)
		return ;
	while (len-- > 0)
	{
		current = *stack;
		*stack = (*stack)->next;
		gfree(current);
	}
	current = NULL;
}

void	stack_delfirst(t_stack **stack, int len)
{
	t_stack	*temp;
	t_stack	*temp_next;
	t_stack	*temp_prev;

	if (len == 0 || *stack == NULL)
		return ;
	if (len == 1)
	{
		stack_clear(stack, 1);
		return ;
	}
	temp = *stack;
	temp_next = (*stack)->next;
	temp_prev = (*stack)->prev;
	temp_next->prev = temp_prev;
	temp_prev->next = temp_next;
	(*stack) = temp_next;
}
