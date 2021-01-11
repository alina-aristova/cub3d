/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:14:24 by acase             #+#    #+#             */
/*   Updated: 2020/11/02 15:59:41 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	char	*s1;

	if (!s || !f)
		return (0);
	s1 = (char*)s;
	i = 0;
	str = ft_strdup(s1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = (f)(i, s1[i]);
		i++;
	}
	return (str);
}
