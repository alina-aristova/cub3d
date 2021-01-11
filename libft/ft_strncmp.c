/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:56:30 by acase             #+#    #+#             */
/*   Updated: 2020/10/31 15:57:07 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *str1, char *str2, unsigned int nb)
{
	unsigned int i;

	i = 0;
	if (nb == 0)
		return (0);
	while (str1[i] == str2[i] && str1[i] != '\0' && i < (nb - 1))
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
