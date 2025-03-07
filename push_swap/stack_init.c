/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:58:00 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/03/04 15:16:42 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	append_node(t_stack **stack, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = ft_calloc(sizeof(t_stack), 1);
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if (!(*stack))
		*stack = node;
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
	}
}

void	init_stack_a(t_stack **a, char **argv, int flag)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(a, flag, argv);
		n = ft_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a, flag, argv);
		if (error_duplicate((*a), (int)n))
			free_errors(a, flag, argv);
		append_node(a, (int)n);
		i++;
	}
}
