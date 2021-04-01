# SUBDIRS = $(shell find .. -type d | grep -Ev "(.git|.vscode)")
# IFLAGS = $(addprefix -I, $(SUBDIRS))
LIBFT_DIR = src/libft
CFLAGS = -Wall -Wextra # -Werror
CHK_SRCDIR = src/checker
PS_SRCDIR = src/pswap
LFLAGS = -L$(LIBFT_DIR) -lft
IFLAGS = -I$(LIBFT_DIR) -I$(CHK_SRCDIR) -I$(PS_SRCDIR)
# SRCS =  $(addprefix src/checker/, checker.c operations/_test_ops.c \
# 		operations/parse_operation.coperations/push.c operations/rotate.c \
# 		operations/rotate_reverse.coperations/swap.c) 
# SRCS += $(addprefix src/common/, args_to_list.c errors.c free.c \
# 		repeating_numbers.c)
# SRCS += $(addprefix src/get_next_line/, get_next_line.c get_next_line_bonus.c \
# 		get_next_line_utils.cget_next_line_utils_bonus.c) 
# SRCS += $(addprefix src/pswap/, mapping.c orbit.c orbit_str.c) 
SRCS_CHK =	$(addprefix src/checker/, checker.c operations/_test_ops.c \
		operations/parse_operation.c operations/push.c operations/rotate.c \
		operations/rotate_reverse.c operations/swap.c)
SRCS_CHK +=	$(addprefix src/common/, args_to_list.c errors.c free.c \
		repeating_numbers.c)
SRCS_CHK +=	$(addprefix src/get_next_line/, get_next_line.c get_next_line_utils.c)
SRCS_PS =	$(addprefix src/common/, args_to_list.c errors.c free.c \
		repeating_numbers.c)
SRCS_PS +=	$(addprefix src/get_next_line/, get_next_line.c get_next_line_utils.c)
SRCS_PS +=	$(addprefix src/pswap/, mapping.c orbit.c orbit_str.c)
OBJS_CHK =	$(SRCS_CHK:%.c=%.o)
OBJS_PS =	$(SRCS_PS:%.c=%.o)

all:	libft checker

%.o:	%.c
	gcc -c -o $@ $< $(CFLAGS) $(IFLAGS)

checker:	$(OBJS_CHK)
	gcc -o $@ $^ $(LFLAGS)

push_swap:	$(OBJS_PS)
	gcc -o $@ $^ $(LFLAGS)

libft:
	make -C $(LIBFT_DIR) bonus

_test_chk_%:	_test_chk_%.c $(OBJS_CHK) libft
	gcc $< $(SRCS) -o $@ $(OBJS_CHK) $(IFLAGS) $(LFLAGS)

_test_ps_%:	_test_ps_%.c $(OBJS_PS) libft
	gcc $< $(SRCS) -o $@ $(OBJS_PS) $(IFLAGS) $(LFLAGS)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJS_CHK)
	rm -f $(OBJS_PS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	rm -f checker

re:	fclean all

.PHONY:	all libft clean fclean re
