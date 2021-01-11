/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:24:06 by acase             #+#    #+#             */
/*   Updated: 2020/12/21 13:54:23 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_arg(char *s, char *arg, t_cub *params)
{
	s = ft_strrchr(s, arg[0]);
	if (!s || (ft_memcmp(s, arg, ft_strlen(s))))
		print_error(params);
}

void	init_func(t_self *self)
{
	self->init = init_params;
}

void	start_game(t_cub *params)
{
	mlx_loop_hook(params->data.mlx, print_map, params);
	mlx_hook(params->data.mlx_win, 2, 0, chek_key_press, params);
	mlx_hook(params->data.mlx_win, 17, 0, ft_close, params);
	mlx_hook(params->data.mlx_win, 3, 0, chek_key_unpress, params);
	mlx_loop(params->data.mlx);
}

int		main(int argc, char **argv)
{
	t_cub		params;
	int			fd;
	t_self		self;

	init_func(&self);
	if (argc < 2 || argc > 3)
		print_error(&params);
	fd = open(argv[1], O_RDONLY);
	check_arg(argv[1], ".cub", &params);
	parser(fd, &params, &self);
	params.data.mlx = mlx_init();
	if (argc == 3)
	{
		if (!(ft_memcmp(argv[2], "--save", 6)))
			creat_bmp(&params);
		else
			print_error(&params);
	}
	init_mlx_params(&params);
	init_texture(&params);
	start_game(&params);
	close(fd);
}
