NAME = cub3d

SRCS =  src/main.c src/parsing/parser.c src/parsing/check_texture.c src/parsing/errers_pars.c src/parsing/check_map.c

UTLS = src/get_line/get_next_line_utils.c src/get_line/get_next_line.c

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

all: $(NAME)

$(NAME) : $(SRCS) $(UTLS)
	@make -C libft
	$(CC) $(CFLAGS) libft/libft.a $(SRCS) $(UTLS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@make clean -C libft
	$(RM) $(NAME)

fclean: clean
	@make fclean -C libft

re: fclean all

.PHONY : clean fclean re bonus all