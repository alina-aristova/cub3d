/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 19:03:10 by acase             #+#    #+#             */
/*   Updated: 2020/12/20 14:42:02 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_pars_map(char *line, t_cub *params, t_list **lst)
{
	char *res;

	if (!check_params_add(params) && !check_empty_line(line))
		return ;
	res = ft_strdup(line);
	if (check_params_add(params))
	{
		ft_lstadd_back(lst, ft_lstnew(res));
	}
	else
		print_error(params);
}

void	check_params(char **res_split_line,
		t_cub *params, char *line, t_list **lst)
{
	if ((!ft_memcmp(res_split_line[0], "R", 2)))
		resolution(res_split_line, params);
	else if (!ft_memcmp(res_split_line[0], "NO", 3))
		north_texture(res_split_line, params);
	else if (!ft_memcmp(res_split_line[0], "SO", 3))
		south_texture(res_split_line, params);
	else if (!ft_memcmp(res_split_line[0], "WE", 3))
		west_texture(res_split_line, params);
	else if (!ft_memcmp(res_split_line[0], "EA", 3))
		east_texture(res_split_line, params);
	else if (!ft_memcmp(res_split_line[0], "S", 2))
		sprite_texture(res_split_line, params);
	else if (!ft_memcmp(res_split_line[0], "F", 2))
		colour_f(res_split_line, params);
	else if (!ft_memcmp(res_split_line[0], "C", 2))
		colour_s(res_split_line, params);
	else
		ft_pars_map(line, params, lst);
}

void	read_params(char **res_split_line,
		char *line, t_cub *params, t_list **lst)
{
	if (!(res_split_line = ft_split((const char*)line, ' ')))
		print_error(params);
	check_params(res_split_line, params, line, lst);
	free(line);
	line = NULL;
	free_str_arr(res_split_line);
	res_split_line = 0;
}

void	parser(int fd, t_cub *params, t_self *self)
{
	char		*line;
	char		*rez_split_line;
	t_list		*lst;

	lst = NULL;
	self->init(params);
	params->tex = malloc(sizeof(t_texture) * 5);
	while (get_next_line(fd, &line) > 0)
		read_params(&rez_split_line, line, params, &lst);
	if (ft_strlen(line) != 0)
		read_params(&rez_split_line, line, params, &lst);
	params->map = make_map(lst, ft_lstsize(lst));
	check_map(params->map, params);
	check_pos_sprite(params, params->map);
	ft_lstclear(&lst, free);
	if (line != NULL)
		free(line);
}
