/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:27:24 by lemmerli          #+#    #+#             */
/*   Updated: 2026/01/15 14:47:43 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		num;

	stack = NULL;
	i = 1;
	while(i < argc)
	{
		num = ft_atoi(argv[i]);
		stack_add_back(&stack, stack_new(num));
		i++;
	}
	return(stack);
}