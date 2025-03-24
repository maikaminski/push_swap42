# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makamins <makamins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/11 13:49:09 by makamins          #+#    #+#              #
#    Updated: 2025/03/20 13:54:10 by makamins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
FLAGS = -Wall -Wextra -Werror -g
SRC = prepare_list_a.c prepare_list_b.c push_swap_init_list.c \
	push_swap.c push.c reverse_rotate.c rotate.c swap.c three_numbers.c \
	utils.c utils2.c validations.c
CC = cc
FT_PRINTF = ft_printf/ft_printf.a
# LIBFT = libft/libft.a

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

# $(LIBFT):
# 	@make -C libft
$(FT_PRINTF):
	@make -C ft_printf
	
$(NAME): $(OBJS) $(FT_PRINTF) 
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(FT_PRINTF) 
	chmod +x $(NAME) 

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@make clean -C ft_printf


fclean: clean
	rm -f $(NAME)
	@make fclean -C ft_printf


re: fclean all

.PHONY: all clean fclean re 