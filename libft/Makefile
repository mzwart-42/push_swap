# ------------------------------------ COLORS -------------------------------------
RED := $(shell tput -T xterm setaf 1)
GREEN := $(shell tput -T xterm setaf 2)
YELLOW := $(shell tput -T xterm setaf 3)
BLUE := $(shell tput -T xterm setaf 4)
PURPLE := $(shell tput -T xterm setaf 5)
WHITE := $(shell tput -T xterm setaf 15)
RESET := $(shell tput -T xterm setaf sgr0)
# ---------------------------------------------------------------------------------

SRC = \
ft_isalnum.c \
ft_isalpha.c \
ft_isdigit.c \
ft_isprint.c \
ft_strlen.c \
ft_memchr.c \
ft_memmove.c \
ft_memcpy.c \
ft_memset.c \
ft_memcmp.c \
ft_bzero.c \
ft_isascii.c \
ft_strrchr.c \
ft_strchr.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strncmp.c \
ft_strnstr.c \
ft_tolower.c \
ft_toupper.c \
ft_strdup.c \
ft_calloc.c \
ft_atoi.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putnbr_base.c

BONUS_SRC = \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstlast.c \
ft_lstsize.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c

# adding printf to src files and include dir

# in the future create a seperate folder for seperate parts that
# are consistenly structured so you can do recursive make?

PRINTF_FOLDER = ft_printf
PRINTF_SRC = \
char_specifiers.c \
int_specifiers.c \
ft_printf.c

SRC_PRINTF := $(addprefix ./$(PRINTF_FOLDER)/, $(PRINTF_SRC))

SRC += $(SRC_PRINTF)


INCLUDE_DIR = include
HEADER_FILES = ft_printf.h libft.h
HEADERS = $(addprefix ./$(INCLUDE_DIR)/, $(HEADER_FILES))

CC = cc
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = crU

NAME := libft.a
OBJ := $(SRC:.c=.o)
BONUS_OBJ := $(BONUS_SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	$(AR) $(ARFLAGS) $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BONUS_OBJ) $(NAME) $(NAME)($(BONUS_OBJ))

.PHONY:	clean fclean re all bonus
