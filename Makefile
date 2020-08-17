CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_ls
HEADERS = includes/
SRC = srcs

$(NAME): all
 
all: 
	@$(CC) $(CFLAGS) -I $(HEADERS) $(SRC)/*.c -o $(NAME)
	@echo "\033[32m$(NAME) built!\033[0m"

	
clean:
	@rm *.o

fclean:
	@rm $(NAME) *.o

re: fclean all

.PHONY: all clean fclean re