NAME = cub3d

B_NAME = bonus_cub3d

SRCS = src/main.c src/main_function.c 

PFILES = parser.c check_texture.c errers_pars.c check_map.c utils_parsing.c

RFILES =  mlx.c move.c raycasting.c raycasting_utils.c horiz_raycast.c vert_raycast.c more_function.c

GTL = get_next_line_utils.c get_next_line.c

3D = wall_3d.c

PFILES := $(addprefix src/parsing/, $(PFILES))

RFILES := $(addprefix src/raycasting/, $(RFILES))

GTL := $(addprefix src/get_line/, $(GTL))

3D := $(addprefix src/texture_3d/, $(3D))

M_FILES = $(SRCS) $(PFILES) $(RFILES) $(GTL) $(3D)

M_FILES := $(addprefix cub3d_mandatory/, $(M_FILES))

B_FILES = $(SRCS) $(PFILES) $(RFILES) $(GTL) $(3D)

B_FILES := $(addprefix cub3d_bonus/, $(B_FILES))

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror # -fsanitize=address -g3
MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME) : $(M_FILES)
	@make -C cub3d_mandatory/libft
	$(CC) $(CFLAGS) cub3d_mandatory/libft/libft.a $(M_FILES) $(MLX) -o $(NAME)

bonus: $(B_NAME)

$(B_NAME): $(B_FILES)
	@make -C cub3d_bonus/libft
	$(CC) $(CFLAGS) cub3d_bonus/libft/libft.a $(B_FILES) $(MLX) -o $(B_NAME)

clean:
	@make clean -C cub3d_mandatory/libft
	@make clean -C cub3d_bonus/libft

fclean: clean
	$(RM) $(NAME) $(B_NAME)

re: fclean all