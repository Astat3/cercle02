

NAME    =   pipex


CC      =   gcc
CFLAGS  =   -Wall -Werror -Wextra
RM      =   rm -f
AR      =   ar rcs

SRCS    = 	pipex.c\
			utils.c\
			Libft/libft.a\


OBJS    =   $(SRCS:.c=.o)


$(NAME): $(OBJS)
	@echo "Création de la librairie $(NAME)..."
	$(AR) $(NAME) $(OBJS)
	@echo "Terminé."


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@



.PHONY: all clean fclean re


all: $(NAME)


clean:
	@echo "Suppression des fichiers objets (*.o)..."
	$(RM) $(OBJS)

fclean: clean
	@echo "Suppression de la librairie $(NAME)..."
	$(RM) $(NAME)


re: fclean all