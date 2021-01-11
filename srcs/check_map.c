/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:46:43 by acase             #+#    #+#             */
/*   Updated: 2020/12/21 13:55:22 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_empty_line(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	if (*line == '\0')
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

void	check_elem(int x, int y, char **map, t_cub *var)
{
	if (map[x][y] == '0' || map[x][y] == '2' || map[x][y] == '3')
	{
		if (x != 0 && y != 0 && y != (ft_strlen(map[x]) - 1)
		&& map[x + 1] != NULL)
		{
			if (ft_strlen(map[x + 1]) < y ||
			ft_strlen(map[x - 1]) < y)
				print_error(var);
			if (map[x + 1][y] != ' ' && map[x][y + 1] != ' '
			&& map[x][y + 1] != '\0')
				return ;
			else
				print_error(var);
		}
		else
			print_error(var);
	}
	if (map[x][y] == ' ')
	{
		if (x != 0 && y != 0 && y != ft_strlen(map[x]) && map[x + 1] != NULL)
		{
			if (map[x + 1][y] == '0' && map[x][y + 1] == '0')
				print_error(var);
		}
	}
}

void	check_map_utils(char **map, t_cub *params, int i, int j)
{
	if (!ft_memchr(" 120SNWE", map[i][j], 9))
		print_error(params);
	else
	{
		if (map[i][j] == '2')
			params->num_sprite++;
		check_elem(i, j, map, params);
	}
	if (ft_memchr("SNWE", map[i][j], 5))
	{
		check_pos(&params->pl, i, j, params);
		map[i][j] = '3';
		params->poz++;
	}
}

void	check_map(char **map, t_cub *params)
{
	int		i;
	int		j;

	params->poz = 0;
	i = 0;
	while (!check_empty_line(map[i]))
		i++;
	while (map[i])
	{
		j = 0;
		if (!ft_strlen(map[i]))
			print_error(params);
		while (map[i][j])
		{
			check_map_utils(map, params, i, j);
			j++;
		}
		i++;
	}
	if (params->poz != 1)
		print_error(params);
}

void	check_pos_sprite(t_cub *params, char **map)
{
	int		i;
	int		j;
	int		r;

	r = 0;
	i = 0;
	params->sprt = malloc(sizeof(t_sprite) * params->num_sprite);
	while (!check_empty_line(map[i]))
		i++;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
			{
				params->sprt[r].x = i + 0.5;
				params->sprt[r].y = j + 0.5;
				r++;
			}
			j++;
		}
		i++;
	}
}
