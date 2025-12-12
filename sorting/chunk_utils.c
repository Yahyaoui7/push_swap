/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:11:09 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/12 11:35:56 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

void	push_chunk_to_b(t_stack *a, t_stack *b, int chunk)
{
	int	pushed;

	pushed = 0;
	while (a->top)
	{
		if (a->top->index <= pushed)
		{
			pb(a, b);
			rb(b);
			pushed++;
		}
		else if (a->top->index > pushed && a->top->index <= pushed + chunk)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
}

int	find_max_position(t_stack *stack)
{
	int		pos;
	int		max_pos;
	int		max_idx;
	t_node	*tmp;

	pos = 0;
	max_pos = 0;
	max_idx = -1;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->index > max_idx)
		{
			max_idx = tmp->index;
			max_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
	return (max_pos);
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	size;
	int	max_pos;

	while (b->size > 0)
	{
		size = b->size;
		max_pos = find_max_position(b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(b);
		}
		else
		{
			while (max_pos++ < size)
				rrb(b);
		}
		pa(a, b);
	}
}
