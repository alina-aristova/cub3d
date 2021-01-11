/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcst_sprite_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:27:14 by acase             #+#    #+#             */
/*   Updated: 2020/12/18 13:27:16 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	tr_x_y(t_cub *params, int i)
{
	params->spr.sprite_x = params->sprt[params->sp_order[i]].x - params->pl.x;
	params->spr.sprite_y = params->sprt[params->sp_order[i]].y - params->pl.y;
	params->spr.inv_det = 1.0 / (params->pl.player_x * params->pl.diry
					- params->pl.dirx * params->pl.player_y);
	params->spr.trx = params->spr.inv_det *
					(params->pl.diry * params->spr.sprite_x
					- params->pl.dirx * params->spr.sprite_y);
	params->spr.try = params->spr.inv_det *
					(-params->pl.player_y * params->spr.sprite_x
					+ params->pl.player_x * params->spr.sprite_y);
	params->spr.scx = (int)((params->wdht / 2)
							* (1 + params->spr.trx / params->spr.try));
}

void	start_end(t_cub *params, int i)
{
	tr_x_y(params, i);
	params->spr.sheight = abs((int)(params->hght / (params->spr.try)));
	params->spr.starty = -params->spr.sheight / 2 + params->hght / 2;
	if (params->spr.starty < 0)
		params->spr.starty = 0;
	params->spr.endy = params->spr.sheight / 2 + params->hght / 2;
	if (params->spr.endy >= params->hght)
		params->spr.endy = params->hght - 1;
	params->spr.swidht = abs((int)(params->hght / params->spr.try));
	params->spr.startx = -params->spr.swidht / 2 + params->spr.scx;
	if (params->spr.startx < 0)
		params->spr.startx = 0;
	params->spr.endx = params->spr.swidht / 2 + params->spr.scx;
	if (params->spr.endx >= params->wdht)
		params->spr.endx = params->wdht - 1;
}
