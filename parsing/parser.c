/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:12:55 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/12 20:04:21 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_numbers(char **numbers, t_stack *a)
{
	int		i;
	long	num;
	t_node	*new;

	i = 0;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]))
			return (0);
		num = ft_atoi_long(numbers[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		if (has_duplicate(a, (int)num))
			return (0);
		new = node_new((int)num);
		if (!new)
			return (0);
		stack_push_bottom(a, new);
		i++;
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack *stack)
{
	char	**numbers;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!argv[i][0] || is_only_spaces(argv[i]))
			return (0);
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			return (0);
		if (!parse_numbers(numbers, stack))
		{
			free_split(numbers);
			return (0);
		}
		free_split(numbers);
		i++;
	}
	return (1);
}
