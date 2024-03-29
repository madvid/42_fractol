# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/28 10:48:33 by mdavid            #+#    #+#              #
#    Updated: 2021/04/08 12:16:03 by mdavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_memset.c		\
		ft_bzero.c		\
		ft_memcpy.c		\
		ft_memccpy.c	\
		ft_memmove.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_strdup.c		\
		ft_strcpy.c		\
		ft_strncpy.c	\
		ft_strcat.c		\
		ft_strncat.c	\
		ft_strlcat.c	\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_strstr.c		\
		ft_strnstr.c	\
		ft_strcmp.c		\
		ft_strncmp.c	\
		ft_atoi.c		\
		ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_memalloc.c	\
		ft_memdel.c		\
		ft_strnew.c		\
		ft_strdel.c		\
		ft_strclr.c		\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strmap.c		\
		ft_strmapi.c	\
		ft_strequ.c		\
		ft_strnequ.c	\
		ft_strsub.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_strsplit.c	\
		ft_itoa.c		\
		ft_putchar.c	\
		ft_putstr.c		\
		ft_putendl.c	\
		ft_putnbr.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
		ft_lstnew.c		\
		ft_lstdelone.c	\
		ft_lstdel.c		\
		ft_lstadd.c		\
		ft_lstiter.c	\
		ft_lstmap.c		\
		ft_isupper.c	\
		ft_islower.c	\
		ft_power.c		\
		ft_eraser.c		\
		ft_strjoin_1n.c	\
		ft_strdup_1n.c	\
		ft_strjoin_1sp.c	\
		ft_strdup_1sp.c	\
		ft_strdup_p.c	\
		ft_strtrunc_x.c	\
		ft_strdupfree.c	\
		ft_ternaries.c


OBJS = $(SRCS:.c=.o)
INCLUDE = libft.h

all : $(NAME)

$(NAME) : $(OBJS) $(INCLUDE)
	@echo "\033[1;36m[ar rcs)]Constructing librairy\033[0m"
	@ar rcs $(NAME) $^
	@echo "\033[1;31m[ar rcs)]--> Librairy created\033[0m"

%.o: %.c Makefile
	@echo "  \033[1;32m[$(CC)] - [$(CFLAGS)]\033[0m \033[1;33min progress ...:\033[0m $< \033[1;31m->\033[0m $@"
	@$(CC) $(CFLAGS) -MD -c $^ -o $@ -I .$(INCLUDE)

norme :
	 @norminette -R CheckForbiddenSourceHeader $(SRCS) $(INCLUDE)
	 
clean :
	@rm -rf $(OBJS)
	@rm -rf $(OBJS:.o=.d)

fclean : clean
	@rm -f $(NAME)

re : fclean all