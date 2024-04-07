/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:01:34 by hmorand           #+#    #+#             */
/*   Updated: 2024/04/07 14:01:34 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* int	compute_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	return (i);
} */

void	pushswap(t_stack **a, t_stack **b)
{
	int		index_opt;
	int		i;

	i = 0;
	ra(a);
	ra(a);
	pb(b, a);
	pb(b, a);
	print_stacks(*a, *b);
	while (3 < stack_len(*a))
	{
		index_opt = optimal_cost(*a, *b);
		insert_i(a, b, index_opt);
		i++;
	}
	print_stacks(*a, *b);
	sort_3(a);
	max_at_top(b);
	merge(a, b);
}

int	main(int argc, char *argv[])
{
	char	**numbers_a;
	char	*string;
	t_stack	*a;
	t_stack	*b;

	string = join_strarr(argv, argc);
	ft_printf("%s\n",string);
	numbers_a = ft_split(string, ' ');
	gfree(string);
	a = atos(numbers_a);
	if (a)
	{
		b = NULL;
		print_stack(a, "Stack a");
		pushswap(&a, &b);
		//print_stack(a, "Result");
		//ft_printf("Stack a: %d\nStack b: %d\n", stack_len(a), stack_len(b));
		exit(1);
	}
	else
	{
		write(1, "Error", 5);
		exit(1);
	}
}
