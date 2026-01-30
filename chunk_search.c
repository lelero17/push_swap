/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:49:30 by lemmerli          #+#    #+#             */
/*   Updated: 2026/01/30 16:50:21 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_in_chunk(int index, int min_idx, int max_idx)
{
	return (index >= min_idx && index <= max_idx);
}

static int	calculate_cost(int pos, int size)
{
	if (pos <= size - pos)
		return (pos);
	return (size - pos);
}

static void	update_best(int pos, int cost, int *best_pos, int *best_cost)
{
	if (cost < *best_cost)
	{
		*best_cost = cost;
		*best_pos = pos;
	}
}

int	find_next_in_chunk(t_stack *stack, int min_idx, int max_idx)
{
	int		best_pos;
	int		best_cost;
	int		size;
	int		pos;
	t_stack	*tmp;

	if (!stack)
		return (-1);
	best_pos = -1;
	best_cost = 999999;
	size = stack_size(stack);
	pos = 0;
	tmp = stack;
	while (tmp)
	{
		if (is_in_chunk(tmp->index, min_idx, max_idx))
			update_best(pos, calculate_cost(pos, size), &best_pos, &best_cost);
		pos++;
		tmp = tmp->next;
	}
	return (best_pos);
}
