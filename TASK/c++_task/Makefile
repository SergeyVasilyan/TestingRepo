DIR = $(PWD)
MAKE_DIR = $(DIR)/mkfiles


all: mult fib

.PHONY: mult
mult:
	@$(MAKE) -C $(MAKE_DIR) -f makefile_mult

.PHONY: fib
fib:
	@$(MAKE) -C $(MAKE_DIR) -f makefile_fib

.PHONY:fib_clean
fib_clean:
	 @$(MAKE) -C $(MAKE_DIR) -f makefile_fib clean

.PHONY:mult_clean
mult_clean:
	@$(MAKE) -C $(MAKE_DIR) -f makefile_mult clean

