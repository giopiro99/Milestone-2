/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:57:47 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/03/04 12:57:49 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack **head)
{
	t_stack	*current;
	t_stack	*last;
	t_stack	*second_last;

	if (!(*head) || !(*head)->next)
		return ;
	current = *head;
	while (current->next && current->next->next)
		current = current->next;
	second_last = current;
	last = current->next;
	second_last->next = NULL;
	last->next = *head;
	*head = last;
}

void	rra(t_stack **a, int flag)
{
	reverse_rotate(a);
	if (flag)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int flag)
{
	reverse_rotate(b);
	if (flag)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (flag)
		ft_printf("rrr\n");
}
