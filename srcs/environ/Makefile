env:
	cc -g3 -O0 -fsanitize=address \
	environ.c \
	env_lstiter_funcs.c \
	ft_unset.c \
	ft_env.c \
	ft_export.c \
	env_utils.c \
	ft_pwd.c \
	ft_cd.c \
	-I../../libft ../../libft/libft.a \
	-I../../includes \
	-I../../ft_printf/includes \
	../../ft_printf/libftprintf.a \
	-o env

leak:
	cc -g3 -O0 \
	environ.c \
	env_lstiter_funcs.c \
	ft_unset.c \
	ft_env.c \
	ft_export.c \
	env_utils.c \
	ft_pwd.c \
	ft_cd.c \
	-I../../libft ../../libft/libft.a \
	-I../../includes \
	-I../../ft_printf/includes \
	../../ft_printf/libftprintf.a \
	-o env
.PHONY: env leak