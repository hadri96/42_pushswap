/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:25:31 by hmorand           #+#    #+#             */
/*   Updated: 2024/02/26 11:25:31 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_len(t_stack *stack)
{
	int	i;
	int	start;

	if (!stack)
		return (0);
	i = 0;
	start = stack->x;
	stack = stack->next;
	while (stack->x != start || i++ == 0)
		stack = stack->next;
	return (i);
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
