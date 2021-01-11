/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 13:07:04 by acase             #+#    #+#             */
/*   Updated: 2020/11/04 15:12:04 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
int c, size_t n)
{
	unsigned char	*str_dst;
	unsigned char	*str_src;
	unsigned char	c1;
	size_t			i;

	str_dst = (unsigned char*)dst;
	str_src = (unsigned char*)src;
	c1 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		*(str_dst + i) = *(str_src + i);
		if (*(str_src + i) == c1)
			return (str_dst + i + 1);
		i++;
	}
	return (NULL);
}
