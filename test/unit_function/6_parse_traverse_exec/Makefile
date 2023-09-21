# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 13:40:27 by kamitsui          #+#    #+#              #
#    Updated: 2023/09/21 14:46:07 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target name
NAME1 = simple_command
NAME2 = pipe_command

# Sources files
SRCS = parse.c \
	   parse_command.c \
	   parse_simple_command.c \
	   parse_pipe_command.c \
	   parse_argument.c \
	   create_node.c \
	   is_pipe_command.c \
	   \
	   execute_command.c \
	   get_arguments.c \
	   wait_process.c \
	   exec_file.c \
	   \
	   execute_pipeline.c \
	   set_cmd_stack.c \
	   \
	   traverse_ast.c \
	   handle_command.c \
	   handle_argument.c \
	   handle_pipe_command.c \
	   handle_operator.c \
	   \
	   free_utils.c \
	   error.c \
	   substr_env.c \
	   \
	   debug.c \
	   debug_ast.c
SRCS_TEST1 = test_simple_command.c
SRCS_TEST2 = test_pipe_command.c

# Directories
PROJ_DIR = ../../..
SRCS_DIR = $(PROJ_DIR)/srcs \
		   $(PROJ_DIR)/srcs/parse_utils \
		   $(PROJ_DIR)/srcs/traverse_utils \
		   $(PROJ_DIR)/srcs/execute_utils \
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
OBJS1 = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o)) $(addprefix $(OBJS_DIR)/, $(SRCS_TEST1:.c=.o))
DEPS1 = $(addprefix $(DEPS_DIR)/, $(SRCS:.c=.d)) $(addprefix $(OBJS_DIR)/, $(SRCS_TEST1:.c=.d))
OBJS2 = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o)) $(addprefix $(OBJS_DIR)/, $(SRCS_TEST2:.c=.o))
DEPS2 = $(addprefix $(DEPS_DIR)/, $(SRCS:.c=.d)) $(addprefix $(OBJS_DIR)/, $(SRCS_TEST2:.c=.d))

# Rules for building object files
$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(DEPS_DIR)
	$(CC) $(CFLAGS) $(INC_CF) $(DEP_CF) $(LD_CF) -c $< -o $@
#	$(CC) $(CFLAGS) $(INC_CF) $(DEP_CF) -c $< -o $@

$(DEPS_DIR)/%.d: %.c
	@mkdir -p $(DEPS_DIR)

# Default target
all: $(NAME1) $(NAME2)

# <simple-command> Target
$(NAME1): $(LIBFT) $(LIB_PRINTF) $(OBJS1)
	$(CC) $(CFLAGS) $(LFLAGS) $(LD_CF) $(OBJS1) $(LIB_PRINTF) -o $(NAME1)
#	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS1) $(LIB_PRINTF) -o $(NAME1)

# <pipe-command> Target
$(NAME2): $(LIBFT) $(LIB_PRINTF) $(OBJS2)
	$(CC) $(CFLAGS) $(LFLAGS) $(LD_CF) $(OBJS2) $(LIB_PRINTF) -o $(NAME2)
#	$(CC) $(CFLAGS) $(LFLAGS) $(OBJS2) $(LIB_PRINTF) -o $(NAME2)
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
	rm -f $(NAME1) $(NAME2)

# Rebuild target
re: fclean all

# Enable dependency file
-include $(DEPS)

.PHONY: debug all clean fclean re

#cw -Iincludes srcs/execute_utils/exec_pipe_cmd.c srcs/execute_utils/exec_file.c srcs/error.c srcs/environ_utils/substr_env.c ft_printf/libftprintf.a -g -fsanitize=address
