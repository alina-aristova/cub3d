/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:17:39 by acase             #+#    #+#             */
/*   Updated: 2020/12/24 19:34:05 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**make_map(t_list *head, int size)
{
	int		i;
	char	**map;
	t_list	*tmp;

	map = ft_calloc(size + 1, sizeof(char *));
	i = -1;
	tmp = head;
	while (tmp)
	{
		map[++i] = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	return (map);
}

int		check_params_add(t_cub *var)
{
	if (var->stex == NULL || var->wetex == NULL ||
		var->eatex == NULL || var->sotex == NULL ||
		var->notex == NULL || var->wdht == 0 ||
		var->hght == 0 || var->color_f == -1 ||
		var->color_s == -1)
		return (FALSE);
	return (TRUE);
}

void	resolution(char **resolution, t_cub *var)
{
	int i;

	i = 0;
	if (count_str(resolution) != 3 || var->wdht != -1 || var->hght != -1)
		print_error(var);
	while (resolution[1][i])
	{
		if (!(ft_memchr("0123456789", resolution[1][i], 11)))
			print_error(var);
		i++;
	}
	while (resolution[2][i])
	{
		if (!(ft_memchr("0123456789", resolution[2][i], 11)))
			print_error(var);
		i++;
	}
	var->wdht = ft_atoi(resolution[1]);
	if (var->wdht > 2560)
		var->wdht = 2560;
	var->hght = ft_atoi(resolution[2]);
	if (var->hght <= 0 || var->wdht <= 0)
		print_error(var);
	if (var->hght > 1395)
		var->hght = 1395;
}

void	check_tex(t_cub *params)
{
	if (!params->tex[0].img || !params->tex[1].img
		|| !params->tex[2].img || !params->tex[3].img || !params->tex[4].img)
		print_error(params);
}
