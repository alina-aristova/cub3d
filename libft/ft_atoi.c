/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:11:29 by acase             #+#    #+#             */
/*   Updated: 2020/11/04 02:19:16 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(char c)
{
	return ((c == ' ' || (c >= 9 && c <= 13)) ? 1 : 0);
}

int		ft_atoi(char *str)
{
	int				i;
	long long int	res;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if (res > 2147483647 && sign == 1)
			return (-1);
		if (res <= -2147483648 && sign == -1)
			return (0);
	}
	return (res * sign);
}
