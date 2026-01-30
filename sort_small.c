/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:09:50 by lemmerli          #+#    #+#             */
/*   Updated: 2026/01/30 13:11:53 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_top(t_stack **stack, int value)
{
	int	pos;
	int size;

	pos = find_position(*stack, value);
	size = stack_size(*stack);

	if (pos <= size / 2)
	{
		while((*stack)->value != value)
			ra(stack);
	}
	else
	{
		while((*stack)->value != value)
			rra(stack);
	}
}

void	sort_two(t_stack **stack_a)
{
	int	first;
	int	second;

	if (stack_size(*stack_a) < 2)
		return ;
	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	if (first > second)
		sa(stack_a);
	return ;
}

void	sort_three(t_stack **stack_a)
{
	int	max;
	int	first;
	int	second;

	if (stack_size(*stack_a) < 3)
		return ;
	max = stack_max(*stack_a);
	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	if (first == max)
		ra(stack_a);
	else if (second == max)
		rra(stack_a);
	sort_two(stack_a);
	return ;
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	size;

	size = stack_size(*stack_a);
	while (size > 3)
	{
		min = stack_min(*stack_a);
		rotate_to_top(stack_a, min);
		pb(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
	return ;
}
