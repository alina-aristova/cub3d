/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:44:51 by acase             #+#    #+#             */
/*   Updated: 2020/11/28 16:27:04 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c1;
	int				i;

	str = (unsigned char*)s;
	c1 = (unsigned char)c;
	i = 0;
	while (n--)
	{
		if (str[i] == c1)
			return (str + i);
		i++;
	}
	return (NULL);
}
