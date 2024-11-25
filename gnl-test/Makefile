GNL_PATH := ../

GNL_M_SRCS := get_next_line.c get_next_line_utils.c
GNL_M_PATH := $(addprefix $(GNL_PATH), $(GNL_M_SRCS))

GNL_B_SRCS := get_next_line.c get_next_line_utils.c
GNL_B_PATH := $(addprefix $(GNL_PATH), $(GNL_B_SRCS))

TEST_M_SRCS := main_m.c
TEST_B_SRCS := main_b.c

GNL_M_OBJ := $(GNL_M_PATH:.c=.o)
GNL_B_OBJ := $(GNL_B_PATH:.c=.o)

TEST_M_OBJ := $(TEST_M_SRCS:.c=.o)
TEST_B_OBJ := $(TEST_B_SRCS:.c=.o)

HDR := colors.h

CC := cc
CFLAGS += -Wall -Wextra -Werror -I$(GNL_PATH)

RED = \033[0;31m
GREEN = \033[0;32m
ENDCOLOR = \033[0m

NAME := test
NAME_BONUS := test_bonus

BUFFER_SIZE ?= 42

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

$(NAME): $(GNL_M_OBJ) $(TEST_M_OBJ)
	$(CC) $(CFLAGS) $(GNL_M_OBJ) $(TEST_M_OBJ) -o $@
	@rm -f $(GNL_M_OBJ) $(GNL_B_OBJ)

$(NAME_BONUS): $(GNL_B_OBJ) $(TEST_B_OBJ)
	$(CC) $(CFLAGS) $(GNL_B_OBJ) $(TEST_B_OBJ) -o $@

m: $(NAME)
mandatory: $(NAME)

b: $(NAME_BONUS)
bonus: $(NAME_BONUS)

clean:
	@rm -f $(GNL_M_OBJ) $(GNL_B_OBJ) $(TEST_M_OBJ) $(TEST_B_OBJ)
	@echo "$(RED)✅ GNL: Clean complete.$(ENDCOLOR)"

fclean:
	@rm -f $(GNL_M_OBJ) $(GNL_B_OBJ) $(TEST_M_OBJ) $(TEST_B_OBJ) $(NAME) $(NAME_BONUS)
	@echo "$(RED)✅ GNL: FClean complete.$(ENDCOLOR)"

re: fclean all

.PHONY: clean fclean re all
