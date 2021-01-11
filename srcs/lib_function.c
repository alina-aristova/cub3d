/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:25:59 by acase             #+#    #+#             */
/*   Updated: 2020/12/21 13:46:39 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	str = (char*)malloc(sizeof(*s1) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		count_chr(char *str, int c)
{
	int		count;
	char	*str1;

	count = 0;
	str1 = str;
	while ((str1 = ft_strchr(str1, c)))
	{
		count++;
		str1++;
	}
	return (count);
}

int		count_str(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

void	ft_bzero(char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	all_size;

	all_size = count * size;
	str = malloc(all_size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, all_size);
	return (str);
}
