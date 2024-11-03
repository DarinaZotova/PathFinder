COMPILER = clang
COMPILER_FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic 
AR = ar

DIR_SRC = src
DIR_OBJ = obj
DIR_INC = inc

INCLUDE_FILES = $(DIR_INC)/libmx.h
LIBRARY_NAME = libmx.a

SOURCE_FILES = $(wildcard $(DIR_SRC)/*.c)
OBJECT_FILES = $(patsubst $(DIR_SRC)/%.c, $(DIR_OBJ)/%.o, $(SOURCE_FILES))

.PHONY: all clean uninstall reinstall create_dirs

all: create_dirs $(LIBRARY_NAME)

$(LIBRARY_NAME): $(OBJECT_FILES)
	$(AR) rcs $@ $^

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(INCLUDE_FILES)
	$(COMPILER) $(COMPILER_FLAGS) -I$(DIR_INC) -c $< -o $@

create_dirs:
	@mkdir -p $(DIR_OBJ)

clean:
	@rm -rf $(DIR_OBJ) $(LIBRARY_NAME)

uninstall: clean
	@rm -f $(LIBRARY_NAME)

reinstall: uninstall all
