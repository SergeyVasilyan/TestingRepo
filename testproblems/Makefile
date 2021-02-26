.PHONY: clean subsystem fibonachi fibonachi_clean multiplication multiplication_clean
MUL_MKF_DIR :=./src/multiplication
FIB_MKF_DIR :=./src/fibonachi

subsystem:
	$(MAKE) -C $(MUL_MKF_DIR)
	$(MAKE) -C $(FIB_MKF_DIR)

fibonachi:
	$(MAKE) -C $(FIB_MKF_DIR)

multiplication:
	$(MAKE) -C $(MUL_MKF_DIR)

clean:
	$(MAKE) -C $(MUL_MKF_DIR) clean
	$(MAKE) -C $(FIB_MKF_DIR) clean

fibonachi_clean:
	$(MAKE) -C $(FIB_MKF_DIR) clean

multiplication_clean:
	$(MAKE) -C $(MUL_MKF_DIR) clean
