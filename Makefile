NAME	=	so_long

SRCS	=	so_long.c\
			check_map.c\
			check_map2.c\
			gnl/get_next_line.c\
			gnl/get_next_line_utils.c\
			game_init.c\
			gamedata_init.c\
			map_init.c\
			map_read.c\
			draw.c\
			event_handl.c\
			move_player.c\
			map_handl.c\
			close_game.c\
			libft/*.c

HDRS	=	so_long.h\
			gnl/get_next_line.h\
			libft/libft.h

CFLAGS	=	-Wall -Wextra -Werror

CC	=	gcc $(CFLAGS)

CFLAGS	=	-Wall -Wextra -Werror

MAKEFILE	=	Makefile

LIBM	=	libft/Makefile

OBJ		=	${SRCS:.c=.o}

all:	$(NAME)

$(NAME):	$(MAKEFILE) $(SRCS) $(HDRS)
		$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:	clean

re:	fclean all

.PHONY:	all clean fclean re