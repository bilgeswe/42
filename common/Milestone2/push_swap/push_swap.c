/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:24:35 by jbyrne            #+#    #+#             */
/*   Updated: 2025/02/27 15:38:47 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_sort(t_stack_node **a)
{
	if (stack_len(*a) == 2)
		sa(a, false);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		sort_above_three(a);
}

int	process_input(int argc, char **argv, t_stack_node **a)
{
	char	**split_argv;

	if (argc == 2)
	{
		split_argv = ft_split(argv[1], ' ');
		if (!split_argv)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		init_a_stack(a, split_argv);
		free_split(split_argv);
	}
	else
		init_a_stack(a, argv + 1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;

	a = NULL;
	if (argc == 1)
		return (1);
	if (process_input(argc, argv, &a))
		return (1);
	if (!stack_is_sorted(a))
		handle_sort(&a);
	free_stack(&a);
	return (0);
}

void	free_split(char **split)
{
	char	**temp;

	if (split == NULL)
		return ;
	temp = split;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(split);
}
