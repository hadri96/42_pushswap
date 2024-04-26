/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:29:38 by hmorand           #+#    #+#             */
/*   Updated: 2024/04/22 18:29:38 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_both_up(int _ra, int _rb, t_stack **a, t_stack **b)
{
	int	remaining;

	if (_ra > _rb)
	{
		remaining = _ra - _rb;
		while (_rb--)
			rr(a, b);
		while (remaining--)
			ra(a);
	}
	else
	{
		remaining = _rb - _ra;
		while (_ra--)
			rr(a, b);
		while (remaining--)
			rb(b);
	}
}

void	move_both_down(int _rra, int _rrb, t_stack **a, t_stack **b)
{
	int	remaining;

	if (_rra > _rrb)
	{
		remaining = _rra - _rrb;
		while (_rrb--)
			rrr(a, b);
		while (remaining--)
			rra(a);
	}
	else
	{
		remaining = _rrb - _rra;
		while (_rra--)
			rrr(a, b);
		while (remaining--)
			rrb(b);
	}
}

void	move_a_up_b_down(int _ra, int _rrb, t_stack **a, t_stack **b)
{
	while (_ra--)
		ra(a);
	while (_rrb--)
		rrb(b);
}

void	move_b_up_a_down(int _rra, int _rb, t_stack **a, t_stack **b)
{
	while (_rra--)
		rra(a);
	while (_rb--)
		rb(b);
}
