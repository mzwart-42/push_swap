SRC = main.c \
	stack_logic.c \
	map_indexes.c \
	push_swap_operations.c \
	sort_subset.c \
	sorting_utils.c \
	sorting.c \
	queue.c


CC = cc
#CFLAGS = -Wall -Wextra -Werror
OUTPUT = hi

ARG = ${arg}
ifeq ($(ARG),) # if arg is empty
	ARG = 670 5593 4305 3569 1116 9828 1506 8616 34 324 234 2424 123 12 1
endif

OUTPUT_EXEC = a.out

all:
	cc $(CFLAGS) $(SRC) -g -o $(OUTPUT_EXEC)
	./$(OUTPUT_EXEC) $(ARG)


fclean:
	rm $(OUTPUT_EXEC)
