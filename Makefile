NAME = cub3d

SRCS = src/main.c

PFILES = parser.c check_texture.c errers_pars.c check_map.c utils_parsing.c 

RFILES =  mlx.c move.c rendering.c raycasting.c raycasting_utils.c horiz_raycast.c vert_raycast.c event.c

GTL = get_next_line_utils.c get_next_line.c

PFILES := $(addprefix src/parsing/, $(PFILES))

RFILES := $(addprefix src/raycasting/, $(RFILES))

GTL := $(addprefix src/get_line/, $(GTL))

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3

all: $(NAME)

$(NAME) : $(SRCS) $(GTL) $(PFILES) $(RFILES)
	@make -C libft
	$(CC) $(CFLAGS) libft/libft.a $(SRCS) $(GTL) $(RFILES) $(PFILES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@make clean -C libft
	$(RM) $(NAME)

fclean: clean
	@make fclean -C libft

re: fclean all

.PHONY : clean fclean re bonus all