NAME=fdf.bin
LIB_CFG=dep/libs.mk
include dep/gen.mk
export NAME

make: $(OBJS)
	gcc -o $(NAME) $(OBJS) $(INCLUDE) $(addprefix -L,$(LIBRAIRIES)) -I$(INCLUDE_DIR) $(LINKS) -lmlx -framework OpenGl -framework AppKit