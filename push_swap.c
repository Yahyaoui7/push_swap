/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:12:21 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/12 21:19:39 by nyahyaou         ###   ########.fr       */
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
	if (!normalize_stack(a))
		return (1);
	sorting(a, b);
	stack_free(a);
	stack_free(b);
}
