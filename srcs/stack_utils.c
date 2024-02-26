/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:14:10 by hmorand           #+#    #+#             */
/*   Updated: 2024/02/26 12:15:15 by hmorand          ###   ########.ch       */
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

t_stack	*atos(char **numbers)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	i = 0;
	if (contains_doubles(numbers))
	{
		free_strarr(numbers);
		return (NULL);
	}
	stack = 0;
	while (numbers[i])
	{
		if (!ft_is_digit(numbers[i]))
		{
			free_strarr(numbers);
			stack_clear(&stack, stack_len(stack));
			return (NULL);
		}
		new = stack_new(ft_atoi(numbers[i++]));
		stack_add_back(&stack, new);
	}
	free_strarr(numbers);
	return (stack);
}
