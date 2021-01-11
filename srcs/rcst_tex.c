/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcst_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:59:06 by acase             #+#    #+#             */
/*   Updated: 2020/12/17 18:59:11 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_tex(t_cub *var)
{
	if (var->r.side == 0)
	{
		if (var->r.stepx < 0)
			var->r.tex = (int)(var->r.wlx * (double)(var->tex[0].widht));
		else
			var->r.tex = (int)(var->r.wlx * (double)(var->tex[1].widht));
	}
	else
	{
		if (var->r.stepy < 0)
			var->r.tex = (int)(var->r.wlx * (double)(var->tex[2].widht));
		else
			var->r.tex = (int)(var->r.wlx * (double)(var->tex[3].widht));
	}
}

void	computation_step(t_cub *var)
{
	if (var->r.side == 0)
	{
		if (var->r.stepx < 0)
		{
			var->r.step = 1.0 * var->tex[0].height / var->r.lineheight;
			var->r.tex = var->tex->height - var->r.tex - 1;
		}
		else
			var->r.step = 1.0 * var->tex[1].height / var->r.lineheight;
	}
	else
	{
		if (var->r.stepy < 0)
			var->r.step = 1.0 * var->tex[2].height / var->r.lineheight;
		else
		{
			var->r.step = 1.0 * var->tex[3].height / var->r.lineheight;
			var->r.tex = var->tex->height - var->r.tex - 1;
		}
	}
}

void	rc_put(t_cub *var, int n)
{
	var->r.texy = (int)var->r.tx_pos & (var->tex[n].height - 1);
	var->r.color = var->tex[n].addr[var->tex[n].height *
				var->r.texy + var->r.tex];
	my_mlx_pixel_put(&var->data, var->r.x, var->r.drawstart, var->r.color);
}

void	put_image(t_cub *var)
{
	var->r.tx_pos = (var->r.drawstart -
				(var->hght + var->r.lineheight) / 2) * var->r.step;
	while (var->r.drawstart < var->r.drawend)
	{
		var->r.tx_pos += var->r.step;
		if (var->r.side == 0)
		{
			if (var->r.stepx < 0)
				rc_put(var, 0);
			else
				rc_put(var, 1);
		}
		else
		{
			if (var->r.stepy < 0)
				rc_put(var, 2);
			else
				rc_put(var, 3);
		}
		var->r.drawstart++;
	}
}

void	init_variables(t_cub *var)
{
	var->r.camerax = 2 * (var->r.x) / (double)var->wdht - 1;
	var->r.raydirx = var->pl.dirx + var->pl.player_x * var->r.camerax;
	var->r.raydiry = var->pl.diry + var->pl.player_y * var->r.camerax;
	var->r.map_x = (int)var->pl.x;
	var->r.map_y = (int)var->pl.y;
	var->r.deltadistx = fabs(1 / var->r.raydirx);
	var->r.deltadisty = fabs(1 / var->r.raydiry);
}
