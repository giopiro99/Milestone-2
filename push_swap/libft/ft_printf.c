/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:19:57 by gpirozzi          #+#    #+#             */
/*   Updated: 2024/12/17 12:17:58 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_format(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == '%')
		i += ft_putchar('%');
	else if (*format == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (*format == 'p')
		i += ft_forpointer(va_arg(args, void *));
	else if (*format == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (*format == 'u')
		i += ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X')
		i += ft_hexadecimal(va_arg(args, unsigned int), *format);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (count);
			count += check_format(format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
