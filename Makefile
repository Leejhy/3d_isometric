CC = cc
# CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror
INC = fdf.h
SRCS =	fdf.c fdf_utils.c parsing.c file_check.c readmap.c readmap_utils.c \
		error.c put_pixel.c rotation.c init.c hook.c \
		./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
NAME = fdf

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
# $(CC) $(OBJS) -o $(NAME)

%.o : %.c $(INC)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all