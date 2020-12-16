MAKE_DIR = $(PWD)

SRC1_DIR := $(MAKE_DIR)/src1
SRC2_DIR := $(MAKE_DIR)/src2
SRC3_DIR := $(MAKE_DIR)/src3
SRC4_DIR := $(MAKE_DIR)/src4
SRC5_DIR := $(MAKE_DIR)/src5

INC_SRCH_PATH :=
INC_SRCH_PATH += -I$(SRC1_DIR)
INC_SRCH_PATH += -I$(SRC2_DIR)
INC_SRCH_PATH += -I$(SRC3_DIR)
INC_SRCH_PATH += -I$(SRC4_DIR)
INC_SRCH_PATH += -I$(SRC5_DIR)

all:
	@$(MAKE) -C src1 -f makefile
	@$(MAKE) -C src2 -f makefile
	@$(MAKE) -C src3 -f makefile
	@$(MAKE) -C src4 -f makefile
	@$(MAKE) -C src5 -f makefile

.PHONY: clean
clean:
	@$(MAKE) -C src1 -f makefile clean
	@$(MAKE) -C src2 -f makefile clean
	@$(MAKE) -C src3 -f makefile clean
	@$(MAKE) -C src4 -f makefile clean
	@$(MAKE) -C src5 -f makefile clean

