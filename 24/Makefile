CFLAGS = -O3 
COMPILER := ldc2
LINK := 
TARGET := 24

SRC_DIR = src
OBJ_DIR = obj



SRC := $(shell find $(SRC_DIR) -name '*.d')
.PHONY: all database directories clean
all: directories $(TARGET)
.NOTPARALLEL: depend
OBJ := $(subst $(SRC_DIR),$(OBJ_DIR),$(patsubst %.d,%.o,$(SRC)))
OBJDIRS := $(sort $(dir $(OBJ)))
SRCDIRS := $(sort $(dir $(SRC)))
$(TARGET):	$(OBJ) 
	$(COMPILER) -of=$@ $(OBJ) $(LINK)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.d; $(COMPILER) $(CFLAGS) -I=$(SRC_DIR) -c $< -od=$(OBJ_DIR) 
database: ;make clean; bear make
directories:; mkdir -p $(OBJDIRS)
clean: ; rm -f $(TARGET) $(OBJ) 
# DO NOT DELETE
obj/main.o: src/main.d src/lexiographic_permutation.d
obj/lexiographic_permutation.o: src/lexiographic_permutation.d
