# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mogawa <mogawa@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 16:04:53 by mogawa            #+#    #+#              #
#    Updated: 2023/10/17 03:12:12 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Target name
NAME		=	minishell

# Libraries
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIB_PRINTF_DIR = ./ft_printf
LIB_PRINTF_INC_DIR = $(LIB_PRINTF_DIR)/includes
LIB_PRINTF = $(LIB_PRINTF_DIR)/libftprintf.a

# Readline
LIB_RL = libreadline.dylib
LIB_RL_DYLIB_PATH = $(shell find /opt/homebrew -name $(LIB_RL) 2>/dev/null)
LIB_RL_LIB_DIR = $(dir $(LIB_RL_DYLIB_PATH))
LIB_RL_INC_DIR = $(subst /lib/,/include,$(LIB_RL_LIB_DIR))

# Sources files
SRCS = main.c \
	   \
	   input.c \
	   \
	   tokenize.c \
	   tokenize_is_flg.c \
	   tokenize_lstiter_funcs.c \
	   tokenize_markers.c \
	   tokenize_utils.c \
	   \
	   parse.c \
	   create_node.c \
	   get_value.c \
	   parse_connector.c \
	   parse_command.c \
	   parse_pipe_command.c \
	   parse_simple_command.c \
	   parse_io_redirections.c \
	   parse_executable.c \
	   \
	   is_connector.c \
	   is_and_list.c \
	   is_or_list.c \
	   is_pipe.c \
	   is_redirection.c \
	   is_string.c \
	   is_expansion.c \
	   is_squote.c \
	   is_dquote.c \
	   is_variable.c \
	   is_end.c \
	   \
	   traverse_ast.c \
	   handle_operator.c \
	   handle_connector.c \
	   handle_command.c \
	   handle_argument.c \
	   handle_pipe_command.c \
	   handle_redirection.c \
	   handle_file.c \
	   \
	   buck_up_fd.c \
	   recover_fd.c \
	   \
	   exec_file.c \
	   execute_command.c \
	   get_arguments.c \
	   wait_process.c \
	   execute_script_file.c \
	   execute_pipeline.c \
	   set_cmd_stack.c \
	   \
	   substr_env.c \
	   environ.c \
	   env_utils.c \
	   env_lstiter_funcs.c \
	   convert_env_list_to_two_darray.c \
	   \
	   ft_cd.c \
	   ft_env.c \
	   ft_export.c \
	   ft_pwd.c \
	   ft_unset.c \
	   ft_echo.c \
	   \
	   \
	   error.c \
	   free_utils.c \
	   \
	   debug.c \
	   debug_ast.c \
	   debug_parse.c \
	   debug_flag.c \
	   open_log.c \
	   debug_status.c \
	   debug_leaks.c
#	   signal.c \要確認 include/signal.hがあるとkamitsui環境ではコンパイルできない。

SRCS_B =

# Directories
SRCS_DIR = ./srcs \
		   ./srcs/token \
		   ./srcs/tokenize_utils \
		   ./srcs/parse_utils \
		   ./srcs/parse_utils/is_node_type \
		   ./srcs/execute_utils \
		   ./srcs/traverse_utils \
		   ./srcs/traverse_utils/fd_utils \
		   ./srcs/environ \
		   ./srcs/environ_utils \
		   ./srcs/signal \
		   ./srcs/debug
SRCS_B_DIR = ./srcs_bonus
OBJS_DIR = ./objs
OBJS_B_DIR = ./objs_b
DEPS_DIR = .deps
DEPS_B_DIR = .deps_b
INC_DIR = ./includes

# vpath for serching source files in multiple directories
vpath %.c $(SRCS_DIR) $(SRCS_B_DIR)

# Compile
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
CF_LINK		=	-lreadline
CF_DEP		=	-MMD -MP -MF $(@:$(OBJS_DIR)/%.o=$(DEPS_DIR)/%.d)
CF_DYLIB = -L$(LIB_RL_LIB_DIR)
CF_INC = -I$(INC_DIR) -I$(LIBFT_DIR) -I$(LIB_PRINTF_INC_DIR) -I$(LIB_RL_INC_DIR)

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
	$(CC) $(CFLAGS) $(CF_INC) $(CF_DEP) -c $< -o $@

$(DEPS_DIR)/%.d: %.c
	@mkdir -p $(DEPS_DIR)

# Default target
all: $(NAME)

# Mandatory Target
$(NAME): $(LIBFT) $(LIB_PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(CF_LINK) $(CF_DYLIB) $(OBJS) $(LIB_PRINTF) -o $(NAME)

# Bonus Target
bonus: $(NAME)_bonus

# Bonus Target
$(NAME)_bonus: $(LIBFT) $(LIB_PRINTF) $(OBJS_B)
	$(CC) $(CFLAGS) $(CF_LINK) $(CF_DYLIB) $(OBJS_B) $(LIBFT_PRINTF) -o $(NAME)_bonus

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
	cc -Wall -Wextra -g3 -O0 -fsanitize=address ./srcs/token/tokenize.c ./srcs/token/tokenize_utils.c \
	./srcs/token/tokenize_lstiter_funcs.c ./srcs/token/tokenize_markers.c ./srcs/token/tokenize_is_flg.c \
	./srcs/environ/env_lstiter_funcs.c ./srcs/environ/env_utils.c ./srcs/environ/environ.c ./srcs/environ/ft_pwd.c \
	./srcs/environ/ft_cd.c ./srcs/environ/ft_env.c ./srcs/environ/ft_export.c ./srcs/environ/ft_unset.c \
	-Iincludes -Ilibft -Ift_printf/includes ./libft/libft.a ./ft_printf/libftprintf.a -lreadline \
	-o token
#	./srcs/token/token_expansion.c \

leak:
	cc -Wall -Wextra -g3 -O0 ./srcs/token/tokenize.c ./srcs/token/tokenize_utils.c \
	./srcs/token/tokenize_lstiter_funcs.c ./srcs/token/tokenize_markers.c ./srcs/token/tokenize_is_flg.c \
	./srcs/environ/env_lstiter_funcs.c ./srcs/environ/env_utils.c ./srcs/environ/environ.c ./srcs/environ/ft_pwd.c \
	./srcs/environ/ft_cd.c ./srcs/environ/ft_env.c ./srcs/environ/ft_export.c ./srcs/environ/ft_unset.c \
	-Iincludes -Ilibft -Ift_printf/includes ./libft/libft.a ./ft_printf/libftprintf.a -lreadline \
	./srcs/token/token_expansion.c \
	-o token
.PHONY: token leak

expand:
