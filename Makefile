# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 15:11:15 by rcini-ha          #+#    #+#              #
#    Updated: 2024/11/29 16:25:55 by rcini-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
ft_atoi.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c \
 ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
 ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c


INCLUDE_DIR = ./
SRC_DIR = ./
NAME = libft.a
FLAGS = -Wall -Wextra -Werror
OPTIONS = -c -I $(INCLUDE_DIR)
OBJECTS = $(SRC_FILES:.c=.o)
OBJECTS_BONUS = $(SRC_BONUS:.c=.o)

all:	$(NAME)

$(NAME): ${OBJECTS}
#cc $(FLAGS) $(OPTIONS) $(SRC_FILES)
	ar rc $(NAME) $^
#gcc $(FLAGS) main.c -L. -lft
	
clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all re fclean clean 