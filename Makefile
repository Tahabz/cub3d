FLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS = ft_putchar.c ft_putnbr.c cub.c

all: comp

comp : 
	gcc $(FLAG) -I /usr/local/include $(SRCS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

clean :
	rm -rf *.o
