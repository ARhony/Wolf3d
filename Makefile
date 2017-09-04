# Makefile by Anthony

NAME 	= wolf3d

SRC 	= main.c \
		  init.c \
		  input.c \
		  calcul.c \
		  draw.c \
		  player.c \
		  image.c \
		  map.c \
		  minimap.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -Ofast

LIBFT 	= ./libft/libft.a
LIBINC 	= -I./libft
LIBLINK = -L./libft -lft

MLX		= ./minilibx/libmlx.a
MLXINC	= -I./minilibx
MLXLINK = -L./minilibx -lmlx -framework OpenGL -framework AppKit

INCDIR	= ./include/
SRCDIR	= ./src/
OBJDIR	= ./obj/

all: obj $(LIBFT) $(MLX) $(NAME)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) $(MLXINC) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MLXLINK) $(LIBLINK)

$(LIBFT):
	make -C ./libft

$(MLX):
	make -C ./minilibx

obj:
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)
	make -C ./libft clean
	make -C ./minilibx clean

fclean: clean
	rm -rf $(NAME)

re: fclean all
