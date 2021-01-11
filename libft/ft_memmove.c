/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:49:35 by acase             #+#    #+#             */
/*   Updated: 2020/11/02 16:47:30 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	if (dst == src)
		return (dst);
	i = 1;
	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	if (str2 >= str1)
	{
		while (i++ && i - 1 <= len)
			str1[i - 2] = str2[i - 2];
	}
	if (str2 < str1)
	{
		while (i <= len)
		{
			str1[len - i] = str2[len - i];
			i++;
		}
	}
	return (str1);
}
