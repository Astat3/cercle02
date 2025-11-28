# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adamgallot <adamgallot@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 19:36:10 by adamgallot        #+#    #+#              #
#    Updated: 2025/11/27 19:36:11 by adamgallot       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.

# Ici, on liste explicitement chaque fichier avec son chemin complet
# C'est "moche et long", mais ça marche à tous les coups.

SRCS        = push_swap.c \
			  srcs/command/push.c \
			  srcs/command/reverse_rotate.c \
			  srcs/command/rotate.c \
			  srcs/command/swap.c \
			  srcs/libft_utils/ft_long_atoi.c \
			  srcs/libft_utils/ft_split.c \
			  srcs/libft_utils/putstrfd.c \
			  srcs/sorting/og_sorting.c \
			  srcs/sorting/sort_for_three.c \
			  srcs/stack/create_stack.c \
			  srcs/stack/from_a_to_b.c \
			  srcs/stack/from_b_to_a.c \
			  srcs/stack/get_info_a.c \
			  srcs/stack/get_info_b.c \
			  srcs/stack/node_working.c \
			  srcs/stack/stack_utils.c

# Cette ligne transforme automatiquement la liste des .c en .o
OBJS        = $(SRCS:.c=.o)

# --- Règles ---

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Règle pour compiler chaque fichier .c en .o
# $< représente le fichier source (.c)
# $@ représente le fichier cible (.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re