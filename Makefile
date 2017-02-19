NAME = ft_ls

SRCS = srcs/main.c \
        srcs/get_info.c


INCL = -I./includes/

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
		gcc $(SRCS) $(FLAGS) $(INCL) -L./srcs/libft -lft -L./srcs/printf -lftprintf -o $(NAME)

printf:
		make -C srcs/printf fclean && make -C srcs/printf && make clean -C srcs/printf

libft:
		make -C srcs/libft fclean && make -C srcs/libft && make clean -C srcs/libft
        
clean:
		
fclean:
		rm -rf $(NAME)

re:	fclean all
