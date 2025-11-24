NAME    =   pipex

CC      =   gcc
CFLAGS  =   -Wall -Werror -Wextra
# On ajoute -ILibft pour que tes .c trouvent "libft.h"
IFLAGS  =   -I./Libft

# --- CONFIGURATION LIBFT ---
LIBFT_DIR = ./Libft
LIBFT_A   = $(LIBFT_DIR)/libft.a
# Flags pour dire au compilateur où trouver la lib (-L) et laquelle utiliser (-lft)
LFLAGS    = -L$(LIBFT_DIR) -lft

RM      =   rm -f

# NE METS QUE TES FICHIERS .C ICI (pas de .a)
SRCS    =   pipex.c \
            utils.c	\
			pipex_utils_others.c\

OBJS    =   $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

# Règle pour compiler la libft d'abord
$(LIBFT_A):
	@echo "Compilation de la Libft..."
	make -C $(LIBFT_DIR)

# Règle principale : Création de l'exécutable pipex
# On dépend de $(OBJS) ET de $(LIBFT_A)
$(NAME): $(OBJS) $(LIBFT_A)
	@echo "Compilation de l'exécutable $(NAME)..."
	# C'est ICI que la magie opère : on compile les objets avec la libft
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	@echo "Terminé."

# Règle pour transformer tes .c en .o
%.o: %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	@echo "Suppression des fichiers objets..."
	$(RM) $(OBJS)
	# On nettoie aussi dans la libft
	make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Suppression de $(NAME)..."
	$(RM) $(NAME)
	# On fclean aussi la libft
	make -C $(LIBFT_DIR) fclean

re: fclean all