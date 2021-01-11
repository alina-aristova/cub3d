/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:16:14 by acase             #+#    #+#             */
/*   Updated: 2020/11/04 11:55:15 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src,
						size_t dstsize)
{
	size_t i;
	size_t j;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	while (src[j] && i + j < (dstsize - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + i);
}
