/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:06:02 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/10 17:55:11 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

t_node				*node_new(int value);
t_stack				*stack_init(void);
void				stack_push_bottom(t_stack *s, t_node *node);


void				stack_free(t_stack *s);
int					stack_is_sorted(t_stack *a);
t_node				*stack_last(t_stack *s);
#endif
