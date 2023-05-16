CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c) $(wildcard lst/*.c)
#그냥 나를 위한 메모: 혹시 다음 과제에서 또 하위dir을 만들며 하위dir이 여러 개 생긴다면 SRCS := $(shell find . -type f -name '*.c')
OBJS = $(wildcard *.o) $(wildcard lst/*.o)

NAME = libft.a

INCLUDES = ./includes

.PHONY : all clean fclean re

all :$(NAME)

$(NAME) : $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $^ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
