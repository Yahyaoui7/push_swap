/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 11:12:21 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/11/30 18:09:47 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	parse_arguments_to_stack(&a, ac, av);
	sort_stack(&a, &b);
	stack_free(&a);
	stack_free(&b);
	return (0);
}
