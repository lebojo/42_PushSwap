NAME = push_swap

SRC_PATH = ./
SRC_OBJ = ./
SRC_INCLUDES = ./

HEADER = proto.h
SRC =	push_swap.c utils.c \
		instructions.c check.c \
		instructions_double.c \
		instructions_reverse.c \
		algorithm_complex.c algo_utils.c \
		ft_itoa.c \
		algorithm_simple.c

CFLAGS = -Wall -Wextra -Werror
OPTIONS =  -I$(SRC_INCLUDES)

SRCS = $(addprefix $(SRC_PATH),$(SRC))
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(SRC_OBJ),$(OBJ))
HEADERS = $(addprefix $(SRC_INCLUDES),$(HEADER))

CC = gcc
RM = rm -f

$(SRC_OBJ)%.o: $(SRC_PATH)%.c $(HEADERS)
	mkdir -p $(SRC_OBJ)
	$(CC) $(CFLAGS) $(OPTIONS) -o $(@) -c $(<)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OPTIONS) -o $(@) $(^)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re