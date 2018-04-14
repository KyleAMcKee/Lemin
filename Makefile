#*****************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmckee <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 10:55:28 by kmckee            #+#    #+#              #
#    Updated: 2018/04/14 10:13:29 by kmckee           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	lem-in
SRCDIR		=	srcs/
INCDIR		= 	includes/
OBJDIR		=	temp/
LIBFT		=	libft/
CC			=	gcc
FLAGS		=	-Wall -Werror -Wextra
GFX         =   mlx/libmlx.a -framework OpenGL -framework AppKit

SOURCES		=	main.c \
				parse.c \
				parse_tunnels.c \
				bfs.c \
				queue.c \
				adjacency_list.c \
				rooms.c \
				paths.c \
				utilities_1.c \
				utilities_2.c \
				move_ants.c \
				ant_utilities.c 
 
SRCS		=	$(addprefix $(SRCDIR), $(SOURCES))
OBJS		=	$(addprefix $(OBJDIR), $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\x1b[31m\nBeep boop beep boop...\x1b[0m"
	@make re -C $(LIBFT)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT)libft.a -o $(NAME) 
	@echo "\x1b[32mDone\x1b[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@mkdir -p temp
	@$(CC) $(FLAGS) -I $(INCDIR) -c -o $@ $<
	@printf "\x1b[33m*\x1b[0m"

clean:
	@echo "\x1b[31mCleaning...\x1b[0m"
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: all test clean fclean re
