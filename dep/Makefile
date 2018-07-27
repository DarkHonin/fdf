
include libs.mk  ../project.mk

prep:
	@for i in $(INCLUDE); do \
		echo $$i; \
	done
	@$(MAKE) make

make: $(ARCHIVES)

$(ARCHIVES):
	@make -C $(dir $@) 

fclean:
	@echo -n "Cleaning"
	@for i in $(LIBRAIRIES); do \
		make -C $$i fclean -s;\
		echo -n "."; \
	done
	@echo Done

re:
	@echo -n "Cleaning"
	@for i in $(LIBRAIRIES); do \
		make -C $$i fclean ;\
		echo -n "."; \
	done
	@echo Done
	@$(MAKE) make