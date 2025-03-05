/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:17:00 by gpirozzi          #+#    #+#             */
/*   Updated: 2024/11/18 16:17:06 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>
//#include <stdio.h>
//(char)c non necessaria perche c lo fa implicitamente, ma chiarisce.

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*int main()
{
	char	buffer[10];
	int	i = 0;
	ft_memset(buffer, 6, 10);
	while(i < 10)
	{
		printf("%d", buffer[i]);
		i++;
	}
	return (0);
}*/
