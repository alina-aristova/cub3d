/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rcst_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:34:33 by acase             #+#    #+#             */
/*   Updated: 2020/12/21 13:55:54 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_order_and_dist(t_cub *var)
{
	int		i;

	i = 0;
	var->sp_dist = (double *)malloc(sizeof(double) * var->num_sprite);
	var->sp_order = (int *)malloc(sizeof(int) * var->num_sprite);
	while (i < var->num_sprite)
	{
		var->sp_order[i] = i;
		var->sp_dist[i] = pow(var->pl.x - var->sprt[i].x, 2) +
				pow(var->pl.y - var->sprt[i].y, 2);
		var->sp_dist[i] = ((var->pl.x - var->sprt[i].x) *
				(var->pl.x - var->sprt[i].x) +
				(var->pl.y - var->sprt[i].y) *
				(var->pl.y - var->sprt[i].y));
		i++;
	}
}

void	sort_sprite(t_cub *var)
{
	int		i;
	double	buff;
	int		check;

	check = 1;
	while (check)
	{
		i = 0;
		check = 0;
		while (i < var->num_sprite - 1)
		{
			if (var->sp_dist[i] < var->sp_dist[i + 1])
			{
				check = 1;
				buff = var->sp_dist[i];
				var->sp_dist[i] = var->sp_dist[i + 1];
				var->sp_dist[i + 1] = buff;
				buff = var->sp_order[i];
				var->sp_order[i] = var->sp_order[i + 1];
				var->sp_order[i + 1] = buff;
			}
			i++;
		}
	}
}

void	put_sprite(t_cub *var, int x)
{
	int		color;
	int		d;
	int		texx;
	int		texy;
	int		y;

	texx = ((int)256 * (x - (-var->spr.swidht / 2 + var->spr.scx)))
	* var->tex[4].widht / var->spr.swidht / 256;
	if (var->spr.try > 0 && x > 0 && x < var->wdht &&
		var->spr.try < var->zbuff[x])
	{
		y = var->spr.starty;
		while (y < var->spr.endy)
		{
			d = (y) * 256 - var->hght * 128 + var->spr.sheight * 128;
			texy = ((d * var->tex[4].height) / var->spr.sheight) / 256;
			color = var->tex[4].addr[var->tex[4].widht * texy + texx];
			if (color != 9961608)
				my_mlx_pixel_put(&var->data, x, y, color);
			y++;
		}
	}
}

void	draw_all_sprite(t_cub *var)
{
	int i;
	int x;

	i = 0;
	while (i < var->num_sprite)
	{
		start_end(var, i);
		x = var->spr.startx;
		while (x < var->spr.endx)
		{
			put_sprite(var, x);
			x++;
		}
		i++;
	}
}

void	draw_sprite(t_cub *var)
{
	init_order_and_dist(var);
	sort_sprite(var);
	draw_all_sprite(var);
	free(var->sp_dist);
	free(var->sp_order);
}
