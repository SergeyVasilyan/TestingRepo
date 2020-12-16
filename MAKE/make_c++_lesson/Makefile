MAKE_DIR = $(PWD)

SRC_DIR := $(MAKE_DIR)/src

INC_SRCH_PATH :=
INC_SRCH_PATH += -I$(MAKE_DIR)/mkfiles


all:
	@$(MAKE) -C src -f makefile_scole
	@$(MAKE) -C src -f makefile_sum
	@$(MAKE) -C src -f makefile_sum_of_digits
	@$(MAKE) -C src -f makefile_inverse
	@$(MAKE) -C src -f makefile_draw_regtangle

.PHONY: clean
clean:
	@$(MAKE) -C src1 -f makefile_scole clean
	@$(MAKE) -C src2 -f makefile_sum clean
	@$(MAKE) -C src3 -f makefile_sum_of_digits clean
	@$(MAKE) -C src4 -f makefile_inverse clean
	@$(MAKE) -C src5 -f makefile_draw_regtangle clean

