/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:56:16 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/03/04 17:02:01 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack *a, t_stack *node)
{
	int	pos;

	pos = 0;
	while (a && a != node)
	{
		a = a->next;
		pos++;
	}
	return (pos);
}

void	rotate_a_until_sorted(t_stack **a)
{
	t_stack	*min;
	int		pos;
	int		size;

	size = stack_len(*a);
	min = find_min(*a);
	pos = get_position(*a, min);
	if (pos <= size / 2)
	{
		while (*a != min)
			ra(a, 1);
	}
	else
	{
		while (*a != min)
			rra(a, 1);
	}
}

int	for2(t_stack **a)
{
	if (stack_len(*a) == 2)
	{
		if ((*a)->nbr > (*a)->next->nbr)
		{
			sa(a, 1);
			free_stack(a);
			return (1);
		}
		else
		{
			free_stack(a);
			return (1);
		}
	}
	return (0);
}

void	insertion_sort(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*max;

	i = 0;
	max = NULL;
	if (for2(a) == 0)
	{
		while (stack_len(*a) > 3)
		{
			if (i % 2 == 0)
				pb(a, b, 1);
			else
			{
				max = find_max(*a);
				move_to_top(a, max);
				pb(a, b, 1);
			}
			i++;
		}
		sort_three(a);
		while (*b)
			push_best_to_a(a, b);
		return (rotate_a_until_sorted(a), free_stack(b), free_stack(a));
	}
	return ;
}
