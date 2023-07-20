NAME = cub3d

SRCS = src/main.c

PFILES = parser.c check_texture.c errers_pars.c check_map.c utils_parsing.c

GTL = get_next_line_utils.c get_next_line.c

PFILES := $(addprefix src/parsing/, $(PFILES))

GTL := $(addprefix src/get_line/, $(GTL))

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

all: $(NAME)

$(NAME) : $(SRCS) $(GTL) $(PFILES)
	@make -C libft
	$(CC) $(CFLAGS) libft/libft.a $(SRCS) $(GTL) $(PFILES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@make clean -C libft
	$(RM) $(NAME)

fclean: clean
	@make fclean -C libft

re: fclean all

.PHONY : clean fclean re bonus all