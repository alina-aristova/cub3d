/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:27:37 by acase             #+#    #+#             */
/*   Updated: 2020/11/02 14:29:38 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str1, char *str2, size_t size)
{
	size_t		j;
	size_t		i;

	i = 0;
	if (!(*str2))
		return (str1);
	while (str1[i] != '\0' && i < size)
	{
		j = 0;
		while (str2[j] == str1[i + j] && (i + j) < size)
		{
			if (str2[j + 1] == '\0')
				return (str1 + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
