/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 12:19:54 by acase             #+#    #+#             */
/*   Updated: 2020/12/18 12:19:57 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		chek_key_press(int key, t_cub *params)
{
	if (key == 53)
		ft_close(params);
	if (key == 13)
		params->pl.keyw = 1;
	if (key == 0)
		params->pl.key_left = 1;
	if (key == 1)
		params->pl.keys = 1;
	if (key == 2)
		params->pl.key_right = 1;
	if (key == 123)
		params->pl.left = 1;
	if (key == 124)
		params->pl.right = 1;
	return (0);
}

int		chek_key_unpress(int key, t_cub *params)
{
	if (key == 13)
		params->pl.keyw = 0;
	if (key == 0)
		params->pl.key_left = 0;
	if (key == 1)
		params->pl.keys = 0;
	if (key == 2)
		params->pl.key_right = 0;
	if (key == 123)
		params->pl.left = 0;
	if (key == 124)
		params->pl.right = 0;
	return (0);
}
