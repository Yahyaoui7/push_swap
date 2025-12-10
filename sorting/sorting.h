/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:17:52 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/10 11:42:47 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "../operations/operations.h"
# include "../stack/stack.h"

void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);
void	small_sort(t_stack *a, t_stack *b);

int		find_min_position(t_stack *a);

#endif
