/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 16:27:23 by lemmerli          #+#    #+#             */
/*   Updated: 2026/02/08 12:31:33 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(int size)
{
	if (size <= 20)
		return (5);
	else if (size <= 50)
		return (8);
	else if (size <= 100)
		return (18);
	return (20);
}

int	find_max_index(t_stack *stack_b)
{
	int		max_index;
	int		max_pos;
	int		pos;
	t_stack	*tmp;

	if (!stack_b)
		return (0);
	max_index = -1;
	max_pos = 0;
	pos = 0;
	tmp = stack_b;
	while (tmp)
	{
		if (tmp->index > max_index)
		{
			max_index = tmp->index;
			max_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (max_pos);
}
