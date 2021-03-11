DIR = $(PWD)
MAKE_DIR = $(DIR)/mkfiles


all: matrix

.PHONY: matrix
matrix:
	@$(MAKE) -C $(MAKE_DIR) -f makefile_matrix

.PHONY:matrix_clean
matrix_clean:
	@$(MAKE) -C $(MAKE_DIR) -f makefile_matrix clean

