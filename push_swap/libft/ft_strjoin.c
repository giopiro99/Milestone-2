/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:38:03 by gpirozzi          #+#    #+#             */
/*   Updated: 2024/11/21 11:38:10 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*fstrcat(char *dest, char *src)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[a] != '\0')
	{
		dest[i] = src[a];
		a++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		total_len;

	total_len = len(s1)+len(s2);
	str = ((char *)malloc((total_len + 1) * sizeof(char)));
	if (str == NULL)
		return (NULL);
	str[0] = '\0';
	str = fstrcat(str, (char *)s1);
	str = fstrcat(str, (char *)s2);
	return (str);
}
/*int main()
{
	const char str[] = "tua madre ";
	const char str2[] = "saluta i bambini..";
	printf("%s", ft_strjoin(str, str2));
}*/
