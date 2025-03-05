/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:57:20 by gpirozzi          #+#    #+#             */
/*   Updated: 2024/12/02 16:25:12 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned_putnbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr(n / 10);
	n = (n % 10) + 48;
	count += write(1, &n, 1);
	return (count);
}
