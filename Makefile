CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_ls
HEADERS = includes/
SRCS = srcs

$(NAME): all
 
all: 
	@make -C libft 									# go to libft directory and do make 
	@$(CC) $(CFLAGS) -I $(HEADERS) libft/libft.a $(SRCS)/*.c -o $(NAME)
	@echo "\033[32m$(NAME) built!\033[0m"

	
clean:
	@make -C libft clean							# do clean in libft
	@rm *.o

fclean:
	@make -C libft fclean							# do fclean in libft
	@rm $(NAME) *.o

re: fclean all

.PHONY: all clean fclean re