# ------------------------------------ COLORS -------------------------------------
RED := $(shell tput -T xterm setaf 1)
GREEN := $(shell tput -T xterm setaf 2)
YELLOW := $(shell tput -T xterm setaf 3)
BLUE := $(shell tput -T xterm setaf 4)
PURPLE := $(shell tput -T xterm setaf 5)
WHITE := $(shell tput -T xterm setaf 7)
GREY := $(shell tput -T xterm setaf 14)
RESET := $(shell tput -T xterm setaf sgr0)
# ------------------------------ configurable -----------------------------------

# -MMD generates makefile dependencies that tell make which source file depend
#  on what headers. These get generated at the same time when the source files are compiled
DEP_FLAGS = -MMD -MP
INCLUDE_PATHS = include
CFLAGS = -Wall -Werror -Wextra
CC = cc

SUB_DIRS := libft
RECURSIVE_MAKE_FLAGS = --no-print-directory
ARCHIVE_FILES := libft.a
STATIC_LIBS := libft/libft.a

# NAME stands for the output file, because subjects require it
NAME = push_swap
BUILD_DIR = ./build

# -------------------------------------------------------------------------------

INCLUDE_FLAGS = $(addprefix -I, $(INCLUDE_PATHS))
CFLAGS += $(INCLUDE_FLAGS)

# vpath only works with automatic variables?
vpath %.c src
SRC_FILES := main.c \
	lst_utils.c \
	stack_utils.c \
	map_indexes.c \
	split_stack.c \
	sorting.c \
	sorting_utils.c \
	sort_subset.c \
	push_swap_operations.c \
	parse.c \
	queue.c \
	queue_utils.c \
	queue_optimizations.c
OBJ_FILES = $(SRC_FILES:%.c=$(BUILD_DIR)/%.o)
DEPS = $(SRC_FILES:%.c=$(BUILD_DIR)/%.d)

# ----------------------------------- Targets --------------------------------------
all: subdirs $(NAME)

subdirs: $(SUB_DIRS)
	@echo $(YELLOW) recursive make calls ... $(BLUE)
	@$(MAKE) $(RECURSIVE_MAKE_FLAGS) -C $^ $(MAKECMDGOALS)
	@echo -n $(RESET)$(WHITE)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(DEP_FLAGS) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES) $(STATIC_LIBS)
	$(CC) $^ -o $@
	@echo $(YELLOW) 'Compiled push_swap  ._.)/\(._.'

clean: subdirs
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all re clean fclean subdirs run


# inpsired by https://8thlight.com/insights/make-developing-easier-by-building-a-beautiful-makefile
## --------------------------------------------------------------------------------
## Everything after double hash sign is printed out when make help is called.
## This can very useful for clean documentation!
## --------------------------------------------------------------------------------

# prints out all of the help documentation (double commented lines) in every makefile that is called
help:
	@sed -ne '/@sed/!s/## //p' $(MAKEFILE_LIST)

run: $(NAME)
ifndef ARGS
	@echo $(RED) make run ARGS='" ... "'
else
	./$(NAME) $(ARGS)
endif

