NAME =				server

NAME2 =				client

SRCS_S =			server.c untils.c 
		
OBJ_DIR =			obj

LIB_PATH = 			libft/

SRCS_C =			client.c untils.c
				
HEADER =			minitalk.h

OBJ_S =				$(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(SRCS_S)))

OBJ_C =				$(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(SRCS_C)))

CC =				gcc

FLAGS =				-Wall -Wextra -Werror -I$(HEADER)

.PHONY:				all clean makelibft fclean re

all:				makelibft $(NAME)

makelibft:			
					make -C $(LIB_PATH) all

$(NAME):			$(HEADER) $(OBJ_S) $(OBJ_C)
					$(CC) $(FLAGS) $(OBJ_S) $(LIB_PATH)libft.a -o $(NAME)
					$(CC) $(FLAGS) $(OBJ_C) $(LIB_PATH)libft.a -o $(NAME2)

$(OBJ_DIR)/%.o:		%.c	$(HEADER)
					@mkdir -p $(OBJ_DIR)
					$(CC) $(FLAGS) -c $< -o $@

clean:
					@rm -rf $(OBJ_DIR)
					@make -C $(LIB_PATH) clean

fclean:				clean
					@$(RM) $(NAME) $(NAME2)
					@make -C $(LIB_PATH) fclean

re:					fclean all