/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acase <acase@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/18 13:49:42 by acase             #+#    #+#             */
/*   Updated: 2020/12/20 14:54:43 by acase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <math.h>
# include <stdlib.h>
# include "inc/mlx.h"
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define TRUE 1
# define FALSE 0
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct	s_data
{
	void	*img;
	void	*mlx;
	void	*data;
	void	*mlx_win;
	char	*addr;
	int		bpp;
	int		l_ln;
	int		endian;
}				t_data;

typedef struct	s_sprite{
	double	x;
	double	y;
}				t_sprite;

typedef struct	s_texture
{
	void	*img;
	void	*mlx;
	void	*data;
	void	*mlx_win;
	int		*addr;
	int		bpp;
	int		l_ln;
	int		endian;
	int		widht;
	int		height;

}				t_texture;

typedef struct	s_spr
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	trx;
	double	try;
	int		scx;
	int		sheight;
	int		swidht;
	int		endx;
	int		startx;
	int		endy;
	int		starty;
}				t_spr;

typedef struct	s_playgame
{
	int		key_right;
	int		key_left;
	int		keyw;
	int		keys;
	int		left;
	int		right;
	double	dirx;
	double	diry;
	double	player_x;
	double	player_y;
	double	x;
	double	y;
	int		key;

}				t_playgame;

typedef struct	s_rcst
{
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	double			step;
	int				drawend;
	int				tex;
	unsigned int	color;
	int				texy;
	double			tx_pos;
	double			wlx;
	int				x;
	int				map_x;
	int				map_y;
}				t_rcst;

typedef struct	s_cub
{
	int			wdht;
	int			hght;
	char		*notex;
	char		*sotex;
	char		*wetex;
	char		*eatex;
	char		*stex;
	int			color_f;
	char		**color_floor;
	int			color_s;
	char		**color_sell;
	t_data		data;
	t_playgame	pl;
	t_texture	*tex;
	char		**map1;
	char		**map;
	int			num_sprite;
	t_sprite	*sprt;
	t_spr		spr;
	double		*zbuff;
	double		*sp_dist;
	int			*sp_order;
	t_rcst		r;
	int			poz;
}				t_cub;

typedef struct	s_self
{
	void	(*init)(t_cub *params);
}				t_self;

int				get_next_line(int fd, char **line);
int				ft_strlen(const char *str);
char			*ft_strndup(char *s, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_bzero(char *s, size_t n);
int				ft_atoi(char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strchr(const char *s, int c);
char			**ft_split(char const *s, char c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlcpy(char *restrict dst, const char *restrict src,
					size_t dstsize);
void			south_texture(char **south_texture, t_cub *params);
void			west_texture(char **west_texture, t_cub *params);
void			east_texture(char **east_texture, t_cub *params);
void			sprite_texture(char **sprite_texture, t_cub *params);
void			north_texture(char **north_texture, t_cub *params);
void			print_error(t_cub *var);
void			colour_s(char **color, t_cub *params);
void			colour_f(char **color, t_cub *params);
char			*ft_strdup(const char *s1);
int				count_chr(char *str, int c);
int				count_str(char **str);
void			ft_lstadd_back(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
void			bmp(unsigned char *bmp, int size, t_cub *cfg);
void			go_to(t_cub *params, char **map);
t_list			*ft_lstnew(void *content);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_checkmap(char **map);
void			check_map(char **map, t_cub *params);
void			cat_map(t_cub *var);
int				check_empty_line(char *line);
void			raycasting(t_cub *conf, char **map);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				print_map(t_cub *var);
void			ceiling_and_floor(t_cub *var);
int				chek_key_unpress(int key, t_cub *params);
int				chek_key_press(int key, t_cub *params);
int				my_get_color(t_cub *var, int x, int y);
void			check_pos_sprite(t_cub *params, char **map);
void			check_pos(t_playgame *params, int i, int j, t_cub *cub);
void			check_state(t_cub *game);
void			creat_bmp(t_cub *params);
void			start_end(t_cub *params, int i);
void			tr_x_y(t_cub *params, int i);
void			init_texture(t_cub *params);
void			init_mlx_params(t_cub *params);
void			init_params(t_cub *params);
void			parser(int fd, t_cub *params, t_self *self);
int				check_params_add(t_cub *var);
void			resolution(char **resolution, t_cub *var);
char			**make_map(t_list *head, int size);
char			*add_strdup(char *line);
void			free_str_arr(char **str);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				my_get_color(t_cub *var, int x, int y);
void			ceiling_and_floor(t_cub *params);
void			put_image(t_cub *var);
void			rc_put(t_cub *var, int n);
void			init_variables(t_cub *var);
void			computation_step(t_cub *var);
void			find_tex(t_cub *var);
void			computation_dist(t_cub *var);
void			computation_side(t_cub *var);
void			computation_perp_wall_dist(t_cub *var);
void			computation_start_end(t_cub *var);
void			computation_wlx(t_cub *var);
void			right(t_cub *cub);
void			left(t_cub *cub);
void			draw_sprite(t_cub *var);
int				ft_close(t_cub *var);
int				main(int argc, char **argv);
char			*ft_strrchr(const char *s, int c);
void			check_tex(t_cub *params);
void			free_str_arr(char **str);
#endif
