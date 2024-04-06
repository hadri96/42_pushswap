/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atos.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:42:03 by hmorand           #+#    #+#             */
/*   Updated: 2024/04/05 14:42:30 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
