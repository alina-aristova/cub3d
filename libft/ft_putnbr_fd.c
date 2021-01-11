/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 09:59:49 by acase             #+#    #+#             */
/*   Updated: 2020/11/01 10:47:53 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long int num;

	num = (long int)n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num > 10)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	ft_putchar_fd((char)(num % 10 + '0'), fd);
}
