/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:25:28 by acase             #+#    #+#             */
/*   Updated: 2020/11/04 11:52:31 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	if (dst == src)
		return (dst);
	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dst);
}
