/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:56:18 by gpirozzi          #+#    #+#             */
/*   Updated: 2024/11/20 14:56:20 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
static void	*memsets(void *s, int c, size_t n)
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 && size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	ptr = (void *)malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	else
		return (memsets(ptr, 0, nmemb * size));
}
/*int main()
{
	char *a = (char *)ft_calloc(5, sizeof(char));
	printf("%s", a);
	if (a != NULL)
		free(a);
	//per provarlo cambia 48 con altro
}*/
