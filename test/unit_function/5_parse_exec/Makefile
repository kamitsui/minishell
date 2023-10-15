# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:40:27 by kamitsui          #+#    #+#              #
#    Updated: 2023/10/14 21:01:48 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target name
NAME = a.out

# Sources files
SRCS = parse.c \
	   parse_command.c \
	   parse_simple_command.c \
	   parse_pipe_command.c \
	   parse_argument.c \
	   create_node.c \
	   count_pipe_command.c \
	   parse_io_redirection.c \
	   parse_operator.c \
	   parse_file.c \
	   \
	   is_operator.c \
	   is_and_list.c \
	   is_or_list.c \
	   is_pipe.c \
	   is_string.c \
	   is_redirection.c \
	   is_expansion.c \
	   is_squote.c \
	   is_dquote.c \
	   is_variable.c \
	   \
	   execute_command.c \
	   get_arguments.c \
	   wait_process.c \
	   exec_file.c \
	   \
	   environ.c \
	   env_lstiter_funcs.c \
	   convert_env_list_to_two_darray.c \
	   env_utils.c \
	   \
	   ft_cd.c \
	   ft_env.c \
	   ft_export.c \
	   ft_pwd.c \
	   \
	   free_utils.c \
	   \
	   error.c \
	   substr_env.c \
	   \
	   debug.c \
	   debug_ast.c \
	   debug_flag.c \
	   debug_leaks.c \
	   open_log.c \
	   \
	   test_parse_exec.c

# Directories
PROJ_DIR = ../../..
SRCS_DIR = $(PROJ_DIR)/srcs \
		   $(PROJ_DIR)/srcs/parse_utils \
		   $(PROJ_DIR)/srcs/parse_utils/is_node_type \
		   $(PROJ_DIR)/srcs/execute_utils \
		   $(PROJ_DIR)/srcs/environ \
		   $(PROJ_DIR)/srcs/environ_utils \
		   $(PROJ_DIR)/srcs/debug \
		   srcs
OBJS_DIR = objs
DEPS_DIR = .deps

# vpath for serching source files in multiple directories
vpath %.c $(SRCS_DIR) $(SRCS_B_DIR)

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
LFLAGS		=	-lreadline
DEP_CF		=	-MMD -MP -MF $(@:$(OBJS_DIR)/%.o=$(DEPS_DIR)/%.d)
LD_CF = -g -fsanitize=address
INC_CF = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(LIB_PRINTF_INC_DIR)

# Object files and dependency files
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(DEPS_DIR)/, $(SRCS:.c=.d))

# Rules for building object files
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(DEPS_DIR)
	$(CC) $(CFLAGS) $(INC_CF) $(DEP_CF) $(LD_CF) -c $< -o $@
#	$(CC) $(CFLAGS) $(INC_CF) $(DEP_CF) -c $< -o $@

$(DEPS_DIR)/%.d: %.c
	@mkdir -p $(DEPS_DIR)

# Default target
all: $(NAME)

# Mandatory Target
$(NAME): $(LIBFT) $(LIB_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(LD_CF) $(OBJS) $(LIB_PRINTF) -o $(NAME)
#	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS) $(LIB_PRINTF) -o $(NAME)

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

# Enable dependency file
-include $(DEPS)

.PHONY: debug all clean fclean re

#cw -Iincludes srcs/execute_utils/exec_pipe_cmd.c srcs/execute_utils/exec_file.c srcs/error.c srcs/environ_utils/substr_env.c ft_printf/libftprintf.a -g -fsanitize=address
