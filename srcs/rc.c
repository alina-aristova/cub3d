/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:32:24 by acase             #+#    #+#             */
/*   Updated: 2020/12/17 18:32:26 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		print_map(t_cub *var)
{
	var->r.x = 0;
	ceiling_and_floor(var);
	go_to(var, var->map);
	var->zbuff = (double *)malloc(sizeof(double) * var->wdht);
	while (var->r.x < var->wdht)
	{
		init_variables(var);
		computation_dist(var);
		computation_side(var);
		computation_perp_wall_dist(var);
		computation_start_end(var);
		computation_wlx(var);
		find_tex(var);
		computation_step(var);
		put_image(var);
		var->zbuff[var->r.x] = var->r.perpwalldist;
		var->r.x++;
	}
	draw_sprite(var);
	mlx_put_image_to_window(var->data.mlx,
				var->data.mlx_win, var->data.data, 0, 0);
	free(var->zbuff);
	return (0);
}
