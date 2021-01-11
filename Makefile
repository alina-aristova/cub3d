SRCS            =   srcs/pars_map.c\
					srcs/lib.c\
					srcs/get_next_line.c\
					srcs/get_next_line_utils.c\
					libft/ft_split.c\
					libft/ft_memchr.c\
                    libft/ft_memcmp.c\
                    libft/ft_strlcpy.c\
                    srcs/pars_color.c\
                    srcs/pars_texture.c\
                    srcs/check_map.c\
                    srcs/check_location_player.c\
                    srcs/rc.c\
                    srcs/check_key.c\
                    srcs/go_to.c\
                    srcs/create_bmp.c\
					srcs/init.c\
					srcs/main.c\
					srcs/lib_function.c\
					srcs/pars_map_utils.c\
					srcs/rcst_sprite.c\
					srcs/rcst_sprite_utils.c\
					srcs/rcst_tex.c\
					srcs/rcst_tex_utils.c\
					srcs/draw_func.c\
					srcs/turns.c\
					srcs/clear_func.c\
					srcs/exit.c

OBJS            = $(SRCS:.c=.o)

CC              = gcc

RM              = rm -f

CFLAGS          =  -g -Wall -Wextra -Werror

LIBS            =  -lmlx -framework OpenGL -framework AppKit -lm -Llibft -lft

MLX             = libmlx.dylib

LIBFT           = ./libft/libft.a

NAME            = cub3D

all:            $(NAME)

$(NAME):        $(LIBFT) $(OBJS)  $(LIBFT)
					gcc ${CFLAGS} -o ${NAME}  ${OBJS} ${LIBS}

$(LIBFT):
				$(MAKE) -C libft


clean:
				$(RM) $(OBJS)

fclean:         clean
				$(RM) $(NAME) $(MLX) $(LIBFT) ./mlx/$(MLX)

re:             fclean $(NAME)

.PHONY:         all clean fclean re libft