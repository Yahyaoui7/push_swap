/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:13:57 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/10 20:36:16 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_init(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->top = NULL;
	s->size = 0;
	return (s);
}

t_node	*node_new(int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->index = -1;
	n->next = NULL;
	return (n);
}

void	stack_push_bottom(t_stack *s, t_node *node)
{
	t_node	*cur;

	if (!node)
		return ;
	if (!s->top)
		s->top = node;
	else
	{
		cur = stack_last(s);
		cur->next = node;
	}
	s->size++;
}
