NAME = cub3d

SRCS = src/main.c src/main_function.c

PFILES = parser.c check_texture.c errers_pars.c check_map.c utils_parsing.c 

RFILES =  mlx.c move.c raycasting.c raycasting_utils.c horiz_raycast.c vert_raycast.c more_function.c

GTL = get_next_line_utils.c get_next_line.c

3D = wall_3d.c

PFILES := $(addprefix src/parsing/, $(PFILES))

RFILES := $(addprefix src/raycasting/, $(RFILES))

GTL := $(addprefix src/get_line/, $(GTL))

3D := $(addprefix src/texture_3d/, $(3D))

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror # -fsanitize=address -g3
MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) : $(SRCS) $(GTL) $(PFILES) $(RFILES) $(3D)
	@make -C libft
	$(CC) $(CFLAGS) libft/libft.a $(SRCS) $(GTL) $(3D) $(RFILES) $(PFILES) $(MLX) -o $(NAME)

clean:
	@make clean -C libft
	

fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY : clean fclean re bonus all