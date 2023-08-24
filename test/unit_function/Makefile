# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamitsui <kamitsui@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 13:58:25 by kamitsui          #+#    #+#              #
#    Updated: 2023/08/24 15:02:38 by kamitsui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target Directory
DIR1 = 1_handle_operator
DIR2 = 2_traverse
DIR3 = 3_parse
DIR4 = 4_parse_pipe_command
DIR5 = 5_parse_exec
DIR6 = 6_parse_traverse_exec

# Target name
NAME1 = $(DIR1)/a.out
NAME2 = $(DIR2)/a.out
NAME3 = $(DIR3)/a.out
NAME4 = $(DIR4)/a.out
NAME5 = $(DIR5)/a.out
NAME6_1 = $(DIR6)/simple_command
NAME6_2 = $(DIR6)/pipe_command

# Run Target
RUN1 = ./$(NAME1) ; echo "\n\n"
RUN2 = ./$(NAME2) ; echo "\n\n"
RUN3 = ./$(NAME3) ; echo "\n\n"
RUN4 = ./$(NAME4) ; echo "\n\n"
RUN5 = ./$(NAME5) ; echo "\n\n"
RUN6_1 = ./$(NAME6_1) ; echo "\n\n"
RUN6_2 = ./$(NAME6_2) ; echo "\n\n"
RUN6 = $(RUN6_1) ; $(RUN6_2)

# Default target
all : $(NAME1) $(NAME2) $(NAME3) $(NAME4) $(NAME5) $(NAME6_1) $(NAME6_2)

# First Target
1 :
	make -C $(DIR1)
$(NAME1) :
	make -C $(DIR1)

# Second Target
2 :
	make -C $(DIR2)
$(NAME2) :
	make -C $(DIR2)

# Third Target
3 :
	make -C $(DIR3)
$(NAME3) :
	make -C $(DIR3)

# Force Target
4 :
	make -C $(DIR4)
$(NAME4) :
	make -C $(DIR4)

# Fifce Target
5 :
	make -C $(DIR5)
$(NAME5) :
	make -C $(DIR5)

# Six Target
6 :
	make -C $(DIR6)
$(NAME6_1) :
	make -C $(DIR6)
$(NAME6_2) :
	make -C $(DIR6)

# Run Target
run :
	$(RUN1)
	$(RUN2)
	$(RUN3)
	$(RUN4)
	$(RUN5)
	$(RUN6)

# Run choose Target
run1 :
	$(RUN1)
run2 :
	$(RUN2)
run3 :
	$(RUN3)
run4 :
	$(RUN4)
run5 :
	$(RUN5)
run6 :
	$(RUN6)
run6-1 :
	$(RUN6_1)
run6-2 :
	$(RUN6_2)

# Clean target
clean:
	rm -f $(NAME1) $(NAME2) $(NAME3) $(NAME4) $(NAME5) $(NAME6_1) $(NAME6_2)

# Clean and remove target
fclean: clean

# Rebuild target
re: fclean all

.PHONY: all 1 2 3 4 5 6 6-1 6-2 fclean clean re run run1 run2 run3 run4 run5 run6 run6-1 run6-2
