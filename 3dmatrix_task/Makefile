DIR = $(PWD)
MAKE_DIR = $(DIR)/mkfiles


all: project

.PHONY: project
project:
	@$(MAKE) -C $(MAKE_DIR) -f makefile_project

.PHONY:project_clean
project_clean:
	@$(MAKE) -C $(MAKE_DIR) -f makefile_project clean

