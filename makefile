LIB_CFG=dep/libs.mk
NAME=fdf.bin
LIBDIR=$(realpath dep)
OS_D=$(WORKING_DIR)/$(shell uname)
include dep/gen.mk
export NAME

make: $(OBJS)
		make $(shell uname)_OS

MINGW32_NT-6.2_OS:
		gcc $(OBJS) $(INCLUDE) $(LIBPATHS) $(LINKS) -o $(NAME) -lmingw32 -lSDL2main -lSDL2
Darwin_OS:
		gcc $(OBJS) $(INCLUDE) $(LIBPATHS) $(LINKS) -o $(NAME)  -framework opengl -framework appkit -lmlx
