/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:03:01 by lemmerli          #+#    #+#             */
/*   Updated: 2026/01/16 12:12:38 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d -> ", stack->value);
		stack = stack->next;
	}
	printf("NULL\n");
}

int main(int argc, char **argv)
{
	t_stack *stack_a;

	if (argc < 2)
		return (0);
	validate_input(argc, argv);
	stack_a = parse_input(argc, argv);
	print_stack(stack_a);
	stack_free(&stack_a);
	return (0);
}

