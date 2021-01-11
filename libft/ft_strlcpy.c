/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:33:07 by acase             #+#    #+#             */
/*   Updated: 2020/11/02 19:18:29 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *restrict dst, const char *restrict src,
						size_t dstsize)
{
	size_t			i;
	size_t			len;
	unsigned char	*str1;
	unsigned char	*str2;

	if (!dst || !src)
		return (0);
	len = 0;
	str1 = (unsigned char*)dst;
	str2 = (unsigned char*)src;
	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (str2[i] && i < (dstsize - 1))
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i] = '\0';
	return (len);
}
