NAME = push_swap
CHECKER = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_MAIN = push_swap.c

SRC_PARSING = parsing/parser.c parsing/ft_checks.c \
	parsing/parsing_helpers.c parsing/ft_splite.c

SRC_OPS = operations/operations_push.c \
	operations/operations_swap.c \
	operations/operations_rotate.c \
	operations/operations_reverse_rotate.c

SRC_STACK = stack/stack.c stack/stack_utils.c stack/normalize.c

SRC_SORT = sorting/sorting.c sorting/small_sort.c \
		sorting/chunk_sort.c sorting/chunk_utils.c

SRC_CHECKER = checker.c \
				checker_helper/check_utils.c \
				checker_helper/get_next_line.c \
				checker_helper/get_next_line_utils.c

SRCS = $(SRC_MAIN) $(SRC_PARSING) $(SRC_OPS) $(SRC_STACK) $(SRC_SORT)
SRCS_CHECK = $(SRC_PARSING) $(SRC_OPS) $(SRC_STACK) $(SRC_CHECKER)

OBJS = $(SRCS:.c=.o)
OBJS_CHECK = $(SRCS_CHECK:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(CHECKER): $(OBJS_CHECK)
	$(CC) $(CFLAGS) $(OBJS_CHECK) -o $(CHECKER)

bonus: $(CHECKER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_CHECK)

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re bonus
