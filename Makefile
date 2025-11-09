
NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = so_long.c \
		utils.c \
		get_next_line.c \
		map/map_read.c \
		map/map_check.c \
		map/is_accessible.c \

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = Libft/Libft
PRINTF_DIR = Libft/Printf
MLX_DIR = minilibx-linux

LIBFT_A = $(LIBFT_DIR)/libft.a
PRINTF_A = $(PRINTF_DIR)/libftprintf.a
MLX_A = $(MLX_DIR)/libmlx_Linux.a

LIBS = $(LIBFT_A) $(PRINTF_A) $(MLX_A)
MLX_FLAGS = -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(PRINTF_A) $(MLX_A)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_A):
	@$(MAKE) -C $(PRINTF_DIR)

$(MLX_A):
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(PRINTF_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re