# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:04:53 by mogawa            #+#    #+#              #
#    Updated: 2023/09/06 16:30:39 by mogawa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Target name
NAME		=	minishell

# Libraries
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIB_PRINTF_DIR = ft_printf
LIB_PRINTF = $(LIB_PRINTF_DIR)/libftprintf.a

# Sources files
SRCS = main.c \
	   \
	   input.c \
	   \
	   tokenize.c \
	   \
	   parse.c \
	   parse_argument.c \
	   parse_command.c \
	   parse_simple_command.c \
	   parse_pipe_command.c \
	   create_node.c \
	   is_pipe_command.c \
	   \
	   traverse_ast.c \
	   handle_command.c \
	   handle_argument.c \
	   handle_operator.c \
	   handle_pipe_command.c \
	   \
	   exec_file.c \
	   execute_command.c \
	   get_arguments.c \
	   wait_process.c \
	   \
	   execute_pipeline.c \
	   set_cmd_stack.c \
	   \
	   substr_env.c \
	   \
	   error.c \
	   free_utils.c \
	   \
	   debug.c \
	   debug_ast.c
#	   get_next_token.c \
#	   get_token_type.c \
#	   count_tokens.c \

SRCS_B =

# Directories
SRCS_DIR = srcs \
		   srcs/tokenize_utils \
		   srcs/parse_utils \
		   srcs/execute_utils \
		   srcs/traverse_utils \
		   srcs/environ_utils \
		   srcs/debug
SRCS_B_DIR = srcs_bonus
OBJS_DIR = objs
OBJS_B_DIR = objs_b
DEPS_DIR = .deps
DEPS_B_DIR = .deps_b

# vpath for serching source files in multiple directories
vpath %.c $(SRCS_DIR) $(SRCS_B_DIR)

# Compile
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
LFLAGS		=	-lreadline
DEP_CF		=	-MMD -MP -MF $(@:$(OBJS_DIR)/%.o=$(DEPS_DIR)/%.d)
LD_CF = -g -fsanitize=address
INC = -Iincludes -I./libft -I./ft_printf/include

# Command
RM			=	rm -f

# Object files and dependency files
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
OBJS_B = $(addprefix $(OBJS_B_DIR)/, $(SRCS_B:.c=.o))
DEPS = $(addprefix $(DEPS_DIR)/, $(SRCS:.c=.d))
DEPS_B = $(addprefix $(DEPS_B_DIR)/, $(SRCS_B:.c=.d))

# Rules for building object files
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(DEPS_DIR)
	$(CC) $(CFLAGS) $(INC) $(DEP_CF) -c $< -o $@
#	$(CC) $(CFLAGS) $(INC) $(DEP_CF) $(LD_CF) -c $< -o $@

$(DEPS_DIR)/%.d: %.c
	@mkdir -p $(DEPS_DIR)

# Default target
all: $(NAME)

# Mandatory Target
$(NAME): $(LIBFT) $(LIB_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) $(LIB_PRINTF) -o $(NAME)
#	$(CC) $(CFLAGS) $(LFLAGS) $(LD_CF) $(OBJS) $(LIB_PRINTF) -o $(NAME)

# Bonus Target
bonus: $(NAME)_bonus

# Bonus Target
$(NAME)_bonus: $(LIBFT) $(LIB_PRINTF) $(OBJS_B)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS_B) $(LIBFT_PRINTF) -o $(NAME)_bonus

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
	rm -rf $(OBJS_DIR) $(DEPS_DIR)
	make -C ./libft clean

# Clean and remove target
fclean: clean
	$(RM) $(LIBFT) $(LIB_PRINTF)
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

token:
	cc -Wall -Wextra -g -fsanitize=address ./srcs/token/tokenize.c ./srcs/token/tokenize_utils.c -I./libft ./libft/libft.a -lreadline -o token
.PHONY: token
