/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:57:54 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/03/04 16:36:03 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*head) || !(*head)->next)
		return ;
	first = *head;
	last = find_last(*head);
	*head = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_stack **a, int flag)
{
	rotate(a);
	if (flag)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int flag)
{
	rotate(b);
	if (flag)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, int flag)
{
	rotate(a);
	rotate(b);
	if (flag)
		ft_printf("rr\n");
}
