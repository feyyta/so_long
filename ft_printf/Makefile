# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcastrat <mcastrat.s19.be>                 +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 23:15:33 by mcastrat          #+#    #+#              #
#    Updated: 2025/03/12 23:15:34 by mcastrat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=	ft_printf.c ft_putnbr_hex.c ft_putptr.c ft_putunsigned.c \
				ft_putchar.c ft_putstr.c ft_putnbr.c
OBJS 		=	$(SRCS:.c=.o)
NAME 		=	libftprintf.a
LIBFTNAME 	=	libft.a
LIBC		=	ar rcs
CC 			=	cc
CFLAGS 		=	-Wall -Werror -Wextra
RM			=	rm -f
LIBFTDIR 	=	./libft
MAKELIB		=	make -C

all: $(NAME)

makelibft:
	$(MAKELIB) $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	$(LIBC) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	@cd $(LIBFTDIR) && make clean
	
fclean: clean
	$(RM) $(NAME)
	@cd $(LIBFTDIR) && make fclean
	
re: fclean all
