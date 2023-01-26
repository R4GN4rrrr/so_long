NAME = so_long

SOURCES = so_long.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_read.c\
		cheking.c\
		./libft/ft_calloc.c\
		./libft/ft_bzero.c\
		./libft/ft_memset.c\
		./libft/ft_split.c\
		./libft/ft_strncmp.c\
		./libft/ft_strlen.c\
		./libft/ft_putstr_fd.c\

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Werror -Wextra -Wall

Mlx_F = -lmlx -framework OpenGL -framework Appkit

all : $(NAME)

$(NAME) : $(OBJECTS)

	$(CC) $(CFLAGS) $(OBJECTS) $(Mlx_F) -o $(NAME)

clean :
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
