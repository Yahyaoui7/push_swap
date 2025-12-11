/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:27:57 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/11 17:40:07 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

int	find_min_position(t_stack *a)
{
	int		pos;
	int		i;
	int		min;
	t_node	*cur;

	pos = 0;
	i = 0;
	min = a->top->value;
	cur = a->top;
	while (cur)
	{
		if (cur->value < min)
		{
			min = cur->value;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

void	sort_big(t_stack *a, t_stack *b)
{
	chunk_sort(a, b);
}

void	sorting(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size <= 5)
		sort_5(a, b);
	else
		sort_big(a, b);
}
