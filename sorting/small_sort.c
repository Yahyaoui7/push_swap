/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:16:17 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/11 22:21:08 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	sort_2(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_3(t_stack *a)
{
	int	x;
	int	y;
	int	z;

	x = a->top->value;
	y = a->top->next->value;
	z = a->top->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > z && y < z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

void	sort_4(t_stack *a, t_stack *b)
{
	int	pos;

	pos = find_min_position(a);
	if (pos == 1)
		ra(a);
	else if (pos == 2)
	{
		ra(a);
		ra(a);
	}
	else if (pos == 3)
		rra(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

static void	bring_min_top(t_stack *a)
{
	int	pos;

	pos = find_min_position(a);
	if (pos > (a->size - 1) / 2)
	{
		pos = a->size - pos;
		while (pos--)
			rra(a);
	}
	else
		while (pos--)
			ra(a);
}

void	sort_5(t_stack *a, t_stack *b)
{
	bring_min_top(a);
	pb(a, b);
	bring_min_top(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
