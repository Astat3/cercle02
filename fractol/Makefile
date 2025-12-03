# ============================================================================ #
#                                   VARIABLES                                  #
# ============================================================================ #

NAME		=	fractol

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -O3

# 1. LIBFT CONFIGURATION
LIBFT_PATH	=	Libft
LIBFT		=	$(LIBFT_PATH)/libft.a

# Détection de l'OS
UNAME_S		:=	$(shell uname -s)

# ============================================================================ #
#                              CONFIGURATION OS                                #
# ============================================================================ #

ifeq ($(UNAME_S), Linux)
	MLX_PATH	=	minilibx-linux
	MLX_NAME	=	libmlx.a
	MLX_FLAGS	=	-L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz
else
	MLX_PATH	=	mlx
	MLX_NAME	=	libmlx.a
	MLX_FLAGS	=	-L$(MLX_PATH) -lmlx -framework OpenGL -framework AppKit
endif

MLX			=	$(MLX_PATH)/$(MLX_NAME)

# 2. INCLUDES (Add Libft path)
INCLUDES	=	-I ./includes -I $(MLX_PATH) -I $(LIBFT_PATH)

# ============================================================================ #
#                                   SOURCES                                    #
# ============================================================================ #

SRCS		=	main.c \
				# Add other files here

OBJS		=	$(SRCS:.c=.o)

# ============================================================================ #
#                                    RÈGLES                                    #
# ============================================================================ #

all: $(MLX) $(LIBFT) $(NAME)

# 3. COMPILE LIBFT
$(LIBFT):
	@echo "Compiling Libft..."
	@make -sC $(LIBFT_PATH)

# Compile MLX
$(MLX):
	@echo "Compiling MiniLibX..."
	@make -sC $(MLX_PATH)

# Compile Objects
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# 4. LINK EVERYTHING (Add Libft flags)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "✅ $(NAME) built successfully!"

clean:
	@make -sC $(MLX_PATH) clean
	@make -sC $(LIBFT_PATH) clean
	@rm -f $(OBJS)
	@echo "🧹 Objects cleaned."

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@echo "🗑️  Executables removed."

re: fclean all

.PHONY: all clean fclean re