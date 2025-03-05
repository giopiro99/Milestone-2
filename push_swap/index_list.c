/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:56:58 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/03/04 12:57:00 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	sort_list(t_stack **tmp)
{
	t_stack	*stack_v;

	stack_v = (*tmp);
	while (stack_v->next)
	{
		if (stack_v->nbr > stack_v->next->nbr)
		{
			swap(&(stack_v->nbr), &(stack_v->next->nbr));
			stack_v = (*tmp);
		}
		else
			stack_v = stack_v->next;
	}
}

void	ft_index_list(t_stack **a, t_stack **tmp)
{
	t_stack	*head_a;
	t_stack	*head_tmp;
	int		i;

	sort_list(tmp);
	head_a = (*a);
	head_tmp = (*tmp);
	i = 0;
	while (head_a && head_tmp)
	{
		if (head_a->nbr == head_tmp->nbr)
		{
			head_a->index = i;
			i = 0;
			head_tmp = (*tmp);
			head_a = head_a->next;
		}
		else
		{
			i++;
			head_tmp = head_tmp->next;
		}
	}
	free_stack(tmp);
}
