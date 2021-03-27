# SUBDIRS = $(shell find .. -type d | grep -Ev "(.git|.vscode)")
# IFLAGS = $(addprefix -I, $(SUBDIRS))
LIBFT_DIR = libft
CFLAGS = -Wall -Wextra # -Werror
CHK_SRCDIR = src_checker
LFLAGS = -L$(LIBFT_DIR) -lft
IFLAGS = -I$(LIBFT_DIR) -I$(CHK_SRCDIR)
CHK_SRCS = $(addprefix $(CHK_SRCDIR)/, args_to_list.c errors.c free.c repeating_numbers.c)
CHK_SRCS += $(addprefix $(CHK_SRCDIR)/operations/, parse_operation.c push.c rotate.c rotate_reverse.c swap.c)
CHK_OBJS = $(CHK_SRCS:%.c=%.o)

all:	libft checker

%.o:	%.c
	gcc -c -o $@ $< $(CFLAGS) $(IFLAGS)

checker:	$(CHK_OBJS)
	gcc -o $@ $^ $(LFLAGS)

libft:
	make -C $(LIBFT_DIR) bonus

_%:	_%.c $(CHK_OBJS) libft
	gcc $< $(SRCS) -o $@ $(CHK_OBJS) $(IFLAGS) $(LFLAGS)

srcs:
	echo -n $(CHK_SRCS) > srcs_list.txt

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(CHK_OBJS)

fclean:	clean
	make -C $(LIBFT_DIR) fclean
	rm -f checker

re:	fclean all

.PHONY:	all libft clean fclean re
