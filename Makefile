FLAGS = -Wall -Wextra -Werror -g
DFLAGS = -g3 -fsanitize=address
CC = gcc
SRCS = ft_putchar.c ft_putnbr.c cub.c get_next_line.c get_next_line_utils.c

all: comp

comp : 
	gcc $(FLAGS) $(DFLAGS) -I /usr/local/include $(SRCS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit 

clean :
	rm -rf a.out*
