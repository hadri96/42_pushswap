/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 17:04:26 by hmorand           #+#    #+#             */
/*   Updated: 2024/04/06 17:07:42 by hmorand          ###   ########.ch       */
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
	pb(b, a);
	pb(b, a);
	while (i < 5)
	{
		index_opt = optimal_cost(*a, *b);
		insert_i(a, b, index_opt);
		i++;
	}
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
		pushswap(&a, &b);
		print_stacks(a, b);
		rr(&a, &b);
		print_stacks(a, b);
		ft_printf("Stack a: %d\nStack b: %d\n", stack_len(a), stack_len(b));
		stack_push(&a, &b);
		print_stacks(a, b);
		ft_printf("Stack a: %d\nStack b: %d\n", stack_len(a), stack_len(b));
		exit(1);
	}
	else
	{
		write(1, "Error", 5);
		exit(1);
	}

}
