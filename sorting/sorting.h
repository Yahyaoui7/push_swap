/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:17:52 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/12 11:37:43 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "../operations/operations.h"
# include "../stack/stack.h"

int		find_min_position(t_stack *a);
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);

void	chunk_sort(t_stack *a, t_stack *b);
void	push_chunk_to_b(t_stack *a, t_stack *b, int chunk);
int		find_max_position(t_stack *stack);
void	push_back_to_a(t_stack *a, t_stack *b);

void	sorting(t_stack *a, t_stack *b);

#endif
