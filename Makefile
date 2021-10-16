CC				= 	gcc
CFLAGS			= 	-Wall -Wextra -Werror
NAME			= 	push_swap	
INCLUDES		= 	includes
SRCS_PATH		= 	./srcs/
BONUS_PATH		= 	./srcs_bonus/
LIBFT_PATH		= 	./libft/
SRCS_FILES    	= 	$(SRCS_PATH)main.c $(SRCS_PATH)dlst_utils.c $(SRCS_PATH)dlst_utils2.c $(SRCS_PATH)dlst_utils3.c $(SRCS_PATH)operations.c $(SRCS_PATH)operations2.c $(SRCS_PATH)operations3.c
BONUS_FILES    	= 	$(BONUS_PATH)main_bonus.c 
SRCS_OBJS		= 	$(SRCS_FILES:.c=.o)
BONUS_OBJS		= 	$(BONUS_FILES:.c=.o)

ifdef BONUS
SRCS_OBJS        	= 	$(BONUS_OBJS)
endif

LIBFTMAKE		= 	$(MAKE) -C $(LIBFT_PATH)
LIBFTFLAG		= 	-L$(LIBFT_PATH) -lft

all:			$(NAME)

$(NAME):		$(SRCS_OBJS)
				$(LIBFTMAKE)
				$(CC) $(CFLAGS) $(SRCS_OBJS) $(LIBFTFLAG) -o $(NAME)

lib:
				$(LIBFTMAKE)

.c.o:
				$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

clean:
				$(LIBFTMAKE) clean
				$(RM) $(SRCS_OBJS) $(BONUS_OBJS)

fclean:			clean
				$(LIBFTMAKE) fclean
				$(RM) $(NAME) $(SRCS_PATH)$(SRCS_OBJS) $(BONUS_PATH)$(BONUS_OBJS)

re:				fclean all

bonus:			
				make BONUS=1

.PHONY:			all clean fclean bonus lib mlx re