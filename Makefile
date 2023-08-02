# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:04:53 by mogawa            #+#    #+#              #
#    Updated: 2023/07/26 15:50:01 by mogawa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	pipex
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f
FILES		=	pipex pipex_utils
BONUS_FILES	=	pipex_bonus get_next_line get_next_line_utils \
				pipex_bonus_utils
SRCS_DIR	=	./srcs/
BONUS_DIR	=	./srcs_bonus
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B		=	$(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))
INC			=	./includes/
OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)


%.o : %.c
	$(CC) $(CFLAGS) -I $(INC) -c -o $@ $<

$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

$(NAME)_bonus: $(OBJS_B)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS_B) ./libft/libft.a -o $(NAME)_bonus

bonus: $(NAME)_bonus

all: $(NAME)

debug: fclean
	make $(NAME) WITH_DEBUG=1

asan: fclean
	make $(NAME) WITH_ASAN=1

clean:
	$(RM) $(OBJS) $(OBJS_B)
	$(RM) ./bonus_files/$(OBJS_B)
	make -C ./libft clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME)_bonus
	make -C ./libft fclean

re: fclean all

ifdef WITH_ASAN
CFLAGS = -Wall -g3 -O0 -fsanitize=address -fno-omit-frame-pointer
endif

ifdef WITH_DEBUG
CFLAGS = -Wall -g3 -O0 -fno-omit-frame-pointer
endif

.PHONY: debug asan all clean fclean re