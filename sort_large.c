/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 16:14:56 by lemmerli          #+#    #+#             */
/*   Updated: 2026/01/26 17:29:55 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack *compare;
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