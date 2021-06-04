NAME =		push_swap
NAME_DB =	push_swap_db
CFLAGS =	-Wall -Wextra #-Werror
LIBFT_DIR =	libft
LIBFT =		$(LIBFT_DIR)/libft.a
LFLAGS =	-L$(LIBFT_DIR) -lft
IFLAGS =	-I$(LIBFT_DIR) -Iinclude
DBFLAGS =	-g3 -fsanitize=address
OBJ_DIRS =	obj/ $(addprefix obj/, common pswap_recursion get_next_line operations pswap_recursion/operations dequeue checker)
SRCS_COM =$(addprefix src/get_next_line/, get_next_line_utils.c get_next_line.c)
SRCS_COM +=$(addprefix src/operations/, rotate_reverse.c push.c rotate.c \
		parse_operation.c swap.c)
SRCS_COM +=$(addprefix src/common/, handle_args.c is_sorted_lst.c \
		lstrev_array.c args_to_stacks.c repeating_numbers.c \
		utils.c replace_with_indexes.c exit_fun.c)
SRCS_COM +=$(addprefix src/dequeue/, add.c create.c remove.c sort.c print.c)
SRCS_PS = $(addprefix src/pswap_recursion/, pswap.c push_half_in_a.c push_half_in_b.c utils.c main.c push_half.c)
SRCS_PS +=$(addprefix src/pswap_recursion/operations/, push.c rotate.c rotate_reverse.c swap.c)
SRCS_PS += src/_trace.c
# SRCS_PS += src/pswap_recursion/main.c
OBJS_COM =$(SRCS_COM:src/%.c=obj/%.o)
OBJS_PS =		$(OBJS_COM) $(SRCS_PS:src/%.c=obj/%.o)
OBJS_COM_DB =	$(SRCS_COM:src/%.c=obj/%.o_db)
OBJS_PS_DB =	$(OBJS_COM_DB) $(SRCS_PS:src/%.c=obj/%.o_db)
SRCS_CHK = $(addprefix src/checker/, checker.c check_ok.c read_execute.c)
OBJS_CHK =	$(OBJS_COM) $(SRCS_CHK:src/%.c=obj/%.o)

all:	$(NAME)
db:		$(NAME_DB)
# $(OBJS_CHK): $(LIBFT)

checker: $(OBJS_CHK)
	gcc -o $@ $^ $(LFLAGS) $(IFLAGS)

$(NAME): $(OBJS_PS)
	gcc -o $@ $(OBJS_PS) $(LFLAGS)
$(NAME_DB): $(OBJS_PS_DB)
	gcc -o $@ $(OBJS_PS_DB) $(LFLAGS) -g3 -fsanitize=address
$(NAME):	libft
$(NAME_DB):	libft

libft:
	make -C $(LIBFT_DIR)

_%:	test/_%.c $(OBJS_PS) libft
	gcc $< -o test/$@ $(OBJS_PS) $(IFLAGS) $(LFLAGS)
_%_db:	test/_%.c $(OBJS_PS_DB) libft
	gcc $< -o test/$@ $(OBJS_PS_DB) $(IFLAGS) $(LFLAGS) $(DBFLAGS)

# _test_chk_%:	test/_test_chk_%.c $(OBJS_CHK)
# 	gcc $< $(SRCS) -o test/$@ $(OBJS_CHK) $(IFLAGS) $(LFLAGS)

# _test_ps_%:	test/_test_ps_%.c $(OBJ_DIRS) $(OBJS_PS)
# 	gcc $< $(SRCS) -o test/$@ $(OBJS_PS) $(IFLAGS) $(LFLAGS) $(DBFLAGS)

$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

$(OBJS_COM) :	| $(OBJ_DIRS)
$(OBJS_PS) :	| $(OBJ_DIRS)
$(OBJS_COM_DB) :	| $(OBJ_DIRS)
$(OBJS_PS_DB) :		| $(OBJ_DIRS)

obj/%.o:	src/%.c
	gcc -c -o $@ $< $(CFLAGS) $(IFLAGS)
obj/%.o_db:	src/%.c
	gcc -c -o $@ $< $(CFLAGS) $(IFLAGS) -g3 -fsanitize=address

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf obj/

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re libft
