/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:27:23 by acase             #+#    #+#             */
/*   Updated: 2020/12/17 18:27:25 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	right(t_cub *cub)
{
	double olddir;
	double oldplay;

	olddir = cub->pl.dirx;
	cub->pl.dirx = cub->pl.dirx * cos(0.1) - cub->pl.diry * sin(0.1);
	cub->pl.diry = olddir * sin(0.1) + cub->pl.diry * cos(0.1);
	oldplay = cub->pl.player_x;
	cub->pl.player_x = cub->pl.player_x
				* cos(0.1) - cub->pl.player_y * sin(0.1);
	cub->pl.player_y = oldplay * sin(0.1)
				+ cub->pl.player_y * cos(0.1);
}

void	left(t_cub *cub)
{
	double olddir;
	double oldplay;

	olddir = cub->pl.dirx;
	cub->pl.dirx = cub->pl.dirx * cos(-0.1) - cub->pl.diry * sin(-0.1);
	cub->pl.diry = olddir * sin(-0.1) + cub->pl.diry * cos(-0.1);
	oldplay = cub->pl.player_x;
	cub->pl.player_x = cub->pl.player_x * cos(-0.1)
				- cub->pl.player_y * sin(-0.1);
	cub->pl.player_y = oldplay * sin(-0.1)
				+ cub->pl.player_y * cos(-0.1);
}
