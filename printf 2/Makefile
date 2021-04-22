# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccubillo <ccubillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 16:22:36 by glopez-a          #+#    #+#              #
#    Updated: 2020/01/13 20:23:53 by ccubillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = f*.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SRCS) ft_printf.h
			@gcc -Wall -Wextra -Werror $(INCLUDES) -c $(SRCS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)

clean:
			@$(RM) $(OBJS)

fclean: clean
			@$(RM) $(NAME)

re: 		fclean all

.PHONY:		all clean fclean re
