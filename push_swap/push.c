/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:57:39 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/03/04 12:57:42 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **dst, t_stack **src)
{
	t_stack	*push_node;

	if (!src || !(*src))
		return ;
	push_node = *src;
	*src = (*src)->next;
	push_node->next = *dst;
	*dst = push_node;
}

void	pa(t_stack **a, t_stack **b, int flag)
{
	push(a, b);
	if (flag)
		ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b, int flag)
{
	push(b, a);
	if (flag)
		ft_printf("pb\n");
}
