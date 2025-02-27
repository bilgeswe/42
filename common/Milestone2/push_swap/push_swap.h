/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:23:23 by bakpulat          #+#    #+#             */
/*   Updated: 2025/02/27 11:23:28 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

void					free_split(char **split);
void					init_a_stack(t_stack_node **a, char **argv);
void					append_node(t_stack_node **stack, int n);
t_stack_node			*find_last_node(t_stack_node *stack);
int						is_number_out_of_range(const char *str);
long					ft_atol(const char *str);
bool					syntax_error(char *str);
bool					duplicate_error(t_stack_node *a, long nbr);
void					free_stack(t_stack_node **stack);
void					free_error(t_stack_node **stack);
bool					stack_is_sorted(t_stack_node *a);
int						stack_len(t_stack_node *a);
int						find_index(const t_stack_node *stack, int nbr);
int						find_min_val(t_stack_node *stack);
t_stack_node			*ft_lstlast(t_stack_node *lst);
void					sort_three(t_stack_node **a);
t_stack_node			*find_max(t_stack_node *stack);
void					sort_above_three(t_stack_node **a);
void					sort_push_to_b(t_stack_node **a, t_stack_node **b);
void					sort_push_to_a(t_stack_node **a, t_stack_node **b);
void					min_to_top(t_stack_node **a);
int						min_nbr(t_stack_node *a);
int						max_nbr(t_stack_node *a);
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrb(t_stack_node **b, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					pa(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **a, t_stack_node **b, bool print);
int						find_cheapest_ab(t_stack_node *a, t_stack_node *b);
int						find_place_for_b(t_stack_node *stack_b, int nbr_push);
int						calc_right_rotate_ab(t_stack_node *a, t_stack_node *b,
							int nbr);
int						do_left_ab(t_stack_node **a, t_stack_node **b, int nbr);
int						calc_left_rotate_ab(t_stack_node *b, t_stack_node *a,
							int nbr);
int						do_right_ab(t_stack_node **a, t_stack_node **b,
							int nbr);
int						do_right_ba(t_stack_node **b, t_stack_node **a,
							int nbr);
int						calc_right_rotate_ba(t_stack_node *b, t_stack_node *a,
							int nbr);
int						calc_left_rotate_ba(t_stack_node *b, t_stack_node *a,
							int nbr);
int						do_left_ba(t_stack_node **b, t_stack_node **a, int nbr);
int						find_cheapest_ba(t_stack_node *a, t_stack_node *b);
int						find_place_for_a(t_stack_node *stack_a, int nbr_push);
int						process_input(int argc, char **argv, t_stack_node **a);
void					handle_sort(t_stack_node **a);

#endif
