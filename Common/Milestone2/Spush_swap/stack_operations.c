/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                  :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>           +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:03:00 bakpulat             #+#    #+#             */
/*   Updated: 2024/02/07 12:03:00 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **a)
{
    t_stack *first;
    t_stack *second;

    if (*a && (*a)->next)
    {
        first = *a;
        second = (*a)->next;
        first->next = second->next;
        second->next = first;
        *a = second;
        write(1, "sa\n", 3);
    }
}

void sb(t_stack **b)
{
    t_stack *first;
    t_stack *second;

    if (*b && (*b)->next)
    {
        first = *b;
        second = (*b)->next;
        first->next = second->next;
        second->next = first;
        *b = second;
        write(1, "sb\n", 3);
    }
}

void ss(t_stack **a, t_stack **b)
{
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
}

void pa(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (*b)
    {
        temp = *b;
        *b = (*b)->next;
        temp->next = *a;
        *a = temp;
        write(1, "pa\n", 3);
    }
}

void pb(t_stack **a, t_stack **b)
{
    t_stack *temp;

    if (*a)
    {
        temp = *a;
        *a = (*a)->next;
        temp->next = *b;
        *b = temp;
        write(1, "pb\n", 3);
    }
}

void ra(t_stack **a)
{
    t_stack *first;
    t_stack *last;

    if (*a && (*a)->next)
    {
        first = *a;
        *a = first->next;
        last = *a;
        while (last->next)
            last = last->next;
        last->next = first;
        first->next = NULL;
        write(1, "ra\n", 3);
    }
}

void rb(t_stack **b)
{
    t_stack *first;
    t_stack *last;

    if (*b && (*b)->next)
    {
        first = *b;
        *b = first->next;
        last = *b;
        while (last->next)
            last = last->next;
        last->next = first;
        first->next = NULL;
        write(1, "rb\n", 3);
    }
}

void rr(t_stack **a, t_stack **b)
{
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
}

void rra(t_stack **a)
{
    t_stack *prev;
    t_stack *last;

    if (*a && (*a)->next)
    {
        prev = NULL;
        last = *a;
        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
        last->next = *a;
        *a = last;
        write(1, "rra\n", 4);
    }
}

void rrb(t_stack **b)
{
    t_stack *prev;
    t_stack *last;

    if (*b && (*b)->next)
    {
        prev = NULL;
        last = *b;
        while (last->next)
        {
            prev = last;
            last = last->next;
        }
        prev->next = NULL;
        last->next = *b;
        *b = last;
        write(1, "rrb\n", 4);
    }
}

void rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
}
