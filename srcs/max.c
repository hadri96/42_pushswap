/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:29:20 by hmorand           #+#    #+#             */
/*   Updated: 2024/04/22 18:29:23 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(int count, ...)
{
	int		max_value;
	int		current_value;
	int		i;
	va_list	args;

	va_start(args, count);
	i = 0;
	max_value = va_arg(args, int);
	while (++i < count)
	{
		current_value = va_arg(args, int);
		if (current_value > max_value)
		{
			max_value = current_value;
		}
	}
	va_end(args);
	return (max_value);
}

int	min(int count, ...)
{
	int		min_value;
	int		current_value;
	int		i;
	va_list	args;

	va_start(args, count);
	i = 0;
	min_value = va_arg(args, int);
	while (++i < count)
	{
		current_value = va_arg(args, int);
		if (current_value < min_value)
		{
			min_value = current_value;
		}
	}
	va_end(args);
	return (min_value);
}
