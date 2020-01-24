# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-eng <mvan-eng@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/24 15:54:21 by mvan-eng       #+#    #+#                 #
#    Updated: 2020/01/22 13:23:18 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = mvan-eng.filler

FLAGS = -Wall -Wextra -Werror

FILES = main get_game parse_token calc_possibilities

LIB = libft/libft.a

SRC = $(FILES:%=src/%.c)

all: $(NAME)

$(NAME):
	@echo ">>>>>	$(NAME) COMPILING STARTED	<<<<<"
	@cd libft && make
	@gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME)
	@echo ">>>>>	$(NAME) COMPILING SUCCESS	<<<<<"

clean:
	@echo ">>>>>	CLEANING $(NAME)	<<<<<"
	@cd libft && make clean

fclean: clean
	@echo ">>>>>	REMOVING $(NAME)	<<<<<"
	@rm -f $(NAME)
	@cd libft && make fclean

re: fclean all
