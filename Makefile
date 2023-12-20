CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

SRC_DIR		:= source
OBJ_DIR		:= objects
INC_DIR		:= include

SRCS		:= $(wildcard $(SRC_DIR)/*.c)
OBJS		:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TARGET		:= libftdprintf.a

.PHONY: all clean fclean re

all: $(TARGET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(TARGET): $(OBJS)
	ar rcs $@ $^

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all
