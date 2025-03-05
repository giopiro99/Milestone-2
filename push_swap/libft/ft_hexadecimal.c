/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:13:55 by gpirozzi          #+#    #+#             */
/*   Updated: 2024/12/02 16:32:50 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexadecimal(unsigned int n, const char c)
{
	int		count;
	int		rest;
	char	*upper;
	char	*lower;

	upper = "0123456789ABCDEF";
	lower = "0123456789abcdef";
	count = 0;
	if (c == 'x')
	{
		if (n > 15)
			count += ft_hexadecimal(n / 16, c);
		rest = (n % 16);
		count += write(1, &lower[rest], 1);
	}
	else if (c == 'X')
	{
		if (n > 15)
			count += ft_hexadecimal(n / 16, c);
		rest = (n % 16);
		count += write(1, &upper[rest], 1);
	}
	return (count);
}
