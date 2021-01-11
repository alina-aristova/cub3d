/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:37:09 by acase             #+#    #+#             */
/*   Updated: 2020/11/02 16:00:39 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int start;
	int end;

	if (!s1 || !set)
		return (0);
	end = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (start < end && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}
