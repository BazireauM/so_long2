NAME	=	so_long

SRCS	=	get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c\
			ft_printf/ft_printf.c\
			ft_printf/choose_%.c\
			ft_printf/choose_d.c\
			ft_printf/choose_c.c\
			ft_printf/choose_p.c\
			ft_printf/choose_s.c\
			ft_printf/choose_type.c\
			ft_printf/choose_u.c\
			ft_printf/choose_x.c\
			ft_printf/choose_xmaj.c\
			ft_printf/ft_itoa_u.c\
			ft_printf/ft_parssing_input.c\
			ft_printf/ft_putnbr_base.c\
			ft_printf/ft_itoa.c\
			ft_printf/ft_putstr_fd.c\
			src/test.c\
			src/test2.c\
			src/test3.c\
			src/parssing.c\
			src/free.c\
			src/init_img.c\
			src/move.c\
			main.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	= -Wall -Werror -Wextra -I include -I minilibx/include
G_FLG	= minilibx/libmlx42.a -lglfw -L "/Users/$(shell echo $(USER))/.brew/opt/glfw/lib/"

rm		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS) minilibx/libmlx42.a
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(G_FLG)

minilibx/libmlx42.a:
	make -C minilibx

clean	:
			$(RM) $(OBJS)
			make clean -C minilibx

fclean	:	clean
			$(RM) $(NAME)
			make fclean -C minilibx

re		:	fclean $(NAME)
