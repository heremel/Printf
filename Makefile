CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS = ft_printf.c ft_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS) 
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
