NAME  = smalloc

SRC   = smalloc.c s_free.c main.c

OBJ	  = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

RM	  = rm -f

cc 	  = cc

$(NAME) : $(OBJ)
	@$(cc) $(FLAGS) $(OBJ) -o $(NAME)
	@printf "\033[1;32mfiles compiled successfully \033[0m\n"

%.o : %.c smalloc.h
	@$(cc) $(FLAGS) -c $< -o $@

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@printf "\033[1;32mobjects files removed successfully\033[0m\n"

fclean: clean
	@$(RM) $(NAME)

re : fclean $(NAME)
