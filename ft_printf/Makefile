# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 14:39:52 by kamitsui          #+#    #+#              #
#    Updated: 2023/10/05 21:28:18 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Directories
SRC_DIR = srcs \
		  srcs/process_utils \
		  srcs/conversion_utils \
		  srcs/conversion_utils/unsigned_arg \
		  srcs/conversion_utils/signed_arg \
		  srcs/formalize_utils
OBJ_DIR = objs
INC_DIR = includes
DEP_DIR = .deps
LIBFT_DIR = ../libft

# Source files
SRCS = \
	   ft_printf.c \
	   ft_dprintf.c \
	   initialize.c \
	   process.c \
	   conversion.c \
	   join_to_out.c \
	   \
	   letter.c \
	   flag.c \
	   field.c \
	   width.c \
	   precision.c \
	   get_field_nbr.c \
	   prefix.c \
	   type.c \
	   error.c \
	   add_to_buff.c \
	   \
	   decimal.c \
	   unsign_decimal.c \
	   octal.c \
	   hexadecimal.c \
	   pointer.c \
	   character.c \
	   string.c \
	   percent.c \
	   itoa_buff.c \
	   \
	   unsign_va_arg.c \
	   unsign_hh.c \
	   unsign_ll.c \
	   unsign_h.c \
	   unsign_l.c \
	   unsign_int.c \
	   \
	   sign_va_arg.c \
	   sign_hh.c \
	   sign_ll.c \
	   sign_h.c \
	   sign_l.c \
	   sign_int.c \
	   \
	   formalize.c \
	   adjust.c \
	   adjust_width.c \
	   adjust_prec.c \
	   adjust_number.c \
	   adjust_string.c \
	   adjust_sign.c \
	   adjust_hash.c \
	   pad_str.c \
	   pad_n_str.c \
	   pad_width.c \
	   pad_prec.c \
	   sequence_unsigned.c \
	   sequence_signed.c

# Object files and dependency files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(DEP_DIR)/, $(SRCS:.c=.d))

# Library name
NAME = libftprintf.a
LIBFT = $(LIBFT_DIR)/libft.a

# vpath for serching source files in multiple directories
vpath %.c $(SRC_DIR)

# Compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror
CF_ASAN = -g3 -O0 -fsanitize=address -fno-omit-frame-pointer
CF_DEBUG = -g3 -O0 -fno-omit-frame-pointer
CF_INC = -I$(INC_DIR) -I$(LIBFT_DIR)
CF_DEP = -MMD -MP -MF $(@:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

# Rules for building object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)
	$(CC) $(CFLAGS) $(CF_INC) $(CF_DEP) -c $< -o $@

$(DEP_DIR)/%.d: %.c
	@mkdir -p $(DEP_DIR)

# Default target
all: $(NAME)

# Library target
$(NAME): $(LIBFT) $(DEPS) $(OBJS)
	cp $(LIBFT) $@
	ar rcs $@ $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

bonus: $(NAME)

debug: fclean
	make $(NAME) WITH_DEBUG=1

asan: fclean
	make $(NAME) WITH_ASAN=1

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR)

# Clean and remove library target
fclean: clean
	rm -f $(NAME)

# Rebuild target
re: fclean all

-include $(DEPS)

ifdef WITH_ASAN
CFLAGS += $(CF_ASAN)
endif

ifdef WITH_DEBUG
CFLAGS += $(CF_DEBUG)
endif

.PHONY: all bonus clean fclean re asan debug
