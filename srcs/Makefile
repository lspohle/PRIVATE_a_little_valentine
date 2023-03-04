NAME		= a_little_valentine

LIBFT		= libft

MINILIBX	= minilibx

SRCS		= play_game.c manage_window.c read_map.c check_map.c create_map.c move_player.c display_output.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror 

RM			= rm -f

${NAME}:	${LIBFT} ${MINILIBX} ${OBJS}
			cp ../libft/libft.a .
			cp ../minilibx/libmlx.a .
			${CC} ${OBJS} libft.a libmlx.a -lm -framework OpenGL -framework AppKit -o ${NAME}

${OBJS}:	${SRCS}
			${CC} ${CFLAGS} -c ${SRCS}

${LIBFT}:	
			cd ../libft && make

${MINILIBX}:	
			cd ../minilibx && make

all:		${NAME}

clean:
			${RM} ${OBJS}
			cd ../libft && make clean

fclean:		clean
			${RM} ${NAME}
			cd ../libft && make fclean
			cd ../minilibx && make clean
			rm libft.a 
			rm libmlx.a

re:			fclean all

.PHONY:		all clean fclean re ${LIBFT} ${MINILIBX}
