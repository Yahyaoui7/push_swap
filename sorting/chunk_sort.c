/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 21:10:09 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/12 11:34:30 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"

int	get_chunk_size(int stack_size)
{
	if (stack_size <= 100)
		return (15);
	else if (stack_size <= 500)
		return (35);
	return (50);
}

void	chunk_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	chunk;

	size = a->size;
	chunk = get_chunk_size(size);
	push_chunk_to_b(a, b, chunk);
	push_back_to_a(a, b);
}
