HEADERS=$(shell cat headers)
LIBRAIRIES=$(shell cat librairies)

LIBFT=$(realpath libft)
GNL=$(realpath gnl)
MATRIX=$(realpath matrix_ft)
VECT=$(realpath vect_ft)

MODS="$(LIBFT)" "$(GNL)" "$(MATRIX)" "$(VECT)"

LIB_DIR="../lib"
INCLUDE_DIR=$(LIB_DIR)/includes

build:
	@for i in $(MODS); do \
		echo "Building librairy: $$i";\
		make -C $$i $(CMD) LIBFT=$(LIBFT);\
	done

	$(MAKE) cp_headers
	$(MAKE) cp_libs

cp_headers: $(INCLUDE_DIR)
	@for i in $(HEADERS); do \
		echo "Copying header: $$i"; \
		cp $$i $(INCLUDE_DIR); \
	done

cp_libs: $(LIB_DIR)
	@for i in $(LIBRAIRIES); do \
		echo "Copying header: $$i"; \
		cp $$i $(LIB_DIR); \
	done

$(LIB_DIR):
	mkdir -p $(LIB_DIR)

$(INCLUDE_DIR): $(LIB_DIR)
	mkdir -p $(INCLUDE_DIR)

re:
	rm -rf $(LIB_DIR)
	$(MAKE) build CMD=re