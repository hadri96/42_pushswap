/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:34:26 by hmorand           #+#    #+#             */
/*   Updated: 2024/01/04 16:34:26 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a)
{
	stack_swap(stack_a);
	write(1, "sa\n", 3);
}

void	rra(t_stack **stack_a)
{
	stack_reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	ra(t_stack **stack_a)
{
	stack_rotate(stack_a);
	write(1, "ra\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	stack_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	stack_rotate(stack_a);
	stack_rotate(stack_b);
	write(1, "rr\n", 3);
}
