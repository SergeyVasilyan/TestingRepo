DIR = $(PWD)
MAKE_DIR = $(DIR)/src


all: matrix dlist equation

.PHONY: matrix
matrix:
	@$(MAKE) -C $(MAKE_DIR)/matrix -f makefile_matrix

.PHONY: dlist
dlist:
	@$(MAKE) -C $(MAKE_DIR)/double_list -f makefile_dlist

.PHONY: equation
equation:
	@$(MAKE) -C $(MAKE_DIR)/equation -f makefile_equation

.PHONY: clean
clean: matrix_clean dlist_clean equation_clean

.PHONY: matrix_clean
matrix_clean:
	@$(MAKE) -C $(MAKE_DIR)/matrix -f makefile_matrix clean

.PHONY: dlist_clean
dlist_clean:
	@$(MAKE) -C $(MAKE_DIR)/double_list -f makefile_dlist clean

.PHONY: equation_clean
equation_clean:
	@$(MAKE) -C $(MAKE_DIR)/equation -f makefile_equation clean
