/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:39:52 by acase             #+#    #+#             */
/*   Updated: 2020/12/17 17:39:54 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	node = *lst;
	while (node->next)
		node = node->next;
	node->next = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	if (!(node = (t_list*)malloc(sizeof(t_list))))
		return (node);
	node->content = content;
	node->next = NULL;
	return (node);
}

int		ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		size;

	if (!lst)
		return (0);
	size = 0;
	node = lst;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

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
