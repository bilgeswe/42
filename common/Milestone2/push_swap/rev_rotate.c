/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:39:05 by bakpulat          #+#    #+#             */
/*   Updated: 2025/02/27 11:39:08 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack_node **a, bool print)
{
	t_stack_node	*tmp;
	int				i;

	i = 0;
	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while ((*a)->next != NULL)
	{
		*a = (*a)->next;
		i++;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool print)
{
	t_stack_node	*tmp;
	int				i;

	i = 0;
	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while ((*b)->next != NULL)
	{
		*b = (*b)->next;
		i++;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (!print)
		write(1, "rrb\n", 4);
}

void	ft_rrb(t_stack_node **b)
{
	t_stack_node	*tmp;
	int				i;

	i = 0;
	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while ((*b)->next != NULL)
	{
		*b = (*b)->next;
		i++;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	write(1, "rrb\n", 4);
}

static void	ft_rrr_help(t_stack_node **b, bool print)
{
	t_stack_node	*tmp;
	int				i;

	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (!print)
		write(1, "rrr\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	t_stack_node	*tmp;
	int				i;

	if (!*a || !((*a)->next) || !*b || !(*b)->next)
		return ;
	i = 0;
	tmp = *a;
	while ((*a)->next)
	{
		i++;
		*a = (*a)->next;
	}
	(*a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (!print)
		ft_rrr_help(b, false);
	else
		ft_rrr_help(b, true);
}
