/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:58:15 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/03/04 12:58:17 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(t_stack *stack, t_stack *node)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->nbr == node->nbr)
			return (index);
		stack = stack->next;
		index++;
	}
	return (-1);
}

void	move_to_top(t_stack **a, t_stack *node)
{
	int	index;
	int	size;

	size = stack_len(*a);
	index = find_index(*a, node);
	if (index == -1)
		return ;
	if (index == 0)
		return ;
	if (index <= size / 2)
	{
		while ((*a) != node)
			ra(a, 1);
	}
	else
	{
		while ((*a) != node)
			rra(a, 1);
	}
}

void	move_to_top_b(t_stack **b, t_stack *node)
{
	int	index;
	int	size;

	size = stack_len(*b);
	index = find_index(*b, node);
	if (index == -1)
		return ;
	if (index == 0)
		return ;
	if (index <= size / 2)
	{
		while ((*b) != node)
			rb(b, 1);
	}
	else
	{
		while ((*b) != node)
			rrb(b, 1);
	}
}

void	sort_three(t_stack **a)
{
	t_stack	*biggest;
	t_stack	*min;

	biggest = find_max(*a);
	min = find_min(*a);
	if (stack_sorted(*a) || for2(a) == 1)
		return ;
	if ((*a)->nbr == biggest->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
	{
		ra(a, 1);
		sa(a, 1);
	}
	else if ((*a)->next->nbr == biggest->nbr && (*a)->nbr == min->nbr)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if ((*a)->next->next->nbr == min->nbr && (*a)->nbr != biggest->nbr)
		rra(a, 1);
	else if ((*a)->next->next->nbr == biggest->nbr && (*a)->nbr != min->nbr)
		sa(a, 1);
	else if ((*a)->nbr == biggest->nbr && (*a)->next->next->nbr != min->nbr)
		ra(a, 1);
}

void	ft_clean_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
