/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:13:24 by acase             #+#    #+#             */
/*   Updated: 2020/11/01 17:54:40 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	all_size;

	all_size = count * size;
	str = malloc(all_size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, all_size);
	return (str);
}
