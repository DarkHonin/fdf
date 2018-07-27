include $(LIB_CFG)

SRC_DIR=$(WORKING_DIR)/srcs
OBJ_DIR=$(WORKING_DIR)/objs
INCLUDE_DIR=$(WORKING_DIR)/includes

SRCS=$(shell find $(SRC_DIR) -type f)
OBJS:=$(foreach obj,$(notdir $(SRCS)),$(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(obj))))

$(NAME): $(LIB_CFG)
	@echo "Current_path: $(WORKING_DIR)"
	@echo "Object path: $(OBJ_DIR)"
	@echo "Config path: $(LIB_CFG)"
	@echo -e "\e[32wWorking directory: \e[0: $(WORKING_DIR)"
	@for i in $(INCLUDE); do \
		echo "Librairy found: $$i"; \
	done
	@echo "Making $(NAME)"
	@for i in $(SRCS); do \
		echo "Discovered: $$i"; \
	done
	
	$(MAKE) make

$(OBJS): $(OBJ_DIR)
	@echo "Creating: $@"
	@gcc $(shell find $(SRC_DIR) -type f -name $(notdir $*)) -o $@ $(INCLUDE) -I $(INCLUDE_DIR) -c -Wextra -Wall -Werror

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

clean: $(OBJ_DIR)
	rm -r $(OBJ_DIR)

fclean: clean
	rm $(NAME)

re: fclean $(NAME)