/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcst_tex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:13:25 by acase             #+#    #+#             */
/*   Updated: 2020/12/18 12:13:27 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	computation_dist(t_cub *var)
{
	var->r.hit = 0;
	if (var->r.raydirx < 0)
	{
		var->r.stepx = -1;
		var->r.sidedistx = (var->pl.x - var->r.map_x) * var->r.deltadistx;
	}
	else
	{
		var->r.stepx = 1;
		var->r.sidedistx = (var->r.map_x + 1.0 - var->pl.x) * var->r.deltadistx;
	}
	if (var->r.raydiry < 0)
	{
		var->r.stepy = -1;
		var->r.sidedisty = (var->pl.y - var->r.map_y) * var->r.deltadisty;
	}
	else
	{
		var->r.stepy = 1;
		var->r.sidedisty = (var->r.map_y + 1.0 - var->pl.y) * var->r.deltadisty;
	}
}

void	computation_side(t_cub *var)
{
	while (var->r.hit == 0)
	{
		if (var->r.sidedistx < var->r.sidedisty)
		{
			var->r.sidedistx += var->r.deltadistx;
			var->r.map_x += var->r.stepx;
			var->r.side = 0;
		}
		else
		{
			var->r.sidedisty += var->r.deltadisty;
			var->r.map_y += var->r.stepy;
			var->r.side = 1;
		}
		if (var->map[var->r.map_x][var->r.map_y] == '1')
			var->r.hit = 1;
	}
}

void	computation_perp_wall_dist(t_cub *var)
{
	if (var->r.side == 0)
	{
		var->r.perpwalldist = (var->r.map_x - var->pl.x
					+ (1 - var->r.stepx) / 2) / var->r.raydirx;
	}
	else
	{
		var->r.perpwalldist = (var->r.map_y - var->pl.y
					+ (1 - var->r.stepy) / 2) / var->r.raydiry;
	}
}

void	computation_start_end(t_cub *var)
{
	var->r.lineheight = (int)(var->hght / (var->r.perpwalldist));
	var->r.drawstart = -var->r.lineheight / 2 + var->hght / 2;
	if (var->r.drawstart < 0)
		var->r.drawstart = 0;
	var->r.drawend = var->r.lineheight / 2 + var->hght / 2;
	if (var->r.drawend >= var->hght)
		var->r.drawend = var->hght - 1;
}

void	computation_wlx(t_cub *var)
{
	if (var->r.side == 0)
		var->r.wlx = var->pl.y + var->r.perpwalldist * var->r.raydiry;
	else
		var->r.wlx = var->pl.x + var->r.perpwalldist * var->r.raydirx;
	var->r.wlx -= (floor(var->r.wlx));
}
