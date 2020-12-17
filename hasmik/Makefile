DIR = $(PWD)
MAKE_DIR = $(DIR)/makefiles

INC_SRCH_PATH += -I$(MAKE_DIR)/makefile_grade
INC_SRCH_PATH += -I$(MAKE_DIR)/makefile_gcd_rec
INC_SRCH_PATH += -I$(MAKE_DIR)/makefile_reserve_integer


all:
	@$(MAKE) -C $(MAKE_DIR) -f makefile_grade
	@$(MAKE) -C $(MAKE_DIR) -f makefile_gcd_rec
	@$(MAKE) -C $(MAKE_DIR) -f makefile_reserve_integer


.PHONY: clean
clean:
	@$(MAKE) -C $(MAKE_DIR) -f makefile_grade
	@$(MAKE) -C $(MAKE_DIR) -f makefile_gcd_rec
	@$(MAKE) -C $(MAKE_DIR) -f makefile_reserve_integer


