/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:06:36 by lemmerli          #+#    #+#             */
/*   Updated: 2026/01/16 20:28:26 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// Stack utils
t_stack		*stack_new(int value);
void		stack_add_back(t_stack **stack, t_stack *new);
void		stack_free(t_stack **stack);

// Input parsing
t_stack		*parse_input(int argc, char **argv);

// Input validation
void		error_exit(void);
int			is_number(char *str);
int			is_int_range(char *str);
int			check_dup(int argc, char **argv);
int			validate_input(int argc, char **argv);

// Operation swap
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);

// Operation push
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);

// Operation rotate
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);

// Operation reverse
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

// Utils
long long	ft_atoi(char *str);

#endif