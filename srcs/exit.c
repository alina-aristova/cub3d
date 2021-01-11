/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:42:08 by acase             #+#    #+#             */
/*   Updated: 2020/12/21 13:42:20 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(t_cub *var)
{
	if (var->map)
		free_str_arr(var->map);
	if (var->notex)
		free(var->notex);
	if (var->sotex)
		free(var->sotex);
	if (var->wetex)
		free(var->wetex);
	if (var->eatex)
		free(var->eatex);
	if (var->stex)
		free(var->stex);
	if (var->color_floor)
		free(var->color_floor);
	if (var->color_sell)
		free(var->color_sell);
	if (var->sprt)
		free(var->sprt);
	if (var->tex)
		free(var->tex);
	exit(0);
}

void	print_error(t_cub *var)
{
	write(2, "error\n", 6);
	ft_close(var);
	exit(0);
}
