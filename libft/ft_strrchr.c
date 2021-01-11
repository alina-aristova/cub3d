/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 14:50:29 by acase             #+#    #+#             */
/*   Updated: 2020/11/04 10:43:31 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*s1;

	s1 = (char*)s;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (s1[len] == (char)c)
			return (&s1[len]);
		len--;
	}
	if (s1[0] == (char)c)
		return (&s1[0]);
	return (NULL);
}
