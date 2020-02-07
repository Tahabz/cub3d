FLAGS = -Wall -Wextra -Werror
CC = gcc
SRCS = ft_putchar.c ft_putnbr.c cub.c

all: comp

comp : 
	gcc -g $(FLAG) -I /usr/local/include $(SRCS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

clean :
	rm *.o
