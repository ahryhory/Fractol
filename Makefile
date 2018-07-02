# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahryhory <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 12:17:34 by ahryhory          #+#    #+#              #
#    Updated: 2018/01/14 22:14:40 by ahryhory         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Werror -Wextra -O2

F = -lmlx -framework OpenGL -framework AppKit -lpthread

OBJ = $(SRC:.c=.o)

PATHLIBFT = includes/libft

LIB = includes/libft/libft.a

SRC =

SRC += main.c
SRC += ft_usage.c
SRC += ft_create.c
SRC += ft_zoom.c
SRC += ft_color.c
SRC += ft_move.c
SRC += ft_iter.c
SRC += ft_control.c
SRC += ft_check.c
SRC += ft_init.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(PATHLIBFT)
	@gcc -o $(NAME) $(OBJ) $(LIB) $(F)

%.o: %.c
	@gcc $(FLAGS) -c -I. $<

clean:
	@make clean -C $(PATHLIBFT)
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C $(PATHLIBFT)
	@rm -rf $(NAME)

re: fclean all
