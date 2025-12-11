/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:17:52 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/11 11:37:34 by nyahyaou         ###   ########.fr       */
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
int		find_index_position(t_stack *stack, int min_idx, int max_idx);
int		find_best_position(t_stack *stack, int min_idx, int max_idx);
void	push_chunk_to_b(t_stack *a, t_stack *b, int min_idx, int max_idx);
int		find_max_position(t_stack *stack);
void	push_back_to_a(t_stack *a, t_stack *b);

void	sorting(t_stack *a, t_stack *b);

#endif
