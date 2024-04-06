/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 16:05:29 by hmorand           #+#    #+#             */
/*   Updated: 2024/04/06 16:05:29 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	optimal_cost_n(int pos, int ins_pos, t_stack *a, t_stack *b)
{
	int	ra;
	int	rb;
	int	rra;
	int	rrb;

	ra = pos;
	rb = ins_pos;
	rra = stack_len(a) - pos;
	rrb = stack_len(b) - ins_pos;
	return (min(4,
			max(2, ra, rb), \
			max(2, rra, rrb), \
			ra + rrb, \
			rra + rb));
}

int	optimal_cost(t_stack *a, t_stack *b)
{
	int		i;
	int		cost;
	int		best_cost;
	int		best_cost_index;
	int		start;

	i = 0;
	start = a->x;
	best_cost = optimal_cost_n(i, insert_pos(b, a->x), a, b);
	best_cost_index = i;
	while (i == 0 || start != a->x)
	{
		cost = optimal_cost_n(i, insert_pos(b, a->x), a, b);
		if (best_cost > cost)
		{
			best_cost = cost;
			best_cost_index = i;
		}
		a = a->next;
		i++;
	}
	return (best_cost_index);
}

void	insert_i(t_stack **a, t_stack **b, int opt_ind)
{
	int	ins_pos;
	int	mini;
	int	len_a;
	int	len_b;

	len_a = stack_len(*a);
	len_b = stack_len(*b);
	ins_pos = insert_pos(*b, value_at(*a, opt_ind));
	mini = optimal_cost_n(opt_ind, ins_pos, *a, *b);
	if (mini == max(2, opt_ind, ins_pos))
		move_both_up(opt_ind, ins_pos, a, b);
	else if (mini == max(2, len_a - opt_ind, len_b - ins_pos))
		move_both_down(len_a - opt_ind, len_b - ins_pos, a, b);
	else if (mini == opt_ind + len_b - ins_pos)
		move_a_up_b_down(opt_ind, len_b - ins_pos, a, b);
	else if (mini == ins_pos + len_a - opt_ind)
		move_b_up_a_down(len_a - opt_ind, ins_pos, a, b);
	pb(b, a);
}