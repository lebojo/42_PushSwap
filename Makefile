NAME		= push_swap

SRC_PATH	= ./

# ------------  FLAGS  ------------------------------------------------------- #
CFLAGS 		= -Wall -Wextra -Werror
CC			= gcc
RM			=	rm -rf

# ------------  SOURCE FILES  ------------------------------------------------ #
SRC 		=	push_swap.c utils.c \
				instructions.c check.c \
				instructions_double.c \
				instructions_reverse.c \
				algorithm_complex.c algo_utils.c

# ------------  FILEPATHS  --------------------------------------------------- #
SRCS 		= $(addprefix $(SRC_PATH),$(SRC))
OBJS		= ${SRCS:.c=.o}

all: $(NAME) 

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) -o $(@) $(^)


%.o: %.c
		${CC} $(CFLAGS) -c $< -o $@ -g3

clean:
			$(RM) ${OBJS}

fclean:		clean
			$(RM) $(NAME) *.a

re:			fclean all

.PHONY: re ignore fclean clean all $(NAME)