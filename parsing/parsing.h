/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyahyaou <nyahyaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:18:18 by nyahyaou          #+#    #+#             */
/*   Updated: 2025/12/12 17:37:46 by nyahyaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../stack/stack.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

int		parse_arguments(int argc, char **argv, t_stack *stack);
int		parse_numbers(char **numbers, t_stack *a);

int		is_valid_number(char *str);
int		is_only_spaces(char *str);
int		has_duplicate(t_stack *stack, int value);

char	**ft_split(char const *s, char c);

long	ft_atoi_long(const char *str);
int		ft_isdigit(int c);
void	free_split(char **split);
void	print_error(void);

#endif
