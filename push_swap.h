/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:06:30 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/11/30 17:30:17 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

/* ============================= */
/*       NODE / STACK TYPES      */
/* ============================= */

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

/* ============================= */
/*            PARSER             */
/* ============================= */

int					is_digit(char c);
int					is_space(char c);
void				check_digit(char c);
void				check_duplicates(int *arr, int n);

int					count_numbers(int ac, char **av);
int					parse_one_number(const char *s, int *j);
void				fill_numbers(int ac, char **av, int *arr);

int					parse_arguments_to_stack(t_stack *a, int ac, char **av);
void				put_error_and_exit(void);

/* ============================= */
/*             STACK             */
/* ============================= */

t_node				*node_new(int value);
void				stack_init(t_stack *s);
void				stack_push_top(t_stack *s, t_node *node);
void				fill_stack(t_stack *a, int *arr, int count);

/* ============================= */
/*         STACK  UTILS          */
/* ============================= */

void				stack_free(t_stack *s);
int					stack_is_sorted(t_stack *a);
t_node				*stack_last(t_stack *s);

/* ============================= */
/*           OPERATIONS          */
/* ============================= */

/* swap */
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

/* push */
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

/* rotate */
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

/* reverse rotate */
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

/* ============================= */
/*           ALGORITHM           */
/* ============================= */

void				sort_stack(t_stack *a, t_stack *b);

#endif
