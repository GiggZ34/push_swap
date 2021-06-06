# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grivalan <grivalan@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/27 13:07:50 by grivalan          #+#    #+#              #
#    Updated: 2021/06/06 15:03:32 by grivalan         ###   ########lyon.fr    #
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

NAME =			push_swap
NAME2 =			checker
OBJS_PATH =		.objs
SRCS_PATH =		src

SRCS_FILES =	main.c				\
				numbers_to_list.c	\
				trash_program.c		\
				utils_list_1.c		\
				utils_list_2.c		\
				utils_list_3.c		\
				process.c			\
				process_sort.c		\
				generate_actions.c	\
				treatment_list.c	\
				ft_calloc.c			\
				ft_atoi.c			\
				ft_bzero.c			\
				ft_strlen.c			\
				ft_isdigit.c		\
				ft_strncmp.c		\
				ft_memcpy.c			\
				ft_memset.c			\
				ft_abs.c			\
				ft_putnbr_fd.c

SRCS_FILES_CHECKER	=	numbers_to_list.c		\
						trash_program.c			\
						utils_list_1.c			\
						utils_list_2.c			\
						utils_list_3.c			\
						process_sort.c			\
						generate_actions.c		\
						ft_calloc.c				\
						ft_atoi.c				\
						ft_bzero.c				\
						ft_strlen.c				\
						ft_isdigit.c			\
						ft_strncmp.c			\
						ft_memcpy.c				\
						ft_memset.c				\
						ft_abs.c				\
						ft_putnbr_fd.c			\
						checker/main.c			\
						checker/process.c		\
						checker/get_next_line.c	\
						checker/ft_realloc.c	\
						checker/ft_strpos.c		\
						checker/ft_substr.c		\
						checker/exit_program.c	\
						checker/treatment_list.c

OBJS_FILES =			$(SRCS_FILES:.c=.o)
OBJS_FILES_CHECKER =	$(SRCS_FILES_CHECKER:.c=.o)

INC_PATH =	includes
INC_FILES = push_swap.h\
			checker.h
INC = $(addprefix $(INC_PATH)/, $(INC_FILES))

SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS_FILES))

SRCS_CHECKER = $(addprefix $(SRCS_PATH)/, $(SRCS_FILES_CHECKER))
OBJS_CHECKER = $(addprefix $(OBJS_PATH)/, $(OBJS_FILES_CHECKER))

CC = gcc

CFLAGS =	-Wall -Wextra -Werror

DIR =	checker

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c $(INC)
			@mkdir -p $(OBJS_PATH) $(addprefix $(OBJS_PATH)/, $(DIR))
			@$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH)
			@printf "$(ERASE)$(YELLOW)$<$(END)"

$(NAME):	$(OBJS)
		@printf "$(ERASE)";
		@$(CC) -o $(NAME) $(OBJS) -I $(INC_PATH)
		@printf "$(ERASE)$(GREEN)Push Swap\t\t->\t\tCOMPILED$(END)\n"

$(NAME2):	$(OBJS_CHECKER)
		@printf "$(ERASE)";
		@$(CC) -o $(NAME2) $(OBJS_CHECKER) -I $(INC_PATH)
		@printf "$(ERASE)$(GREEN)Checker\t\t\t->\t\tCOMPILED$(END)\n"

all :		$(NAME)

bonus :	all $(NAME2)

clean :
		@rm -rf $(OBJS_PATH)
		@printf "$(ERASE)$(RED)Push Swap\t\t->\t\tDESTROY$(END)\n"

fclean :	clean
			@rm -f $(NAME)
			@rm -f $(NAME2)

re : fclean all

norm:
			@norminette $(SRCS) $(INC)
			@norminette $(SRCS_CHECKER)
			@printf "$(YELLOW)norminette push_swap\t->\tfinish$(END)\n"

.PHONY : all bonus clean fclean re norm checker push_swap
