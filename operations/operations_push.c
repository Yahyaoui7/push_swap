/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 10:12:13 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/09 11:03:05 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

static void	push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	if (from->size == 0)
		return ;
	tmp = from->top;
	from->top = tmp->next;
	from->size--;
	tmp->next = to->top;
	to->top = tmp;
	to->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
