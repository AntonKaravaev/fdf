NAME = fdf

FLAGS = -Wall -Wextra -Werror -g

HEADER = -I libft/includes/ -I minilibx_macos/ -I includes/

LIB		= -L libft/ -lft -L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

LIST = main read draw solution tricky_atoi board menu#test

OBJS = $(addprefix objs/, $(addsuffix .o, $(LIST)))

all: $(NAME)

objs/%.o: srcs/%.c includes/fdf.h
		gcc $(FLAGS) -c $< -o $@ $(HEADER)

$(NAME): objs make_lib $(OBJS) libft/libft.a minilibx_macos/libmlx.a
		@gcc -o $(NAME) $(OBJS) $(LIB)
		@echo ✅ FDF compiled!

make_lib:
		@make -C libft
		@make -C minilibx_macos

objs:
		@mkdir objs 2> /dev/null || true

clean:
		@make -C libft/ clean
		@make -C ./minilibx_macos clean
		@rm -rf ./objs/

fclean: clean
		@make -C libft/ fclean
		@make -C ./minilibx_macos fclean
		@rm -f $(NAME)

re: 	fclean all

.PHONY: clean fclean re all