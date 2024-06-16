SRC = main.c \
	stack_logic.c \
	lst_logic.c \
	map_indexes.c \
	push_swap_operations.c \
	sort_subset.c \
	sorting_utils.c \
	sorting.c \
	split_median.c \
	parse.c \
	queue.c \
	queue_utils.c \
	split.c


CC = cc
CFLAGS = -Wall -Wextra -Werror -Wno-unused-variable
OUTPUT = hi

# export ARG=" ... " to set a default input for make run
# or specify ARGS on the command line, like in the subject
ARGS = ${ARG}
ifeq ($(ARGS),) 
	ARGS = 5 4 3 2 1
endif

OUTPUT_EXEC = push_swap

all:
	cc $(CFLAGS) $(SRC) -g -o $(OUTPUT_EXEC)

run: $(OUTPUT_EXEC)
	./push_swap $(ARGS) | tee operations ; wc -l operations && printf "input:\n$(ARGS)" >> operations

debug: $(OUTPUT_EXEC)
	gdb -q --args $(OUTPUT_EXEC) $(ARGS)

re: fclean all	


fclean:
	-rm $(OUTPUT_EXEC)

.PHONY: clean fclean
