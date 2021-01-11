/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 13:02:45 by acase             #+#    #+#             */
/*   Updated: 2020/12/17 17:39:27 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_params(t_cub *params)
{
	params->wdht = -1;
	params->hght = -1;
	params->notex = NULL;
	params->sotex = NULL;
	params->wetex = NULL;
	params->eatex = NULL;
	params->stex = NULL;
	params->color_f = -1;
	params->color_floor = NULL;
	params->color_s = -1;
	params->color_sell = NULL;
	params->pl.keyw = 0;
	params->pl.key_left = 0;
	params->pl.key_right = 0;
	params->pl.keys = 0;
	params->pl.right = 0;
	params->pl.left = 0;
	params->num_sprite = 0;
}

void	init_mlx_params(t_cub *params)
{
	params->data.mlx_win = mlx_new_window(params->data.mlx, params->wdht,
						params->hght, "cub3d");
	params->data.data = mlx_new_image(params->data.mlx,
						params->wdht, params->hght);
	params->data.addr = mlx_get_data_addr(params->data.data, &params->data.bpp,
						&params->data.l_ln, &params->data.endian);
}

void	init_texture(t_cub *params)
{
	params->tex[0].img = mlx_xpm_file_to_image(params->data.mlx, params->eatex,
						&params->tex[0].widht, &params->tex[0].height);
	params->tex[1].img = mlx_xpm_file_to_image(params->data.mlx, params->notex,
						&params->tex[1].widht, &params->tex[1].height);
	params->tex[2].img = mlx_xpm_file_to_image(params->data.mlx, params->sotex,
						&params->tex[2].widht, &params->tex[2].height);
	params->tex[3].img = mlx_xpm_file_to_image(params->data.mlx, params->wetex,
						&params->tex[3].widht, &params->tex[3].height);
	params->tex[4].img = mlx_xpm_file_to_image(params->data.mlx, params->stex,
						&params->tex[4].widht, &params->tex[4].height);
	check_tex(params);
	params->tex[0].addr = (int*)mlx_get_data_addr(params->tex[0].img,
		&params->tex[0].bpp, &params->tex[0].l_ln, &params->tex[0].endian);
	params->tex[1].addr = (int*)mlx_get_data_addr(params->tex[1].img,
		&params->tex[1].bpp, &params->tex[1].l_ln, &params->tex[1].endian);
	params->tex[2].addr = (int*)mlx_get_data_addr(params->tex[2].img,
		&params->tex[2].bpp, &params->tex[2].l_ln, &params->tex[2].endian);
	params->tex[3].addr = (int*)mlx_get_data_addr(params->tex[3].img,
		&params->tex[3].bpp, &params->tex[3].l_ln, &params->tex[3].endian);
	params->tex[4].addr = (int*)mlx_get_data_addr(params->tex[4].img,
			&params->tex[4].bpp, &params->tex[4].l_ln, &params->tex[4].endian);
}
