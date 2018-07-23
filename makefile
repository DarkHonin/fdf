NAME=fdf
LIBS=-L lib -L /goinfre/wgourley/.brew/Cellar/sdl2/2.0.8/lib
INCLUDE=-I lib/includes

L= -lft -lmlx -lgnl -lmatrix -lvect -framework OpenGl -framework AppKit

FILES:=$(basename $(shell find src -type f))
OBJ:=$(foreach obj,$(notdir $(FILES)),$(addprefix obj/,$(addsuffix .o,$(obj))))

GC=gcc

make: $(OBJ)
	$(GC) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBS) $(L)

$(OBJ):
	mkdir -p obj
	$(GC) $(shell find src -type f -name $(notdir $*).c) -o obj/$(notdir $*).o $(INCLUDE) -c 

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

rebuild: clean
	make -C dep CMD=re
	$(MAKE) re

re: clean make