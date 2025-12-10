/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:12:55 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/10 17:55:25 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	has_duplicate(t_stack *stack, int value)
{
	t_node	*cur;

	if (!stack)
		return (0);
	cur = stack->top;
	while (cur)
	{
		if (cur->value == value)
			return (1);
		cur = cur->next;
	}
	return (0);
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

void	print_error(void)
{
	char	*arr;

	arr = "Error\n";
	write(2, arr, ft_strlen(arr));
}
