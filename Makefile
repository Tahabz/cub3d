FLAGS = -Ofast 
DFLAGS = -g3 -fsanitize=address
SRCS = ft_putchar.c ft_putnbr.c cub.c get_next_line.c get_next_line_utils.c ft_split.c
MLXFLAG = -lmlx -lXext -lX11 -lm

all: comp

comp : 
	gcc $(FLAGS) -I /usr/local/include $(SRCS) -L /usr/local/lib/ $(MLXFLAG)

clean :
	rm -rf a.out*
