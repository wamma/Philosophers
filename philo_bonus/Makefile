# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 19:26:01 by hyungjup          #+#    #+#              #
#    Updated: 2023/05/16 15:50:35 by hyungjup         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc
CFLAG = -Wall -Wextra -Werror -g#-fsanitize=thread

MAN_SRCS_DIR =	./srcs

MAN_OBJS_DIR = ./objs

MAN_INC_DIR = ./includes

SRCS = ./srcs/main_bonus.c \
	   ./srcs/ft_init_bonus.c \
	   ./srcs/ft_philo_bonus.c \
	   ./srcs/ft_print_bonus.c \
	   ./srcs/ft_time_bonus.c \
	   ./srcs/ft_utils_bonus.c \
	   ./srcs/ft_routine_bonus.c

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