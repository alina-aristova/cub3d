/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:36:47 by acase             #+#    #+#             */
/*   Updated: 2020/12/18 13:59:11 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*s1;

	s1 = (char*)s;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (s1[len] == (char)c)
			return (&s1[len]);
		len--;
	}
	if (s1[0] == (char)c)
		return (&s1[0]);
	return (NULL);
}

int		int_rgb(int r, int g, int b)
{
	return ((r * 65536) + (g * 256) + b);
}

int		check_color(char *color, t_cub *var)
{
	int i;
	int color_res;

	i = 0;
	while (color[i])
	{
		if (!(ft_memchr("0123456789", color[i], 11)))
			print_error(var);
		i++;
	}
	color_res = ft_atoi(color);
	if (color_res > 255 || color < 0)
		print_error(var);
	return (color_res);
}

void	colour_f(char **color, t_cub *params)
{
	int		r;
	int		g;
	int		b;

	if (params->color_f != -1)
		print_error(params);
	if ((count_str(color) != 2))
		print_error(params);
	if ((count_chr(color[1], ',')) != 2)
		print_error(params);
	params->color_floor = ft_split(color[1], ',');
	if (count_str(params->color_floor) != 3)
		print_error(params);
	r = check_color(params->color_floor[0], params);
	g = check_color(params->color_floor[1], params);
	b = check_color(params->color_floor[2], params);
	if (r == -1 || g == -1 || b == -1)
		print_error(params);
	params->color_f = int_rgb(r, g, b);
}

void	colour_s(char **color, t_cub *params)
{
	int r;
	int g;
	int b;

	if (params->color_s != -1)
		print_error(params);
	if ((count_str(color) != 2))
		print_error(params);
	if ((count_chr(color[1], ',')) != 2)
		print_error(params);
	params->color_sell = ft_split(color[1], ',');
	if (count_str(params->color_sell) != 3)
		print_error(params);
	r = check_color(params->color_sell[0], params);
	g = check_color(params->color_sell[1], params);
	b = check_color(params->color_sell[2], params);
	if (r == -1 || g == -1 || b == -1)
		print_error(params);
	params->color_s = int_rgb(r, g, b);
}
