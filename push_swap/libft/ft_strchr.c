/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:59:13 by gpirozzi          #+#    #+#             */
/*   Updated: 2024/11/19 18:59:14 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	k;

	k = (char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == k)
			return ((char *)&s[i]);
		i++;
	}
	if (k == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*int	main()
{
	const char s[] = "";
	printf("%s", ft_strchr(s, '\0'));
}*/
