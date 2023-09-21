# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 14:39:52 by kamitsui          #+#    #+#              #
#    Updated: 2023/09/21 13:10:40 by kamitsui         ###   ########.fr        #
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
CF = -Wall -Wextra -Werror
LDF = -g -fsanitize=address
INC_CF = -I$(INC_DIR) -I$(LIBFT_DIR)
DEP_CF = -MMD -MP -MF $(@:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

# Rules for building object files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)
	$(CC) $(CF) $(INC_CF) $(DEP_CF) -c $< -o $@

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

# Clean target
clean:
	rm -rf $(OBJ_DIR) $(DEP_DIR)

# Clean and remove library target
fclean: clean
	rm -f $(NAME)

# Rebuild target
re: fclean all

-include $(DEPS)

.PHONY: all bonus clean fclean re
