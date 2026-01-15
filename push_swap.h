/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:06:36 by lemmerli          #+#    #+#             */
/*   Updated: 2026/01/15 15:27:55 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack *next;
}	t_stack;

// Stack utils
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_free(t_stack **stack);

// Input validation
t_stack	*parse_input(int argc, char **argv);

// Utils
int		ft_atoi(char *str);

#endif