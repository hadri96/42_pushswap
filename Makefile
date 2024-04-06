NAME		=	pushswap
LIBFT		=	libft/
LIBFT_A		=	$(addprefix $(LIBFT), libft.a)

CC			=	gcc
INCLUDE 	=	includes
CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDE) -g
RM			=	rm -f
SRCS		=	srcs/display.c \
				srcs/operations_a.c \
				srcs/operations_b.c \
				srcs/processing.c \
				srcs/stack_info.c \
				srcs/stack_operations.c \
				srcs/stack_utils.c \
				srcs/atos.c \
				srcs/optimal.c \
				srcs/move.c \
				srcs/max.c \
				srcs/pushswap.c

OBJS		=	$(SRCS:%.c=%.o)

all:			$(NAME)

$(NAME):		$(OBJS) $(LIBFT_A)
				@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -lm -o $(NAME)
				@echo "Linked into executable \033[0;32mpushswap\033[0m."

$(LIBFT_A):
				@$(MAKE) bonus -s -C $(LIBFT)
				@echo "Compiled $(LIBFT_A)."

bonus:			all

.c.o:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
				@echo "Compiling $<."

localclean:
				@$(RM) $(OBJS)
				@echo "Removed object files."

clean:			localclean
				@$(MAKE) clean -s -C $(LIBFT)
				@echo "Clean libft."

fclean:			localclean
				@$(MAKE) fclean -s -C $(LIBFT)
				@echo "Full clean libft."
				@$(RM) $(NAME)
				@echo "Removed executable."

re:				fclean all

.PHONY:			all clean fclean re localclean bonus
