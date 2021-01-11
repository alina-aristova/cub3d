/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:40:18 by acase             #+#    #+#             */
/*   Updated: 2020/12/21 13:41:45 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_str_arr(char **str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while ((str)[i])
		{
			if ((str)[i])
			{
				free((str)[i]);
				(str)[i] = NULL;
			}
			i++;
		}
		free(str);
		(str) = NULL;
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*it;
	t_list	*tmp;

	if (!lst)
		return ;
	it = *lst;
	while (it)
	{
		tmp = it;
		it = it->next;
		ft_lstdelone(tmp, del);
	}
	*lst = 0;
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
}
