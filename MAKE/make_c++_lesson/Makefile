DIR = $(PWD)
MAKE_DIR = $(DIR)/mkfiles

INC_SRCH_PATH += -I$(MAKE_DIR)/makefile_score
INC_SRCH_PATH += -I$(MAKE_DIR)/makefile_sum
INC_SRCH_PATH += -I$(MAKE_DIR)/makefile_sum_of_digits
INC_SRCH_PATH += -I$(MAKE_DIR)/makefile_inverse
INC_SRCH_PATH += -I$(MAKE_DIR)/makefile_draw_rectangle
INC_SRCH_PATH += -I$(MAKE_DIR)/makefile_gcd
INC_SRCH_PATH += -I$(MAKE_DIR)/makefile_random


all:
	@$(MAKE) -C $(MAKE_DIR) -f makefile_score
	@$(MAKE) -C $(MAKE_DIR) -f makefile_sum
	@$(MAKE) -C $(MAKE_DIR) -f makefile_sum_of_digits
	@$(MAKE) -C $(MAKE_DIR) -f makefile_inverse
	@$(MAKE) -C $(MAKE_DIR) -f makefile_draw_rectangle
	@$(MAKE) -C $(MAKE_DIR) -f makefile_gcd
	@$(MAKE) -C $(MAKE_DIR) -f makefile_random


.PHONY: clean
clean:
	@$(MAKE) -C $(MAKE_DIR) -f makefile_score clean
	@$(MAKE) -C $(MAKE_DIR) -f makefile_sum clean
	@$(MAKE) -C $(MAKE_DIR) -f makefile_sum_of_digits clean
	@$(MAKE) -C $(MAKE_DIR) -f makefile_inverse clean
	@$(MAKE) -C $(MAKE_DIR) -f makefile_draw_rectangle clean
	@$(MAKE) -C $(MAKE_DIR) -f makefile_gcd clean
	@$(MAKE) -C $(MAKE_DIR) -f makefile_random clean


