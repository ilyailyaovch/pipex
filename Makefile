# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pleoma <pleoma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/17 13:50:23 by pleoma            #+#    #+#              #
#    Updated: 2022/02/17 13:55:30 by pleoma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
FLAGS = -Wall -Wextra -Werror

HEADER = includes/pipex.h
OBJ = 	$(patsubst %.c,%.o,$(SRC))
SRC	=	src/pipex.c\

.c.o:
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "Compiling $@"

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS)  $(OBJ) -o $@
	@echo "Compiling $@"

clean :
	@rm -f $(OBJ)
	@echo "Removing obj"

fclean : clean
	@rm -f $(NAME)
	@echo "Removing all"

re : fclean all

.PHONY : all clean fclean re bonus