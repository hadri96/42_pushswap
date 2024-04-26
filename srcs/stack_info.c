/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:30:21 by hmorand           #+#    #+#             */
/*   Updated: 2024/04/22 18:30:21 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int	i;
	int	start;

	if (stack == NULL)
		return (0);
	if (stack->next->x == stack->x)
		return (1);
	i = 0;
	start = stack->x;
	stack = stack->next;
	while (stack->x != start)
	{
		stack = stack->next;
		i++;
	}
	return (i + 1);
}

int	stack_max(t_stack *stack)
{
	int	start;
	int	i;
	int	max;

	i = 0;
	start = stack->x;
	max = stack->x;
	while (i == 0 || start != stack->x)
	{
		if (i++ != 0)
		{
			if (stack->x > max)
				max = stack->x;
		}
		stack = stack->next;
	}
	return (max);
}

int	stack_min(t_stack *stack)
{
	int	start;
	int	i;
	int	min;

	i = 0;
	start = stack->x;
	min = stack->x;
	while (i == 0 || start != stack->x)
	{
		if (i++ != 0)
		{
			if (stack->x < min)
				min = stack->x;
		}
		stack = stack->next;
	}
	return (min);
}

int	insert_pos(t_stack *s, int num)
{
	int		i;
	int		start;
	int		min;
	int		max;

	i = 0;
	min = stack_min(s);
	max = stack_max(s);
	start = s->x;
	while ((i == 0 || start != s->x))
	{
		if ((s->x == max && num > max) || \
			(s->prev->x == min && num < min))
			return (i);
		else if (s->x == min && num < min)
			return (i + 1);
		else if (s->x < num && s->prev->x > num)
			return (i);
		s = s->next;
		i++;
	}
	return (i);
}

int	value_at(t_stack *stack, int index)
{
	while (index--)
		stack = stack->next;
	return (stack->x);
}
