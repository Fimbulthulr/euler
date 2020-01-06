#SRC := main.c ns_differential.c integrator.c rk_classic.c lagrange_interpolation.c
CFLAGS = -O3 -Wall
COMPILER = clang 
LINK := 
INCLUDE_OPTIONS := 
TARGETS := euler

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc






INCLUDES := $(shell find $(INC_DIR) -type d | sed s/^/-I/) $(INCLUDE_OPTIONS) 
SRC := $(shell find $(SRC_DIR) -name '*.c')
.PHONY:
all: depend directories $(TARGETS)
OBJ := $(subst $(SRC_DIR),$(OBJ_DIR),$(patsubst %.c,%.o,$(SRC)))
OBJDIRS := $(sort $(dir $(OBJ)))
SRCDIRS := $(sort $(dir $(SRC)))
$(TARGETS):	$(OBJ) 
	$(COMPILER) -o $@ $(OBJ) $(LINK)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c; $(COMPILER) $(CFLAGS) $(INCLUDES) -c $< -o $@
.PHONY:
database: ;make clean; bear make
directories:; mkdir -p $(OBJDIRS)
clean: ; rm -f $(TARGETS) $(OBJ) 
depend: ; ../gcc-makedepend $(addprefix -p ,$(OBJDIRS)) $(CFLAGS) $(INCLUDES) $(SRC)
# DO NOT DELETE
obj/floorSqrt.o: src/floorSqrt.c inc/floorSqrt.h
obj/main.o: src/main.c inc/67.h inc/floorSqrt.h
