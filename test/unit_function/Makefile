# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 13:58:25 by kamitsui          #+#    #+#              #
#    Updated: 2023/08/17 18:33:49 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target Directory
DIR1 = 1_handle_operator
DIR2 = 2_traverse
DIR3 = 3_parse

# Target name
NAME1 = $(DIR1)/a.out
NAME2 = $(DIR2)/a.out
NAME3 = $(DIR3)/a.out

# Run Target
RUN1 = ./$(NAME1) ; echo "\n\n"
RUN2 = ./$(NAME2) ; echo "\n\n"
RUN3 = ./$(NAME3) ; echo "\n\n"

# Default target
all : $(NAME1) $(NAME2) $(NAME3)

# First Target
1 : $(NAME1)
$(NAME1) :
	make -C $(DIR1)

# Second Target
2 : $(NAME2)
$(NAME2) :
	make -C $(DIR2)

# Third Target
3 : $(NAME3)
$(NAME3) :
	make -C $(DIR3)

# Run Target
run :
	$(RUN1)
	$(RUN2)
	$(RUN3)

# Run choose Target
run1 :
	$(RUN1)
run2 :
	$(RUN2)
run3 :
	$(RUN3)

# Clean target
clean:
	rm -f $(NAME1) $(NAME2) $(NAME3)

# Clean and remove target
fclean: clean

# Rebuild target
re: fclean all

.PHONY: all 1 2 3 fclean clean re run run1 run2 run3
