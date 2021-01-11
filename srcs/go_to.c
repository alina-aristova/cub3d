/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:39:15 by acase             #+#    #+#             */
/*   Updated: 2020/12/17 17:39:18 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	go_down(t_cub *cub, char **map)
{
	if (map[(int)(cub->pl.x - cub->pl.dirx * 0.1)][(int)(cub->pl.y)] == '0' ||
	map[(int)(cub->pl.x - cub->pl.dirx * 0.1)][(int)(cub->pl.y)] == '3')
		cub->pl.x -= cub->pl.dirx * 0.1;
	if ((map[(int)(cub->pl.x)][(int)(cub->pl.y - cub->pl.diry * 0.1)] == '0') ||
	(map[(int)(cub->pl.x)][(int)(cub->pl.y - cub->pl.diry * 0.1)] == '3'))
		cub->pl.y -= cub->pl.diry * 0.1;
}

void	go_left(t_cub *cub)
{
	if (((cub->map[(int)(cub->pl.x)][(int)(cub->pl.y +
	cub->pl.dirx * 0.1 + 0.1)] == '0') &&
	(cub->map[(int)(cub->pl.x)][(int)(cub->pl.y +
	cub->pl.dirx * 0.1 - 0.1)] == '0')) ||
	((cub->map[(int)(cub->pl.x)][(int)(cub->pl.y +
	cub->pl.dirx * 0.1 + 0.1)] == '3') &&
	(cub->map[(int)(cub->pl.x)][(int)(cub->pl.y +
	cub->pl.dirx * 0.1 - 0.1)] == '3')))
		cub->pl.y += cub->pl.dirx * 0.1;
	if (((cub->map[(int)(cub->pl.x - cub->pl.diry *
	0.1 + 0.1)][(int)(cub->pl.y)] == '0') &&
	(cub->map[(int)(cub->pl.x - cub->pl.diry *
	0.1 - 0.1)][(int)(cub->pl.y)] == '0')) ||
	((cub->map[(int)(cub->pl.x - cub->pl.diry *
	0.1 + 0.1)][(int)(cub->pl.y)] == '3') &&
	(cub->map[(int)(cub->pl.x - cub->pl.diry *
	0.1 - 0.1)][(int)(cub->pl.y)] == '3')))
		cub->pl.x -= cub->pl.diry * 0.1;
}

void	go_right(t_cub *cub)
{
	if (((cub->map[(int)(cub->pl.x)][(int)(cub->pl.y
	- cub->pl.dirx * 0.1 + 0.1)] == '0') &&
	(cub->map[(int)(cub->pl.x)][(int)(cub->pl.y
	- cub->pl.dirx * 0.1 - 0.1)] == '0'))
	|| ((cub->map[(int)(cub->pl.x)][(int)(cub->pl.y
	- cub->pl.dirx * 0.1 + 0.1)] == '3') &&
	(cub->map[(int)(cub->pl.x)][(int)(cub->pl.y
	- cub->pl.dirx * 0.1 - 0.1)] == '3')))
		cub->pl.y -= cub->pl.dirx * 0.1;
	if (((cub->map[(int)(cub->pl.x + cub->pl.diry
	* 0.1 + 0.1)][(int)(cub->pl.y)] == '0') &&
	(cub->map[(int)(cub->pl.x + cub->pl.diry
	* 0.1 - 0.1)][(int)(cub->pl.y)] == '0')) ||
	((cub->map[(int)(cub->pl.x + cub->pl.diry
	* 0.1 + 0.1)][(int)(cub->pl.y)] == '3') &&
	(cub->map[(int)(cub->pl.x + cub->pl.diry
	* 0.1 - 0.1)][(int)(cub->pl.y)] == '3')))
		cub->pl.x += cub->pl.diry * 0.1;
}

void	go_up(t_cub *cub)
{
	if ((cub->map[(int)(cub->pl.x
	+ cub->pl.dirx * 0.1)][(int)(cub->pl.y)] == '0')
	|| (cub->map[(int)(cub->pl.x
	+ cub->pl.dirx * 0.1)][(int)(cub->pl.y)] == '3'))
		cub->pl.x += cub->pl.dirx * 0.1;
	if ((cub->map[(int)(cub->pl.x)][(int)(cub->pl.y
	+ cub->pl.diry * 0.1)] == '0') ||
	(cub->map[(int)(cub->pl.x)][(int)(cub->pl.y
	+ cub->pl.diry * 0.1)] == '3'))
		cub->pl.y += cub->pl.diry * 0.1;
}

void	go_to(t_cub *params, char **map)
{
	if (params->pl.keyw)
		go_up(params);
	if (params->pl.keys)
		go_down(params, map);
	if (params->pl.key_left)
		go_left(params);
	if (params->pl.key_right)
		go_right(params);
	if (params->pl.left)
		right(params);
	if (params->pl.right)
		left(params);
}
