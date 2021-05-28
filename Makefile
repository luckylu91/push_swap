# SUBDIRS = $(shell find .. -type d | grep -Ev "(.git|.vscode)")
# IFLAGS = $(addprefix -I, $(SUBDIRS))
LIBFT_DIR =	src/libft
CFLAGS =	-Wall -Wextra # -Werror
LFLAGS =	-L$(LIBFT_DIR) -lft
IFLAGS =	-I$(LIBFT_DIR) -Iincludes
DBFLAGS =	-g3 -fsanitize=address
# SRCS_PS =$(addprefix src/pswap/, merge.c sort.c)
# SRCS_PS +=$(addprefix src/pswap/utils/, utils.c)
# SRCS_PS +=$(addprefix src/pswap/operations/, rotate_reverse.c push.c rotate.c \
#         swap.c)
SRCS_PS =$(addprefix src/pswap_recursion/, pswap.c push_half_in_a.c push_half_in_b.c utils.c main.c)
SRCS_PS +=$(addprefix src/pswap_recursion/operations/, push.c rotate.c rotate_reverse.c swap.c)
OBJS_PS =$(SRCS_PS:%.c=%.o)
SRCS_CHK =$(addprefix src/checker/, checker.c check_ok.c read_execute.c)
OBJS_CHK =$(SRCS_CHK:%.c=%.o)
SRCS_COM =$(addprefix src/get_next_line/, get_next_line_utils.c get_next_line.c)
SRCS_COM +=$(addprefix src/operations/, rotate_reverse.c push.c rotate.c \
		parse_operation.c swap.c)
SRCS_COM +=$(addprefix src/common/, errors.c handle_args.c is_sorted_lst.c \
		lstrev_array.c args_to_stacks.c repeating_numbers.c print_stacks.c free.c \
		utils.c)
OBJS_COM =$(SRCS_COM:%.c=%.o)
OBJS_CHK =	$(OBJS_COM) $(SRCS_CHK:%.c=%.o)
OBJS_PS =	$(OBJS_COM) $(SRCS_PS:%.c=%.o)

all:	push_swap checker

%.o:	%.c
	gcc -c -o $@ $< $(CFLAGS) $(IFLAGS)

$(OBJS_CHK): libft

checker: $(OBJS_CHK)
	gcc -o $@ $^ $(LFLAGS)

$(OBJS_PS): libft

push_swap: $(OBJS_PS)
	gcc -o $@ $^ $(LFLAGS) $(DBFLAGS)

libft:
	make -C $(LIBFT_DIR) bonus

_test_chk_%:	test/_test_chk_%.c $(OBJS_CHK) libft
	gcc $< $(SRCS) -o test/$@ $(OBJS_CHK) $(IFLAGS) $(LFLAGS)

_test_ps_%:	test/_test_ps_%.c $(OBJS_PS) libft
	gcc $< $(SRCS) -o test/$@ $(OBJS_PS) $(IFLAGS) $(LFLAGS) $(DBFLAGS)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS_CHK)
	rm -f $(OBJS_PS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	rm -f checker

re:	fclean all

.PHONY:	all libft clean fclean re
