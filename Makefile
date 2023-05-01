SRC = push_swap.c \
		sort_items.c \
		push_swap_list_utils.c \
		moves.c \
		check_input.c \
		radix_sort.c

OBJSRC = $(SRC:.c=.o)

EXC_NAME = push_swap

LIBFT = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
RESET = \x1b[0m
YELLOW = \x1b[33;01m

all: $(EXC_NAME)
$(EXC_NAME) : $(LIBFT) $(OBJSRC)
	@cc $(CFLAGS) $(SRC) $(LIBFT) -o $(EXC_NAME)
	@printf "$(YELLOW)and executable name push_swap is ready.\n $(RESET)"

$(LIBFT) :
	@make -C libft
	@printf "$(YELLOW)libft made\n $(RESET)"

%.o: %.c 
	@cc -Iinclude -Ilibft/libft.a $(CFLAGS) -c $^ -o $@

clean :
	@rm -f $(OBJSRC)
	@make clean -C libft

fclean : clean
	@rm -f $(EXC_NAME)
	@make fclean -C libft

re : fclean all

mem:
	memdetect $(SRC) $(LIBFT) $(CFLAGS) $(1)

.PHONY : all clean fclean