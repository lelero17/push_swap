/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_val.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemmerli <lemmerli@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:27:24 by lemmerli          #+#    #+#             */
/*   Updated: 2026/01/16 12:12:11 by lemmerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void error_exit(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int is_number(char *str)
{
	int i;
	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i = 1;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_int_range(char *str)
{
	long long num;

	num = ft_atoi(str);
	if (num > INT_MAX || num < INT_MIN)
		return(0);
	return(1);
}

int check_dup(int argc, char **argv)
{
	int i;
	int j;
	long long num_i;
	long long num_j;
	
	i = 1;
	while (i < argc - 1)
	{
		num_i = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			num_j = ft_atoi(argv[j]);
			if (num_i == num_j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int validate_input(int argc, char **argv)
{
	int i;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			error_exit();
		if (!is_int_range(argv[i]))
			error_exit();
		i++;
	}
	if (!check_dup(argc, argv))
		error_exit();
	return (1);
}