/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:03:13 by hmorand           #+#    #+#             */
/*   Updated: 2024/04/06 16:03:13 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **stack_b)
{
	stack_swap(stack_b);
	write(1, "sb\n", 3);
}

void	rrb(t_stack **stack_b)
{
	stack_reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rb(t_stack **stack_b)
{
	stack_rotate(stack_b);
	write(1, "rb\n", 3);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	stack_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}

void	rrr(t_stack **stack_b, t_stack **stack_a)
{
	stack_reverse_rotate(stack_a);
	stack_reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
