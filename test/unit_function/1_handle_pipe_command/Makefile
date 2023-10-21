# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:40:27 by kamitsui          #+#    #+#              #
#    Updated: 2023/10/21 13:28:23 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target name
NAME = minishell

# Sources files
SRCS = handle_operator.c \
	   handle_pipe_command.c \
	   handle_expansion.c \
	   handle_command.c \
	   handle_io_redirections.c \
	   \
	   buck_up_fd.c \
	   recover_fd.c \
	   here_doc.c \
	   input_redirection.c \
	   out_redirection.c \
	   \
	   is_connector.c \
	   is_and_list.c \
	   is_or_list.c \
	   is_pipe.c \
	   is_redirection.c \
	   is_expansion.c \
	   is_squote.c \
	   is_dquote.c \
	   is_variable.c \
	   is_end.c \
	   is_builtins_command.c \
	   is_include_pipe_command.c \
	   is_include_redirection.c \
	   \
	   parse.c \
	   parse_command.c \
	   parse_connector.c \
	   parse_pipe_command.c \
	   parse_simple_command.c \
	   parse_io_redirections.c \
	   parse_executable.c \
	   get_command_value.c \
	   get_pipe_command_value.c \
	   get_executable_value.c \
	   get_redirection_value.c \
	   get_simple_command_value.c \
	   str_add_to_buff.c \
	   str_join_to_out.c \
	   \
	   exec_file.c \
	   get_arguments.c \
	   wait_process.c \
	   execute_builtins_command.c \
	   execute_command.c \
	   \
	   substr_env.c \
	   \
	   error.c \
	   \
	   create_node.c \
	   \
	   free_utils.c \
	   \
	   debug.c \
	   debug_ast.c \
	   debug_flag.c \
	   debug_status.c \
	   debug_leaks.c \
	   open_log.c \
	   \
	   env_lstiter_funcs.c \
	   convert_env_list_to_two_darray.c \
	   environ.c \
	   env_utils.c \
	   ft_cd.c \
	   ft_env.c \
	   ft_pwd.c \
	   ft_export.c \
	   ft_echo.c \
	   ft_exit.c \
	   ft_unset.c \
	   \
	   expansion.c \
	   \
	   test_handle_operator.c

# Directories
PROJ_DIR = ../../..
GNL_DIR = $(PROJ_DIR)/get_next_line

SRCS_DIR = $(PROJ_DIR)/srcs \
		   $(PROJ_DIR)/srcs/parse_utils \
		   $(PROJ_DIR)/srcs/parse_utils/get_value_utils \
		   $(PROJ_DIR)/srcs/parse_utils/is_node_type \
		   $(PROJ_DIR)/srcs/traverse_utils \
		   $(PROJ_DIR)/srcs/traverse_utils/fd_utils \
		   $(PROJ_DIR)/srcs/execute_utils \
		   $(PROJ_DIR)/srcs/builtins \
		   $(PROJ_DIR)/srcs/environ_utils \
		   $(PROJ_DIR)/srcs/environ \
		   $(PROJ_DIR)/srcs/expansion \
		   $(PROJ_DIR)/srcs/debug \
		   $(GNL_DIR) \
		   srcs
SRCS_GNL = \
		   get_next_line_utils.c \
		   get_next_line.c

OBJS_DIR = objs
DEPS_DIR = .deps

# vpath for serching source files in multiple directories
vpath %.c $(SRCS_DIR) $(SRCS_B_DIR)

# Libraries
LIBFT_DIR = $(PROJ_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIB_PRINTF_DIR = $(PROJ_DIR)/ft_printf
LIB_PRINTF = $(LIB_PRINTF_DIR)/libftprintf.a

# Includes DIR
INC_DIR = $(PROJ_DIR)/includes
LIB_PRINTF_INC_DIR = $(LIB_PRINTF_DIR)/includes

# Compile
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
LFLAGS		=	-lreadline
DEP_CF		=	-MMD -MP -MF $(@:$(OBJS_DIR)/%.o=$(DEPS_DIR)/%.d)
LD_CF = -g -fsanitize=address
INC_CF = -I$(INC_DIR) -I$(LIB_PRINTF_INC_DIR) -I$(LIBFT_DIR) -I$(GNL_DIR)

# Object files and dependency files
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(DEPS_DIR)/, $(SRCS:.c=.d))
OBJS_GNL = $(addprefix $(OBJS_DIR)/, $(SRCS_GNL:.c=.o))
DEPS_GNL = $(addprefix $(DEPS_DIR)/, $(SRCS_GNL:.c=.d))

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
$(NAME): $(LIBFT) $(LIB_PRINTF) $(OBJS_GNL) $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(LD_CF) $(OBJS) $(OBJS_GNL) $(LIB_PRINTF) -o $(NAME)

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
