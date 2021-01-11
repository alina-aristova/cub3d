/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:37:36 by acase             #+#    #+#             */
/*   Updated: 2020/12/17 17:37:38 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->l_ln + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

int		my_get_color(t_cub *var, int x, int y)
{
	char			*dst;

	dst = var->data.addr + (y * var->data.l_ln
							+ x * (var->data.bpp / 8));
	return (*(unsigned int*)dst);
}

void	ceiling_and_floor(t_cub *params)
{
	int drawstart;
	int x;

	x = 0;
	while (x < params->wdht)
	{
		drawstart = 0;
		while (drawstart <= params->hght / 2 - 1)
		{
			my_mlx_pixel_put(&params->data, x, drawstart, params->color_s);
			drawstart++;
		}
		x++;
	}
	x = 0;
	while (x < params->wdht)
	{
		drawstart = params->hght / 2;
		while (drawstart <= params->hght - 1)
		{
			my_mlx_pixel_put(&params->data, x, drawstart, params->color_f);
			drawstart++;
		}
		x++;
	}
}
