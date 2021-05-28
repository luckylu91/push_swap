NAME =		push_swap
CFLAGS =	-Wall -Wextra # -Werror
LIBFT_DIR =	src/libft
LIBFT =		$(LIBFT_DIR)/libft.a
LFLAGS =	-L$(LIBFT_DIR) -lft
IFLAGS =	-I$(LIBFT_DIR) -Iinclude
DBFLAGS =	-g3 -fsanitize=address
OBJ_DIRS =	obj/ $(addprefix obj/, common pswap_recursion get_next_line operations pswap_recursion/operations)
SRCS_PS = $(addprefix src/pswap_recursion/, pswap.c push_half_in_a.c push_half_in_b.c utils.c main.c)
SRCS_PS +=$(addprefix src/pswap_recursion/operations/, push.c rotate.c rotate_reverse.c swap.c)
# SRCS_CHK =$(addprefix src/checker/, checker.c check_ok.c read_execute.c)
# OBJS_CHK =$(SRCS_CHK:%.c=%.o)
SRCS_COM =$(addprefix src/get_next_line/, get_next_line_utils.c get_next_line.c)
SRCS_COM +=$(addprefix src/operations/, rotate_reverse.c push.c rotate.c \
		parse_operation.c swap.c)
SRCS_COM +=$(addprefix src/common/, errors.c handle_args.c is_sorted_lst.c \
		lstrev_array.c args_to_stacks.c repeating_numbers.c print_stacks.c free.c \
		utils.c)
OBJS_COM =$(SRCS_COM:src/%.c=obj/%.o)
# OBJS_CHK =	$(OBJS_COM) $(SRCS_CHK:%.c=%.o)
OBJS_PS =	$(OBJS_COM) $(SRCS_PS:src/%.c=obj/%.o)

all:	$(NAME)

# $(OBJS_CHK): $(LIBFT)

# checker: $(OBJS_CHK)
# 	gcc -o $@ $^ $(LFLAGS)

$(NAME): $(OBJS_PS)
	gcc -o $@ $^ $(LFLAGS) $(DBFLAGS)

$(NAME): $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)

_test_chk_%:	test/_test_chk_%.c $(OBJS_CHK)
	gcc $< $(SRCS) -o test/$@ $(OBJS_CHK) $(IFLAGS) $(LFLAGS)

_test_ps_%:	test/_test_ps_%.c $(OBJ_DIRS) $(OBJS_PS)
	gcc $< $(SRCS) -o test/$@ $(OBJS_PS) $(IFLAGS) $(LFLAGS) $(DBFLAGS)

$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

obj/%.o:	src/%.c | $(OBJ_DIRS)
	gcc -c -o $@ $< $(CFLAGS) $(IFLAGS)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS_DIRS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	rm -f checker

re:	fclean all

.PHONY:	all libft clean fclean re
