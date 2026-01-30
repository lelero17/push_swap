/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:14:56 by lemmerli          #+#    #+#             */
/*   Updated: 2026/01/30 11:36:11 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	current = stack;
	while (current != NULL)
	{
		index = 0;
		compare = stack;
		while (compare != NULL)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
	return ;
}

int	get_max_bits(t_stack *stack)
{
	int		max_index;
	int		bits;
	t_stack	*tmp;

	max_index = 0;
	bits = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	while (max_index > 0)
	{
		max_index = max_index / 2;
		bits++;
	}
	return (bits);
}

int	get_bit(int num, int bit_pos)
{
	return ((num >> bit_pos) & 1);
}

static void	radix_bit(t_stack **stack_a, t_stack **stack_b, int bit, int size)
{
	int	i;
	int	current_bit;

	i = 0;
	while (i < size)
	{
		current_bit = get_bit((*stack_a)->index, bit);
		if (current_bit == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	return ;
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	size;
	int	bit;

	assign_index(*stack_a);
	max_bits = get_max_bits(*stack_a);
	size = stack_size(*stack_a);
	bit = 0;
	while (bit < max_bits)
	{
		radix_bit(stack_a, stack_b, bit, size);
		while (*stack_b)
			pa(stack_a, stack_b);
		bit++;
	}
	return ;
}
