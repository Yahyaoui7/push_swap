/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:12:55 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/11/30 18:15:44 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicates(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				put_error_and_exit();
			j++;
		}
		i++;
	}
}

int	count_numbers(int ac, char **av)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] && is_space(av[i][j]))
				j++;
			if (!av[i][j])
				break ;
			if (av[i][j] == '+' || av[i][j] == '-')
				j++;
			check_digit(av[i][j]);
			while (av[i][j] && is_digit(av[i][j]))
				j++;
			count++;
		}
		i++;
	}
	return (count);
}

int	parse_one_number(const char *s, int *j)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (s[*j] && is_space(s[*j]))
		(*j)++;
	if (s[*j] == '+' || s[*j] == '-')
	{
		if (s[*j] == '-')
			sign = -1;
		(*j)++;
	}
	if (!s[*j] || !is_digit(s[*j]))
		put_error_and_exit();
	while (s[*j] && is_digit(s[*j]))
	{
		res = res * 10 + (s[*j] - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			put_error_and_exit();
		(*j)++;
	}
	return ((int)(res * sign));
}

void	fill_numbers(int ac, char **av, int *arr)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] && is_space(av[i][j]))
				j++;
			if (!av[i][j])
				break ;
			arr[k++] = parse_one_number(av[i], &j);
		}
		i++;
	}
}

int	parse_arguments_to_stack(t_stack *a, int ac, char **av)
{
	int	count;
	int	*arr;

	count = count_numbers(ac, av);
	arr = malloc(sizeof(int) * count);
	if (!arr)
		put_error_and_exit();
	fill_numbers(ac, av, arr);
	check_duplicates(arr, count);
	fill_stack(a, arr, count);
	free(arr);
	return (1);
}
