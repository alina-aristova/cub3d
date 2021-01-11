/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:00:28 by acase             #+#    #+#             */
/*   Updated: 2020/12/18 13:00:31 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	north_texture(char **north_texture, t_cub *params)
{
	if (count_str(north_texture) != 2)
		print_error(params);
	if (params->notex != NULL)
		print_error(params);
	params->notex = ft_strdup(north_texture[1]);
}

void	south_texture(char **south_texture, t_cub *params)
{
	if (count_str(south_texture) != 2)
		print_error(params);
	if (params->sotex != NULL)
		print_error(params);
	params->sotex = ft_strdup(south_texture[1]);
}

void	west_texture(char **west_texture, t_cub *params)
{
	if (params->wetex != NULL)
		print_error(params);
	if (count_str(west_texture) != 2)
		print_error(params);
	params->wetex = ft_strdup(west_texture[1]);
}

void	east_texture(char **east_texture, t_cub *params)
{
	if (count_str(east_texture) != 2)
		print_error(params);
	if (params->eatex != NULL)
		print_error(params);
	params->eatex = ft_strdup(east_texture[1]);
}

void	sprite_texture(char **sprite_texture, t_cub *params)
{
	if (count_str(sprite_texture) != 2)
		print_error(params);
	if (params->stex != NULL)
		print_error(params);
	params->stex = ft_strdup(sprite_texture[1]);
}
