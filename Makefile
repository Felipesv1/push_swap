NAME = push_swap

LIBFT = libft.a

SRC_FILES =  check.c main.c operations_a.c operations_ab.c operations_b.c radix_utils.c radix.c simple.c sort_utils.c utils.c

DIR = src/
SRC = $(addprefix $(DIR), $(SRC_FILES))
OBJ = ${SRC:.c=.o}

CC  = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@ $(CC) $(CFLAGS) $(OBJ) $(INCLUDE) libft/$(LIBFT) -o $(NAME) 
	@echo Compilation Finish

clean: 
	@make clean -C libft
	${RM} ${OBJ}

fclean: clean
	@make fclean -C libft
	${RM} $(NAME)
	${RM} $(LIBFT)

re: fclean all
