# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 19:26:01 by hyungjup          #+#    #+#              #
#    Updated: 2023/04/25 21:33:09 by hyungjup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAG = -Wall -Wextra -Werror -fsanitize=undefined

MAN_SRCS_DIR =	./srcs

MAN_OBJS_DIR = ./objs

MAN_INC_DIR = ./includes

SRCS = ./srcs/ft_atoi.c \
	   ./srcs/main.c \
	   ./srcs/philo_check.c \
	   ./srcs/philo_init.c \
	   ./srcs/philo_utils.c \
	   ./srcs/philo.c \
	   ./srcs/time.c \
	   ./srcs/print.c

OBJS = $(addprefix $(MAN_OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

vpath %.c $(MAN_SRCS_DIR)

RM = rm -rf

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAG) -o $@ $^
	@echo "\033[1;32m$(NAME) created"

$(MAN_OBJS_DIR) :
	@mkdir -p $(MAN_OBJS_DIR)

$(MAN_OBJS_DIR)/%.o : %.c | $(MAN_OBJS_DIR)
	@$(CC) $(CFLAG) -o $@ -I$(MAN_INC_DIR) -c $^

clean :
	@$(RM) $(MAN_OBJS_DIR)

fclean : clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "\033[0;33m all deleted"

re : fclean all

.PHONY: all clean fclean re bonus