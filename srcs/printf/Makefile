NAME = libftprintf.a

LIB = -I ./includes

SRCS =  libft/util.c\
		libft/format.c \
		libft/format_1.c \
		libft/format_2.c \
		libft/format_3.c \
		libft/printf.c \
		libft/printf_1.c \
		libft/printf_2.c \
		libft/printf_3.c \
		libft/params.c \
        libft/color.c \
		libft/flags_1.c \
		libft/flags_2.c \
		libft/flags_3.c \
		libft/flags_4.c \
		libft/flags_5.c \
		libft/flags_6.c \
		libft/atoi_itoa.c \
		libft/types.c \
		libft/type_1.c \
        libft/ft_strnstr.c \
		libft/ft_itoa_base.c \
		libft/ft_strjoin.c \
		libft/ft_strdup.c \
		libft/ft_islower.c \
		libft/ft_isupper.c \
		libft/ft_tolower.c \
		libft/ft_putchar.c \
		libft/ft_toupper.c \
		libft/ft_isdigit.c \
		libft/ft_strlen.c \
		libft/ft_strchr.c \
		libft/ft_strcpy.c \
		libft/ft_strncpy.c \
		libft/ft_strdup.c \
		libft/ft_strcat.c \
		libft/ft_memset.c \
		libft/ft_strncat.c \
		libft/ft_putchar.c \

OBJ =   util.o \
		format.o \
		format_1.o \
		format_2.o \
		format_3.o \
		printf.o \
		printf_1.o \
		printf_2.o \
		printf_3.o \
		params.o \
		flags_1.o \
		flags_2.o \
		flags_3.o \
		flags_4.o \
		flags_5.o \
		flags_6.o \
		types.o \
		type_1.o \
        color.o \
		ft_itoa_base.o \
		ft_strjoin.o \
		atoi_itoa.o \
		ft_islower.o \
		ft_isupper.o \
		ft_tolower.o \
		ft_putchar.o \
		ft_toupper.o \
        ft_strnstr.o \
		ft_strdup.o \
		ft_isdigit.o \
		ft_strlen.o \
		ft_strchr.o \
		ft_putchar.o \
		ft_strcpy.o \
		ft_strncpy.o \
		ft_strdup.o \
		ft_strcat.o \
		ft_strncat.o \
		ft_memset.o \

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
		gcc -c $(SRCS) $(FLAGS) $(LIB)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:	fclean all
