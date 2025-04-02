/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 21:26:20 by bakpulat          #+#    #+#             */
/*   Updated: 2025/03/20 12:17:44 by bakpulat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	int				pos;
	int				above_median;
	int				min_mov;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int					error_int(char **argv);
int					error_syntax(char **argv);
int					error_dup(char **argv);
long				ft_atol(char *str);
void				print_error(void);

void				ft_free_stack(t_stack **stack);
void				fill_stack(t_stack **a, char **argv);
t_stack				*ft_last_node(t_stack *stack);
int					is_sorted(t_stack *stack);
int					stack_len(t_stack *stack);
t_stack				*max_node(t_stack *stack);
t_stack				*min_node(t_stack *stack);

void				sa(t_stack **a, int check);
void				sb(t_stack **b, int check);
void				ss(t_stack **a, t_stack **b, int check);
void				pa(t_stack **b, t_stack **a, int check);
void				pb(t_stack **a, t_stack **b, int check);
void				ra(t_stack **a, int check);
void				rb(t_stack **b, int check);
void				rr(t_stack **a, t_stack **b, int check);
void				rra(t_stack **a, int check);
void				rrb(t_stack **b, int check);
void				rrr(t_stack **a, t_stack **b, int check);

void				sort_three(t_stack **a);
void				set_pos(t_stack *stack);
void				set_min_mov(t_stack *a, t_stack *b);
t_stack				*get_best_min_mov(t_stack *stack);
void				best_min_move_on_top(t_stack **stack,
						t_stack *best_min_node, int a);
void				min_on_top(t_stack **a);
void				sort(t_stack **a, t_stack **b);

#endif