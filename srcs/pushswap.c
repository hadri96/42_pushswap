/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 09:40:30 by hmorand           #+#    #+#             */
/*   Updated: 2024/04/26 09:40:30 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_stack *a)
{
	int	start;

	if (stack_len(a) == 1)
		return (true);
	start = a->x;
	a = a->next;
	if (start > a->x)
		return (false);
	while (a->x != start && a->next->x > a->x)
			a = a->next;
	if (a->next->x == start)
		return (true);
	return (false);
}

void	pushswap(t_stack **a, t_stack **b)
{
	int		index_opt;

	pb(b, a);
	pb(b, a);
	//print_stacks(*a, *b);
	while (3 < stack_len(*a))
	{
		index_opt = optimal_cost(*a, *b);
		insert_i(a, b, index_opt);
	}
	sort_3(a);
	max_at_top(b);
	if (is_sorted(*b))
		rrb(b);
	merge(a, b);
}

int	main(int argc, char *argv[])
{
	char	**numbers_a;
	char	*string;
	t_stack	*a;
	t_stack	*b;

	string = join_strarr(argv, argc);
	numbers_a = ft_split(string, ' ');
	if (argc == 1)
		exit(1);
	a = atos(numbers_a);
	if (a != NULL || stack_len(a) > 0)
	{
		b = NULL;
		if (is_sorted(a))
			exit(1);
		else if (stack_len(a) == 3)
			sort_3(&a);
		else
			pushswap(&a, &b);
	}
	else
		write(2, "Error\n", 6);
	//print_stack(a, "Stack a");
	exit(1);
}
