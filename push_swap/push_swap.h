/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:57:32 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/03/04 13:12:15 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				chunk;
	struct s_stack	*next;
}	t_stack;

//for errors
int				error_syntax(char *str);
int				error_duplicate(t_stack *a, int n);
void			free_stack(t_stack **stack);
void			free_errors(t_stack **a, int flag, char **argv);

//utils
t_stack			*find_last(t_stack *stack);
t_stack			*find_max(t_stack *stack);
t_stack			*find_min(t_stack *stack);
t_stack			*best_node(t_stack **a, t_stack **b);
int				stack_len(t_stack *stack);
int				take_min(t_stack *stack);
int				find_index(t_stack *stack, t_stack *node);
int				for2(t_stack **a);
void			init_stack_a(t_stack **a, char **argv, int flag);
void			sort_three(t_stack **a);
void			ft_index_list(t_stack **a, t_stack **tmp);
void			move_to_top(t_stack **a, t_stack *node);
void			move_to_top_b(t_stack **b, t_stack *node);
void			ft_clean_matrix(char **matrix);
bool			stack_sorted(t_stack *stack);

//per chunk
int				assign_chunk(t_stack *stack);
int				find_median(t_stack *stack);
int				move_chunks_to_b(t_stack **a, t_stack **b, int max_chunk);
void			insertion_sort(t_stack **a, t_stack **b);

//reduce moves
int				cost_top(t_stack *stack, t_stack *elem);
int				get_position(t_stack *a, t_stack *node);
t_stack			*find_best_move(t_stack *a, t_stack *b);
t_stack			*find_insert_position(t_stack *a, int nbr);
void			push_best_to_a(t_stack **a, t_stack **b);
void			rotate_a_until_sorted(t_stack **a);

//moves
void			pa(t_stack **a, t_stack **b, int flag);
void			pb(t_stack **a, t_stack **b, int flag);
void			ra(t_stack **a, int flag);
void			rb(t_stack **b, int flag);
void			rr(t_stack **a, t_stack **b, int flag);
void			rra(t_stack **a, int flag);
void			rrb(t_stack **b, int flag);
void			rrr(t_stack **a, t_stack **b, int flag);
void			sa(t_stack **a, int flag);
void			sb(t_stack **b, int flag);
void			ss(t_stack **a, t_stack **b, int flag);

#endif
