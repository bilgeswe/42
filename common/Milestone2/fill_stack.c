/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:25:43 by bakpulat          #+#    #+#             */
/*   Updated: 2025/03/20 12:17:37 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_stack **a, int num)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!a)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->num = num;
	new_node->next = NULL;
	if (!(*a))
	{
		*a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_last_node(*a);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	fill_stack(t_stack **a, char **argv)
{
	int	num;
	int	i;

	i = 1;
	while (argv[i])
	{
		num = (int)ft_atol(argv[i]);
		append_node(a, num);
		i++;
	}
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*next;

	if (*stack && stack)
	{
		temp = *stack;
		while (temp)
		{
			next = temp->next;
			free(temp);
			temp = next;
		}
		*stack = NULL;
	}
}
