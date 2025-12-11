
NAME        = push_swap
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

INC = push_swap.h operations/operations.h \
		parsing/parsing.h stack/stack.h \
		sorting/sorting.h

SRC_MAIN    = push_swap.c

SRC_PARSING = parsing/parser.c parsing/ft_checks.c \
				parsing/parsing_helpers.c parsing/ft_splite.c


SRC_OPS     = operations/operations_push.c \
              operations/operations_swap.c \
              operations/operations_rotate.c \
              operations/operations_reverse_rotate.c

SRC_STACK   = stack/stack.c stack/stack_utils.c \
				stack/normalize.c

SRC_SORT = sorting/sorting.c  sorting/small_sort.c \
			sorting/chunk_sort.c sorting/chunk_utils.c

SRCS        = $(SRC_MAIN) $(SRC_PARSING) $(SRC_OPS) $(SRC_STACK) $(SRC_SORT)

OBJS        = $(SRCS:.c=.o)



all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
