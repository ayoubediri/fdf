NAME= fdf
CC= cc
CFLAGE= -g -L/usr/include/minilibx-linux -lmlx_Linux -lX11 -lXext -lm -Wextra -Werror -Wall
SRC= fdf.c get_next_line.c get_next_line_utils.c ft_atoi.c ft_calloc.c ft_memset.c ft_split.c ft_free.c utils.c ft_utils2.c ft_full_data.c draw.c ft_utils1.c ft_mouse_button.c ft_rot.c
OBJ= ${SRC:%.c=%.o}

all:${NAME}

${NAME}: ${OBJ}
	${CC} ${SRC} ${CFLAGE} -o ${NAME}

bonus: all

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all re fclean clean bonus
