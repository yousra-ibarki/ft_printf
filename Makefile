NAME = libftprintf.a
SRCS =	ft_printf.c ft_fcthelp.c ft_pointer.c ft_printhex.c ft_itoa.c ft_printunsigned.c /

OBJS = $(SRCS:%.c=%.o)
CFLAGS = -Wall -Werror -Wextra
CC=cc
RM = rm -f
AR = ar -rcs

all: $(NAME)

$(NAME):$(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re: fclean all
