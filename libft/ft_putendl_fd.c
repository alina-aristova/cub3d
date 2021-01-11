/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:56:18 by acase             #+#    #+#             */
/*   Updated: 2020/11/02 15:57:43 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char const *s, int fd)
{
	size_t len;

	if (s)
	{
		len = ft_strlen(s);
		write(fd, s, len);
		write(fd, "\n", 1);
	}
}
