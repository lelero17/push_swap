/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:09:50 by lemmerli          #+#    #+#             */
/*   Updated: 2026/01/17 16:25:23 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		while ((*stack_a)->value != min)
			ra(stack_a);
		pb(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
	return ;
}
