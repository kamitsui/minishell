# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:04:53 by mogawa            #+#    #+#              #
#    Updated: 2023/08/11 23:12:16 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target name
NAME		=	minishell

# Libraries
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIB_PRINTF_DIR = ft_printf
LIB_PRINTF = $(LIB_PRINTF_DIR)/libftprintf.a

# Compile
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
LFLAGS		=	-lreadline
DEP_CF = -MMD -MP -MF $(@:%.o=%.d)
LD_CD = -g -fsanitize=address

# Command
RM			=	rm -f


# Sources
FILES		=	main \
				input \
				error
BONUS_FILES	=	
SRCS_DIR	=	./srcs/
BONUS_DIR	=	./srcs_bonus/
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B		=	$(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))

# Include Header
INC			=	-Iincludes

# Objects
OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

# Dependency files
DEPS = $(SRCS:.c=.d)

# Rules for building object files
%.o : %.c
	$(CC) $(CFLAGS) $(INC) $(DEP_CF) -c $< -o $@

# Target
$(NAME): $(LIBFT) $(LIB_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) $(LIB_PRINTF) -o $(NAME)

# Bonus Target
$(NAME)_bonus: $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) $(LIBFT) -o $(NAME)_bonus

# Bonus Target
bonus: $(NAME)_bonus

# Default target
all: $(NAME)

# Library target
$(LIB_PRINTF): $(LIBFT)
	$(MAKE) -C $(LIB_PRINTF_DIR)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

debug: fclean
	make $(NAME) WITH_DEBUG=1

asan: fclean
	make $(NAME) WITH_ASAN=1

# Clean target
clean:
	$(RM) $(OBJS) $(DEPS) $(OBJS_BONUS)
	make -C ./libft clean

# Clean and remove target
fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)
#	$(RM) $(NAME)_bonus

# Rebuild target
re: fclean all

# Enable dependency file
-include $(DEPS)

ifdef WITH_ASAN
CFLAGS = -Wall -g3 -O0 -fsanitize=address -fno-omit-frame-pointer
endif

ifdef WITH_DEBUG
CFLAGS = -Wall -g3 -O0 -fno-omit-frame-pointer
endif

.PHONY: debug asan all clean fclean re bonus
