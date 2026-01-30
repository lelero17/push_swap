/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:03:01 by lemmerli          #+#    #+#             */
/*   Updated: 2026/01/30 12:01:26 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	choose_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	validate_input(argc, argv);
	stack_a = parse_input(argc, argv);
	stack_b = NULL;
	size = stack_size(stack_a);
	if (stack_sorted(stack_a) || size < 2)
	{
		stack_free(&stack_a);
		return (0);
	}
	choose_sort(&stack_a, &stack_b, size);
	stack_free (&stack_a);
	stack_free (&stack_b);
	return (0);
}
