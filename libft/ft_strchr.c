/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:28:32 by acase             #+#    #+#             */
/*   Updated: 2020/11/01 14:05:23 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (*s)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
	}
	if (*s == (char)c)
	{
		return ((char*)s);
	}
	return (NULL);
}
