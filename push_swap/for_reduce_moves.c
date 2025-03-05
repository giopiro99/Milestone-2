/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_reduce_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:26:15 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/03/04 18:06:53 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cost_top(t_stack *stack, t_stack *elem)
{
	int	pos;
	int	size;

	pos = 0;
	size = stack_len(stack);
	while (stack && stack != elem)
	{
		stack = stack->next;
		pos++;
	}
	if (pos <= size / 2)
		return (pos);
	else
		return (size - pos);
}

t_stack	*find_best_move(t_stack *a, t_stack *b)
{
	t_stack	*best;
	t_stack	*current;
	int		best_cost;
	int		current_cost;
	t_stack	*pos_a;

	best = NULL;
	current = b;
	pos_a = NULL;
	best_cost = INT_MAX;
	while (current)
	{
		pos_a = find_insert_position(a, current->nbr);
		if (!pos_a)
			current = current->next;
		current_cost = cost_top(b, current) + cost_top(a, pos_a);
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best = current;
		}
		current = current->next;
	}
	return (best);
}

void	push_best_to_a(t_stack **a, t_stack **b)
{
	t_stack	*best;
	t_stack	*pos_a;

	if (!*b)
		return ;
	best = find_best_move(*a, *b);
	pos_a = NULL;
	if (!best)
		return ;
	pos_a = find_insert_position(*a, best->nbr);
	if (!pos_a)
		return ;
	move_to_top_b(b, best);
	move_to_top(a, pos_a);
	pa(a, b, 1);
}

t_stack	*find_insert_position(t_stack *a, int nbr)
{
	t_stack	*best_pos;
	t_stack	*current;
	t_stack	*max;
	t_stack	*min;

	if (!a)
		return (NULL);
	best_pos = NULL;
	current = a;
	max = find_max(a);
	min = find_min(a);
	if (nbr > max->nbr || nbr < min->nbr)
		return (min);
	while (current)
	{
		if (current->nbr > nbr && (!best_pos || current->nbr < best_pos->nbr))
			best_pos = current;
		current = current->next;
	}
	return (best_pos);
}
