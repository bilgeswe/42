/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:20:56 by jbyrne            #+#    #+#             */
/*   Updated: 2025/02/27 11:39:55 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_is_sorted(t_stack_node *stack)
{
	t_stack_node	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->nbr > temp->next->nbr)
			return (false);
		temp = temp->next;
	}
	return (true);
}

int	stack_len(t_stack_node *stack)
{
	int	node_count;

	if (!stack)
		return (0);
	node_count = 0;
	while (stack)
	{
		stack = stack->next;
		node_count++;
	}
	return (node_count);
}

int	find_index(const t_stack_node *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack->nbr != nbr)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	find_min_val(t_stack_node *stack)
{
	t_stack_node	*current;
	int				min_val;

	current = stack;
	min_val = current->nbr;
	while (current != NULL)
	{
		if (current->nbr < min_val)
			min_val = current->nbr;
		current = current->next;
	}
	return (min_val);
}

t_stack_node	*ft_lstlast(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
