# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kachiote <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/23 22:57:04 by kachiote          #+#    #+#              #
#    Updated: 2020/02/23 22:57:06 by kachiote         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = fractol

CFILES = window \
		main \
		buttons \
		button_binds \
		escape_button \
		image_constructor

FW = -framework OpenGL -framework AppKit

SRCS = $(patsubst %, %.c, $(CFILES))

OUT = $(patsubst %, %.o, $(CFILES))

INCL = lib/libft.a minilibx_macos/libmlx.a

FLAGS = -Werror -Wall -Wextra -g

LIB = ./lib

GLIB = ./minilibx_macos

all: $(NAME)

%.o:%.c -I./
	@$(CC) $(FLAGS) $(INCL) $< -o $@

$(NAME):
	@make -C $(LIB)
	@make -C $(GLIB)
	@$(CC) $(FLAGS) -o $(NAME) $(SRCS) $(INCL) $(FW)

test:
	@make -C $(LIB)
	@make -C $(GLIB)
	@$(CC) -o $(NAME) $(SRCS) $(INCL) $(FW)

clean:
	@rm -f $(OUT)
	@make -C $(GLIB) clean
	@make -C $(LIB) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB) fclean

re: fclean all

.PHONY: all clean fclean re
