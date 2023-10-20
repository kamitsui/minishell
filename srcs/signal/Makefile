LIB_RL = libreadline.dylib
RL_DYLIB_PATH = $(shell find /opt/homebrew -name $(LIB_RL) 2>/dev/null)
RL_LIB_DIR = $(dir $(RL_DYLIB_PATH))
RL_INC_DIR = $(subst /lib/,/include,$(RL_LIB_DIR))

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
