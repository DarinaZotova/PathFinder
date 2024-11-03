NAME = pathfinder

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic 

#директории
SRC_DIR	= src
INC_DIR	= inc
OBJ_DIR	= obj

INC_FILES = $(wildcard $(INC_DIR)/*.h)
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC_FILES:%.c=%.o)))

LBMX_DIR = libmx
LBMX_A := $(LBMX_DIR)/libmx.a
LBMX_INC := $(LBMX_DIR)/inc

all: $(LBMX_A) $(NAME)

$(NAME): $(OBJ_FILES)
	@clang $(FLAGS) $(OBJ_FILES) -L$(LBMX_DIR) -lmx -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_FILES)
	@clang $(FLAGS) -c $< -o $@ -I$(INC_DIR) -I$(LBMX_INC)

$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $@

$(LBMX_A):
	@make -sC $(LBMX_DIR)
	
clean:
	@rm -rf $(OBJ_DIR)
	@make clean -sC $(LBMX_DIR)

uninstall:
	@make -sC $(LBMX_DIR) $@
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)

reinstall: uninstall all
