NAME = cub3d

CFLAGS = -Wall -Werror -Wextra

SRCS =	cub3d.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\





OBJS = $(SRCS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@gcc $(OBJS) ./libft/libft.a -o $(NAME)

clean:
	@make clean -C ./libft
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re