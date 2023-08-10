# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:04:53 by mogawa            #+#    #+#              #
#    Updated: 2023/08/10 22:10:11 by kamitsui         ###   ########.fr        #
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
DEP_CF = -MMD -MP -MF $(@:$(SRCS_DIR)/%.o=$(DEP_DIR)/%.d)
LD_CD = -g -fsanitize=address

# Command
RM			=	rm -f


# Sources
FILES		=	main \
				input
BONUS_FILES	=	pipex_bonus get_next_line get_next_line_utils \
				pipex_bonus_utils
SRCS_DIR	=	./srcs/
BONUS_DIR	=	./srcs_bonus
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_B		=	$(addprefix $(BONUS_DIR), $(addsuffix .c, $(BONUS_FILES)))

# Include Header
INC			=	-Iincludes -Ilibft

# Objects
OBJS		=	$(SRCS:.c=.o)
OBJS_B		=	$(SRCS_B:.c=.o)

# Dependency files
DEP_DIR = .dep
DEPS = $(addprefix $(DEP_DIR)/, $(SRCS:.c=.d))

# Rules for building object files
%.o : %.c
	@mkdir -p $(DEP_DIR)
	$(CC) $(CFLAGS) $(LFLAGS) $(INC) $(DEP_CF) -c $< -o $@
#	$(CC) $(CFLAGS) $(LFLAGS) $(INC) $(DEP_CF) $(LD_CD) -c $< -o $@

# Target
$(NAME): $(OBJS)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a -o $(NAME)

# Bonus Target
$(NAME)_bonus: $(OBJS_B)
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJS_B) ./libft/libft.a -o $(NAME)_bonus

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
	$(RM) $(OBJS) $(OBJS_B)
	$(RM) ./bonus_files/$(OBJS_B)
	make -C ./libft clean

# Clean and remove target
fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME)_bonus
	make -C ./libft fclean

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
