NAME	=	so_long

SRCS	=	ft_enemy.c	ft_errors.c	ft_map_validation.c\
			ft_moves.c	ft_parsing.c	ft_put_images.c\
			ft_render.c	ft_start.c	so_long.c

HEADER	=	so_long.h

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

LIBFT	=	-L lib -lft

INC		=	-I includes -I lib -I mlx

CFLAGS	=	-Wall -Wextra -Werror -I $(HEADER) -Imlx

MLIBX	=	-Lmlx -lmlx -framework Opengl	-framework AppKit

.PHONE	:	all clean fclean re

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(INC) $(LIBFT) $(MLIBX) $(OBJS) -o $(NAME)

%.o		:	%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean	:
	@rm -f $(OBJS)
	@echo "Cleaned"

fclean	:
	@$(RM) $(NAME)
	@echo "fcleaned"

re		:	fclean all
	@rm -f $(OBJS)