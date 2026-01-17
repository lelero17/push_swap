/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:31:50 by lemmerli          #+#    #+#             */
/*   Updated: 2026/01/17 16:28:15 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	if (!stack)
		return (0);
	min = stack->value;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	stack_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	if (!stack)
		return (0);
	max = stack->value;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	stack_size(t_stack *stack)
{
	int		counter;
	t_stack	*tmp;

	if (!stack)
		return (0);
	counter = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		counter++;
		tmp = tmp->next;
	}
	return (counter);
}

int	stack_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
