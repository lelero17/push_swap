/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:23:53 by lemmerli          #+#    #+#             */
/*   Updated: 2026/01/30 17:48:03 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_in_chunk(t_stack *stack, int min_idx, int max_idx)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index >= min_idx && tmp->index <= max_idx)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

static int	get_value_at_pos(t_stack *stack, int pos)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		if (i == pos)
			return (tmp->value);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

void	push_chunk(t_stack **a, t_stack **b, int min_idx, int max_idx)
{
	int	chunk_size;
	int	pushed;
	int	pos;

	chunk_size = count_in_chunk(*a, min_idx, max_idx);
	pushed = 0;
	while (pushed < chunk_size)
	{
		pos = find_next_in_chunk(*a, min_idx, max_idx);
		if (pos == -1)
			break ;
		rotate_to_top(a, get_value_at_pos(*a, pos));
		pb(a, b);
		pushed++;
	}
}

static void	rotate_max_to_top_b(t_stack **stack_b)
{
	int	max_pos;
	int	size;

	max_pos = find_max_index(*stack_b);
	size = stack_size(*stack_b);
	if (max_pos <= size / 2)
	{
		while (max_pos > 0)
		{
			rb(stack_b);
			max_pos--;
		}
	}
	else
	{
		while (max_pos != 0)
		{
			rrb(stack_b);
			max_pos = find_max_index(*stack_b);
		}
	}
}

void	chunk_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	chunk_size;
	int	num_chunks;
	int	chunk;

	assign_index(*stack_a);
	size = stack_size(*stack_a);
	chunk_size = get_chunk_size(size);
	num_chunks = (size + chunk_size - 1) / chunk_size;
	chunk = 0;
	while (chunk < num_chunks)
	{
		push_chunk(stack_a, stack_b, chunk * chunk_size,
			chunk * chunk_size + chunk_size - 1);
		chunk++;
	}
	while (*stack_b)
	{
		rotate_max_to_top_b(stack_b);
		pa(stack_a, stack_b);
	}
}
