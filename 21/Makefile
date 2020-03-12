CFLAGS = -O3 -Wall -g -fopenmp
COMPILER := clang 
LINK := -g -fopenmp
INCLUDE_OPTIONS := -I./inc
TARGET := 21

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc





INCLUDES := $(shell find $(INC_DIR) -type d | sed s/^/-I/) $(INCLUDE_OPTIONS) 
SRC := $(shell find $(SRC_DIR) -name '*.c')
INC := $(shell find $(INC_DIR) -name '*.h')
.PHONY: all database directories clean depend
all: depend directories $(TARGET)
.NOTPARALLEL: depend
OBJ := $(subst $(SRC_DIR),$(OBJ_DIR),$(patsubst %.c,%.o,$(SRC)))
OBJDIRS := $(sort $(dir $(OBJ)))
SRCDIRS := $(sort $(dir $(SRC)))
$(TARGET):	$(OBJ) 
	$(COMPILER) -o $@ $(OBJ) $(LINK)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | depend; $(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@ 
database: ;make clean; bear make
directories:; mkdir -p $(OBJDIRS)
clean: ; rm -f $(TARGET) $(OBJ) 
depend: ; gcc-makedepend $(addprefix -p ,$(OBJDIRS)) $(CFLAGS) $(INCLUDES) $(SRC)
format:; uncrustify --no-backup -c /home/freyja/.defaults/uncrustify.cfg $(SRC) $(INC)
# DO NOT DELETE
obj/int_root.o: src/int_root.c inc/int_root.h
obj/amicable.o: src/amicable.c inc/amicable.h inc/int_root.h
obj/main.o: src/main.c inc/amicable.h
