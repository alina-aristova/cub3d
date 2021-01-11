/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:28:31 by acase             #+#    #+#             */
/*   Updated: 2020/11/03 22:49:06 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_split_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int			ft_count_words(char const *s, char c)
{
	int count_words;

	count_words = 0;
	while (s)
	{
		if (*s == '\0')
			return (0);
		while (*s == c)
			s++;
		if (*s == '\0')
			return (count_words);
		s = ft_strchr(s, c);
		count_words++;
	}
	return (count_words);
}

void		ft_wordsplit(size_t words, char c, char const *s, char **arr)
{
	size_t		word_len;
	char		**res;
	char const	*word;

	res = arr;
	while (words--)
	{
		while (*s == c)
			s++;
		word = s;
		s = ft_strchr(s, c);
		if (s)
			word_len = s - word + 1;
		else
			word_len = ft_strchr(word, '\0') - word + 1;
		*arr = (char *)malloc(sizeof(char) * word_len);
		if (!arr)
		{
			ft_split_free(res);
			return ;
		}
		ft_strlcpy(*arr, word, word_len);
		arr++;
	}
	*arr = 0;
}

char		**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		count_words;

	if (!s)
		return (NULL);
	count_words = ft_count_words(s, c);
	arr = (char **)malloc(sizeof(char*) * (count_words + 1));
	if (!arr)
		return (0);
	ft_wordsplit(count_words, c, s, arr);
	if (!arr)
		return (0);
	return (arr);
}
