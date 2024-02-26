/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:17:47 by hmorand           #+#    #+#             */
/*   Updated: 2024/02/26 12:17:54 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *stack, char *stack_name)
{
	int	i;

	ft_printf("%s\n", stack_name);
	ft_printf("--------\n");
	i = 0;
	for (int start = stack->x; start != stack->x || i == 0; stack = stack->next)
	{
		i++;
		ft_printf("%d\n", stack->x);
	}
	ft_printf("--------\n");
	ft_printf("----------------\n");
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	start_a;
	int	start_b;

	ft_printf("Stack a | Stack b\n--------|--------\n");
	i = -1;
	start_a = stack_a->x;
	start_b = stack_b->x;
	while (++i == 0 || start_a != stack_a->x || start_b != stack_b->x)
	{
		if (i == 0 || start_a != stack_a->x)
		{
			ft_printf("   %d   |", stack_a->x);
			stack_a = stack_a->next;
		}
		else
			ft_printf("       |");
		if (i == 0 || start_b != stack_b->x)
		{
			ft_printf("    %d\n", stack_b->x);
			stack_b = stack_b->next;
		}
		else
			ft_printf("       \n", stack_b->x);
	}
	ft_printf("----------------\n");
}
