/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:41:34 by gpirozzi          #+#    #+#             */
/*   Updated: 2024/11/18 18:41:35 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
//#include <stdio.h>
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*str;

	if (!dest && !src)
		return (dest);
	i = 0;
	dst = dest;
	str = src;
	if (dest <= src)
	{
		while (n != 0)
		{
			dst[i] = str[i];
			i++;
			n--;
		}
	}
	else
	{
		while (n-- > 0)
			dst[n] = str[n];
	}
	return (dst);
}

/*int	main()
{
	char src[] = "ciao";
	char dest[10];
	ft_memmove(src - 10, src, 5);
	dest[5] = '\0';
	printf("%s", dest);
}*/
