# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/03 18:37:09 by jormoral          #+#    #+#              #
#    Updated: 2024/08/03 19:32:29 by jormoral         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


TARGET = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SOURCES = checkorden.c errorcheck.c firstpush.c free_stack.c ft_atoll.c \
		ft_error.c ft_lstadd_back_bonus.c ft_lstnew_bonus.c \
		ft_position.c ft_set_index.c ft_split.c ft_strlen.c ft_substr.c \
		ft_target.c number_move.c perform_movement.c push_swap.c pushmove.c \
		reverserotatemove.c rotatemove.c sort_three.c swapmove.c totalcost.c \
		ft_lstsize_bonus.c \

HEADERS = push_swap.h

OBJECTS = $(SOURCES:%.c=%.o)

all: $(TARGET)

# Compilación
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

# Enlazado
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o  $@ $^

# Limpieza
clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

# Ejecución
run: $(TARGET)
	./$@

re: clean all

.PHONY: all clean fclean re 
