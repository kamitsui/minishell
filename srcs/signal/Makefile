RL_DIR = $(shell brew --prefix readline)
RL_LIB_DIR = $(addprefix $(RL_DIR), /lib)
RL_INC_DIR = $(addprefix $(RL_DIR), /include)

signal:
	cc -g3 -O0 -fsanitize=address \
	signal.c \
	../../libft/libft.a \
	-I../../libft \
	-I../../includes \
	-lreadline \
	-L$(RL_LIB_DIR) \
	-I$(RL_INC_DIR) \
	-o sig