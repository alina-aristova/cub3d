/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 14:59:38 by acase             #+#    #+#             */
/*   Updated: 2020/12/17 09:33:36 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>

void			bmp_bzero(unsigned char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = (unsigned char)0;
		i++;
	}
}

unsigned char	*bmp_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			all_size;

	all_size = count * size;
	str = malloc(all_size);
	if (str == NULL)
		return (NULL);
	bmp_bzero(str, all_size);
	return (str);
}

void			write_img(int fd, t_cub *params)
{
	unsigned int	color;
	int				x;
	int				y1;
	int				x1;

	y1 = params->hght - 1;
	x1 = params->wdht;
	while (y1 >= 0)
	{
		x = 0;
		while (x < x1)
		{
			color = my_get_color(params, x, y1);
			write(fd, &color, 3);
			x++;
		}
		y1--;
	}
}

void			creat_bmp_header(unsigned char *bmp, int size, t_cub *var)
{
	bmp[0] = (unsigned char)'B';
	bmp[1] = (unsigned char)'M';
	bmp[2] = (unsigned char)size;
	bmp[3] = (unsigned char)(size >> 8);
	bmp[4] = (unsigned char)(size >> 16);
	bmp[5] = (unsigned char)(size >> 24);
	bmp[10] = (unsigned char)54;
	bmp[14] = (unsigned char)40;
	bmp[18] = (unsigned char)var->wdht;
	bmp[19] = (unsigned char)(var->wdht >> 8);
	bmp[20] = (unsigned char)(var->wdht >> 16);
	bmp[21] = (unsigned char)(var->wdht >> 24);
	bmp[22] = (unsigned char)var->hght;
	bmp[23] = (unsigned char)(var->hght >> 8);
	bmp[24] = (unsigned char)(var->hght >> 16);
	bmp[25] = (unsigned char)(var->hght >> 24);
	bmp[26] = (unsigned char)1;
	bmp[28] = (unsigned char)24;
}

void			creat_bmp(t_cub *params)
{
	unsigned char	bmp[54];
	int				size;
	int				fd;
	int				i;

	i = 0;
	while (i < 54)
		bmp[i++] = (unsigned char)0;
	if (params->wdht % 4)
		params->wdht = params->wdht - (params->wdht % 4);
	size = params->wdht * params->hght + 54;
	init_mlx_params(params);
	init_texture(params);
	print_map(params);
	if (!(fd = open("screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU)))
		print_error(params);
	creat_bmp_header(bmp, size, params);
	write(fd, bmp, 54);
	write_img(fd, params);
	close(fd);
	exit(0);
}
