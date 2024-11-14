NAME = rush-02

SOURCES = srcs/main.c \
		  srcs/dict.c \
		  srcs/dict_parser.c \
		  srcs/num_to_str.c \
		  srcs/get_next_line.c \
		  srcs/ft_putstr.c \
		  srcs/ft_strcmp.c \
		  srcs/ft_strncpy.c \
		  srcs/ft_strlen.c \
		  srcs/str.c

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror -I./includes

CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	cc $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
