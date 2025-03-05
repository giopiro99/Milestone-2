/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpirozzi <giovannipirozzi12345@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:31:44 by gpirozzi          #+#    #+#             */
/*   Updated: 2025/02/12 15:15:45 by gpirozzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*copy_w(const char *s, int start_w, int end_w)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(end_w - start_w + 1);
	if (!word)
		return (NULL);
	while (start_w < end_w)
		word[i++] = s[start_w++];
	word[i] = '\0';
	return (word);
}

static void	fclean(char **arr, int j)
{
	if (!arr)
	{
		while (--j >= 0)
			free(arr[j]);
		free(arr);
	}
	return ;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		start_w;
	int		j;

	i = 0;
	j = 0;
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			start_w = i;
			while (s[i] != '\0' && s[i] != c)
				i++;
			arr[j++] = copy_w(s, start_w, i);
			fclean(arr, j);
		}
	}
	arr[j] = NULL;
	return (arr);
}
/* int main()
{
	const char s[] = "51 21 10 5" ;
	//char	c = ' ';
	int	j = 0;
	char	**arr = ft_split(s, ' ');
	while (arr[j] != NULL)
	{
		printf("%s\n", arr[j]);
		free(arr[j]);
		j++;
	}
	free(arr);
	return (0);
} */
