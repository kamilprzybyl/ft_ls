CC 		=	gcc
FLAGS 	=	-Wall -Wextra -Werror
LIBFT 	=	Libft/libft.a
NAME 	=	ft_ls
SRC		=	src/main.c \
			src/parse.c \
			src/ft_ls.c \
			src/print.c \
			src/sort_files.c \
			src/quick_sort.c \
			src/reverse_array.c
OBJ 	=	$(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) -c $(FLAGS) $^ -o $@

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) ./Libft/libft.a  $^ -o $@

$(LIBFT):
	@make --directory=./Libft

clean:
	@rm -fr $(OBJ)

fclean:
	@make clean
	@rm -fr $(NAME)

re: fclean all