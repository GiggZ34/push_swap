# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 13:07:50 by grivalan          #+#    #+#              #
#    Updated: 2021/05/30 19:29:54 by grivalan         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


ERASE		=	\033[2K\r
GREY		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PINK		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m
BOLD		=	\033[1m
UNDER		=	\033[4m
SUR			=	\033[7m
END			=	\033[0m

NAME =		push_swap

SRCS =		src/main.c\
			src/numbers_to_list.c\
			src/trash_program.c\
			src/utils_list_1.c\
			src/utils_list_2.c\
			src/process.c\
			src/generate_actions.c\
			src/treatment_list.c\
			src/ft_calloc.c\
			src/ft_atoi.c\
			src/ft_bzero.c\
			src/ft_strlen.c\
			src/ft_isdigit.c\
			src/ft_memcpy.c\
			src/ft_memset.c\
			src/ft_abs.c\

CC = gcc

CFLAGS =	-Wall -Wextra -Werror

INCLUDES =	includes

OBJS =		$(SRCS:.c=.o)

%.o: %.c includes/push_swap.h
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)
			@printf "$(ERASE)$(YELLOW)$<$(END)"

$(NAME):	$(OBJS)
		@printf "$(ERASE)";
		@$(CC) -g3 -fsanitize=address -o $(NAME) $(OBJS) -I $(INCLUDES)
		@printf "$(ERASE)$(GREEN)Push Swap\t\t->\t\tCOMPILED$(END)\n"

all :		$(NAME)

clean :
		@rm -rf $(OBJS)
		@printf "$(ERASE)$(RED)Push Swap\t\t->\t\tDESTROY$(END)\n"

fclean :	clean
			@rm -f $(NAME)

re : fclean all

norme:
			@norminette -R CheckForbiddenSourceHeader $(SRCS) $(INCLUDES)
			@printf "$(YELLOW)norminette push_swap\t->\tfinish$(END)\n"

.PHONY : all clean fclean re norme
