.PHONY: clean All

All:
	@echo "----------Building project:[ stage_controller - Debug ]----------"
	@cd "stage_controller" && "$(MAKE)" -f  "stage_controller.mk"
clean:
	@echo "----------Cleaning project:[ stage_controller - Debug ]----------"
	@cd "stage_controller" && "$(MAKE)" -f  "stage_controller.mk" clean
