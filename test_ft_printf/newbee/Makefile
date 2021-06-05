SOURCE	=	ft_char.c \
			ft_flag.c \
			ft_parse.c \
			ft_printf.c \
			ft_type.c \
			ft_width.c \
			ft_spec.c\
			ft_stardot.c\
			ft_int.c\
			ft_zero.c\
			ft_unsig.c\
			ft_unsig_itoa.c\
			ft_itoa_hex.c\
			ft_hex.c\
			ft_pointr.c\

HEADER	=	ft_printf.h libft/libft.h

OBJECTS	=	${SOURCE:.c=.o}

RM		=	rm -f

NAME	=	libftprintf.a

AR		=	ar rcs

CFLAGS	=	-Wall -Wextra -Werror

%.o: %.c ${HEADER}
			gcc ${CFLAGS} -Ilibft -c $< -o ${<:.c=.o}

${NAME}:	${OBJECTS}
			make -C libft
			cp libft/libft.a $(NAME)
			${AR} ${NAME} ${OBJECTS}


all:		${NAME}

clean:
			make clean -C libft
			${RM} ${OBJECTS}

fclean:		clean
			make fclean -C libft
			${RM} ${NAME}

re:			fclean all

debug:		re
			gcc -g ${CFLAGS} *.c ./libft/libft.a

.PHONY:		all clean fclean bonus