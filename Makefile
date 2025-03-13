# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makamins <makamins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 13:49:09 by makamins          #+#    #+#              #
#    Updated: 2025/03/11 18:24:29 by makamins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror 
SRC = main.c
CC = cc
FT_PRINTF = ft_printf/ft_printf.a
LIBFT = libft/libft.a

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(LIBFT):
	@make -C libft
$(FT_PRINTF):
	@make -C ft_printf
	
$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF)
	chmod +x $(NAME) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make clean -C ft_printf
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C ft_printf
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re 