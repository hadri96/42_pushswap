/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorand <hmorand@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:34:27 by hmorand           #+#    #+#             */
/*   Updated: 2024/02/26 12:43:11 by hmorand          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* int	compute_cost(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	return (i);
} */

int	main(int argc, char *argv[])
{
	char	**numbers_a;
	char	*string;
	t_stack	*stack_a;
	t_stack	*stack_b;

	string = join_strarr(argv, argc);
	ft_printf("%s\n",string);
	numbers_a = ft_split(string, ' ');
	gfree(string);
	stack_a = atos(numbers_a);
	if (stack_a)
	{
		stack_b = NULL;
		print_stack(stack_a, "Stack a");
		printf("Stack push\n");
		stack_push(&stack_a, &stack_b);
		stack_push(&stack_a, &stack_b);
		stack_push(&stack_a, &stack_b);
		print_stacks(stack_a, stack_b);
		printf("Stack swap\n");
		stack_swap(&stack_a);
		print_stack(stack_a, "Stack a");
		printf("Stack reverse rotate\n");
		stack_reverse_rotate(&stack_a);
		print_stack(stack_a, "Stack a");
		printf("Stack rotate\n");
		stack_rotate(&stack_a);
		print_stack(stack_a, "Stack a");
		stack_clear(&stack_a, stack_len(stack_a));
		stack_clear(&stack_b, stack_len(stack_b));
		exit(1);
	}
	else
	{
		write(1, "Error", 5);
		exit(1);
	}

}
