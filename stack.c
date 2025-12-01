/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:13:57 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/11/30 17:34:58 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = NULL;
	s->size = 0;
}

t_node	*node_new(int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->next = NULL;
	return (n);
}

void	stack_push_top(t_stack *s, t_node *node)
{
	if (!node)
		return ;
	node->next = s->top;
	s->top = node;
	s->size++;
}

void	fill_stack(t_stack *a, int *tab, int n)
{
	int	i;

	i = n - 1;
	while (i >= 0)
	{
		stack_push_top(a, node_new(tab[i]));
		i--;
	}
}
