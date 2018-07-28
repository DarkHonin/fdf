NAME=fdf.bin
LIB_CFG=dep/libs.mk
include dep/gen.mk
export NAME

make: $(OBJS)
	make -C dep
	gcc -o $(NAME) $(OBJS) $(INCLUDE) $(addprefix -L,$(LIBRAIRIES)) -I$(INCLUDE_DIR) -lmingw32 -mwindows $(LINKS)

rebuild:
	make -C dep/$(LIB) fclean
	make -C dep