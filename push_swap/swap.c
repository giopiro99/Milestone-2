/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:58:06 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/03/04 12:58:08 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*head) || !(*head)->next)
		return ;
	first = (*head);
	second = (*head)->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	sa(t_stack **a, int flag)
{
	if (!a)
		return ;
	swap(a);
	if (flag)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int flag)
{
	if (!b)
		return ;
	swap(b);
	if (flag)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, int flag)
{
	if (!a || !b)
		return ;
	swap(a);
	swap(b);
	if (flag)
		ft_printf("ss\n");
}
