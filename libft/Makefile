# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jhoekstr <jhoekstr@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/25 18:32:03 by jhoekstr      #+#    #+#                  #
#    Updated: 2022/11/28 18:21:41 by jhoekstr      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c\
ft_memmove.c\
ft_strchr.c\
ft_strlcpy.c\
ft_toupper.c\
ft_bzero.c\
ft_isdigit.c\
ft_memcpy.c\
ft_memset.c\
ft_strnstr.c\
ft_tolower.c\
ft_isalpha.c\
ft_isalnum.c\
ft_isascii.c\
ft_isprint.c\
ft_strlen.c\
ft_strlcat.c\
ft_strrchr.c\
ft_strncmp.c\
ft_memchr.c\
ft_memcmp.c\
ft_calloc.c\
ft_strdup.c\
ft_substr.c\
ft_strjoin.c\
ft_putchar_fd.c\
ft_strtrim.c\
ft_split.c\
ft_itoa.c\
ft_striteri.c\
ft_strmapi.c\
ft_putstr_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putpointer.c\
ft_printf.c\
ft_puthexup.c\
ft_puthexlow.c\
ft_putchar.c\
ft_putnbr.c\
ft_putstr.c\
ft_putunsnbr.c\
get_next_line.c\
get_next_line_utils.c\

BONUS_SRCS = ft_lstnew_bonus.c\
ft_lstadd_front_bonus.c\
ft_lstsize_bonus.c\
ft_lstlast_bonus.c\
ft_lstadd_back_bonus.c\
ft_lstdelone_bonus.c\

OBJ = $(SRCS:%.c=%.o)	
BONUS_OBJ = $(BONUS_SRCS:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror 

CC = gcc

.PHONY: fclean clean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $^

bonus: $(BONUS_OBJ) $(OBJ)
	@ar -rc $(NAME) $^

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $^

test: $(NAME) main.c
	$(CC) $(CFLAGS) -o $@ $^

clean:
	@$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	@$(RM) $(NAME)

re:	fclean all