/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_location_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 12:54:20 by acase             #+#    #+#             */
/*   Updated: 2020/12/21 13:45:57 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_w_e(int i, int j, t_playgame *params, char **map)
{
	if (map[i][j] == 'W')
	{
		params->dirx = 0;
		params->diry = -1;
		params->player_x = -0.66;
		params->player_y = 0;
	}
	else if (map[i][j] == 'E')
	{
		params->dirx = 0;
		params->diry = 1;
		params->player_x = 0.66;
		params->player_y = 0;
	}
}

void	check_n_s(int i, int j, t_playgame *params, char **map)
{
	if (map[i][j] == 'N')
	{
		params->dirx = -1;
		params->diry = 0;
		params->player_x = 0;
		params->player_y = 0.66;
	}
	else if (map[i][j] == 'S')
	{
		params->dirx = 1;
		params->diry = 0;
		params->player_x = 0;
		params->player_y = -0.66;
	}
}

void	check_pos(t_playgame *params, int i, int j, t_cub *cub)
{
	params->x = i + 0.5;
	params->y = j + 0.5;
	if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S')
		check_n_s(i, j, params, cub->map);
	if (cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
		check_w_e(i, j, params, cub->map);
	cub->map[(int)(i + 0.5)][(int)(j + 0.5)] = '0';
}
