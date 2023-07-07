ASM_SRCS = $(wildcard srcs/*.s)
ASM_OBJS = $(ASM_SRCS:.s=.o)

TEST_SRCS = test.c
TEST_OBJS = $(TEST_SRCS:.c=.o)

AS = nasm
ASFLAGS = -f elf64 -g
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3

NAME = libasm.a
TEST = test

all: $(NAME)

$(NAME): $(ASM_OBJS) $(TEST_OBJS)
	ar rcs $(NAME) $(ASM_OBJS)
	$(CC) $(CFLAGS) -o $(TEST) $(TEST_OBJS) $(NAME)

clean:
	rm -f $(ASM_OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
