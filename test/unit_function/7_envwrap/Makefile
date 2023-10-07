# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:40:27 by kamitsui          #+#    #+#              #
#    Updated: 2023/10/04 22:02:38 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target name
NAME = a.out

# Sources files
SRCS = test_envwrap.c \
	   environ.c \
	   error.c \
	   \
	   tokenize.c \
	   tokenize_markers.c \
	   tokenize_utils.c \
	   tokenize_is_flg.c \
	   tokenize_lstiter_funcs.c \
	   \
	   parse.c \
	   create_node.c \
	   parse_command.c \
	   is_pipe_command.c \
	   parse_argument.c \
	   parse_simple_command.c \
	   parse_pipe_command.c \
	   \
	   execute_command.c \
	   exec_file.c \
	   get_arguments.c \
	   wait_process.c \
	   \
	   debug.c \
	   debug_ast.c \
	   open_log.c \
	   \
	   env_lstiter_funcs.c \
	   env_utils.c \
	   ft_cd.c \
	   ft_pwd.c \
	   ft_env.c \
	   ft_export.c \
	   convert_env_list_to_two_darray.c \
	   substr_env.c \
	   \
	   free_utils.c

# Directories
PROJ_DIR = ../../..
SRCS_DIR = $(PROJ_DIR)/srcs \
		   $(PROJ_DIR)/srcs/environ \
		   $(PROJ_DIR)/srcs/parse_utils \
		   $(PROJ_DIR)/srcs/token \
		   $(PROJ_DIR)/srcs/traverse_utils \
		   $(PROJ_DIR)/srcs/execute_utils \
		   $(PROJ_DIR)/srcs/environ_utils \
		   $(PROJ_DIR)/srcs/debug \
		   srcs
OBJS_DIR = objs
DEPS_DIR = .deps

# vpath for serching source files in multiple directories
vpath %.c $(SRCS_DIR)

# Libraries
LIBFT_DIR = $(PROJ_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIB_PRINTF_DIR = $(PROJ_DIR)/ft_printf
LIB_PRINTF = $(LIB_PRINTF_DIR)/libftprintf.a

# Includes directories
INC_DIR = $(PROJ_DIR)/includes
LIB_PRINTF_INC_DIR = $(LIB_PRINTF_DIR)/includes

# Compile
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CF_LINK		=	-lreadline
CF_DEP		=	-MMD -MP -MF $(@:$(OBJS_DIR)/%.o=$(DEPS_DIR)/%.d)
CF_ASAN = -g -fsanitize=address
CF_DEBUG = -g3 -O0 -fno-omit-frame-pointer
CF_INC = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(LIB_PRINTF_INC_DIR)

# Object files and dependency files
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(DEPS_DIR)/, $(SRCS:.c=.d))

# Rules for building object files
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(DEPS_DIR)
	$(CC) $(CFLAGS) $(CF_INC) $(CF_DEP) -c $< -o $@

$(DEPS_DIR)/%.d: %.c
	@mkdir -p $(DEPS_DIR)

# Default target
all: $(NAME)

# <simple-command> Target
$(NAME): $(LIBFT) $(LIB_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(CF_LINK) $(OBJS) $(LIB_PRINTF) -o $(NAME)

#
# Library target
$(LIB_PRINTF): $(LIBFT)
	make -C $(LIB_PRINTF_DIR)
$(LIBFT):
	make -C $(LIBFT_DIR)

# Clean target
clean:
	rm -rf $(OBJS_DIR) $(DEPS_DIR)

# Clean and remove target
fclean: clean
	rm -f $(NAME)

# Rebuild target
re: fclean all

debug: fclean
	make $(NAME) WITH_DEBUG=1

asan: fclean
	make $(NAME) WITH_ASAN=1

ifdef WITH_ASAN
CFLAGS += $(CF_ASAN)
endif

ifdef WITH_DEBUG
CFLAGS += $(CF_DEBUG)
endif

# Enable dependency file
-include $(DEPS)

.PHONY: debug all clean fclean re

# SRCS = parse.c \
# 	   parse_command.c \
# 	   parse_simple_command.c \
# 	   parse_pipe_command.c \
# 	   parse_argument.c \
# 	   create_node.c \
# 	   is_pipe_command.c \
# 	   \
# 	   execute_command.c \
# 	   get_arguments.c \
# 	   wait_process.c \
# 	   exec_file.c \
# 	   \
# 	   execute_pipeline.c \
# 	   set_cmd_stack.c \
# 	   \
# 	   traverse_ast.c \
# 	   handle_command.c \
# 	   handle_argument.c \
# 	   handle_pipe_command.c \
# 	   handle_operator.c \
# 	   \
# 	   free_utils.c \
# 	   error.c \
# 	   substr_env.c \
# 	   \
# 	   debug.c \
# 	   debug_ast.c
# 
# SRCS_DIR = $(PROJ_DIR)/srcs \
# 		   $(PROJ_DIR)/srcs/environ \
# 		   $(PROJ_DIR)/srcs/parse_utils \
# 		   $(PROJ_DIR)/srcs/traverse_utils \
# 		   $(PROJ_DIR)/srcs/execute_utils \
# 		   $(PROJ_DIR)/srcs/environ_utils \
# 		   $(PROJ_DIR)/srcs/debug \
