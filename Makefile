NAME = cub3d

SRCS =  main.c

UTLS = get_next_line/get_next_line_utils.c get_next_line/get_next_line.c

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(SRCS) $(UTLS)
	$(CC) $(CFLAGS) $(SRCS) $(UTLS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY : clean fclean re bonus all