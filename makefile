NAME = cub3d

CFLAGS = -Wall -Werror -Wextra 

SRCS = 	cub3d.c\
		splitting.c\
		gnl/get_next_line.c\
		gnl/get_next_line_utils.c\
		checkingpath.c\
		colors.c\
		errors.c\
		mapping.c\
		parsing.c\
		utils.c\
		utils2.c\
		utils3.c\
		screen.c\
		move_p.c\
		raycast.c\
		draw.c\


CC = gcc-11

all: $(NAME)

$(NAME):$(SRCS)
	@make -C libft
	@$(CC) $(CFLAGS) $(SRCS) ./libft/libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re:	fclean all

.PHONY:	all clean fclean re
