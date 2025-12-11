/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:10:09 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/11 22:17:09 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

int	get_chunk_size(int stack_size)
{
	if (stack_size <= 100)
		return (15);
	else if (stack_size <= 500)
		return (35);
	return (50);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	smart_last_chunk(t_stack *a, t_stack *b)
{
	int	top;

	while (!stack_is_sorted(a))
	{
		top = a->top->index;
		if (top == 0)
			ra(a);
		else if (a->top->next && a->top->next->index == 0)
		{
			sa(a);
			ra(a);
		}
		else if (top > 5)
			pb(a, b);
		else
			rra(a);
	}
	while (b->size)
		pa(a, b);
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	chunk;

	size = a->size;
	chunk = get_chunk_size(size);
	push_chunk_to_b(a, b, chunk);
	push_back_to_a(a, b);
}
