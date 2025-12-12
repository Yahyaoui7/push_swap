/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 18:05:18 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/12 19:05:04 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = stack_init();
	b = stack_init();
	if (!a || !b || !parse_arguments(ac, av, a))
	{
		if (!parse_arguments(ac, av, a))
			print_error();
		stack_free(a);
		stack_free(b);
		return (1);
	}
	read_and_apply(a, b);
	if (stack_is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_free(a);
	stack_free(b);
	return (0);
}
