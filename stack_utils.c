/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:19:39 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/11/30 11:20:37 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack *s)
{
	t_node	*tmp;

	while (s->top)
	{
		tmp = s->top->next;
		free(s->top);
		s->top = tmp;
	}
	s->size = 0;
}

int	stack_is_sorted(t_stack *a)
{
	t_node	*cur;

	cur = a->top;
	while (cur && cur->next)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

t_node	*stack_last(t_stack *s)
{
	t_node	*cur;

	if (!s->top)
		return (NULL);
	cur = s->top;
	while (cur->next)
		cur = cur->next;
	return (cur);
}
