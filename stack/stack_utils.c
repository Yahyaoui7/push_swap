/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:19:39 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/09 14:29:12 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_free(t_stack *s)
{
	t_node	*cur;
	t_node	*next;

	if (!s)
		return ;
	cur = s->top;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(s);
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
