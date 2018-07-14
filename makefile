GNL:=$(realpath gnl)
LIBFT:=$(realpath libft)
MINILIBX:=$(realpath minilibx)
VECT:=$(realpath vect_ft)
MATRIX:=$(realpath matrix_ft)

LIBS:= "$(GNL)" "$(LIBFT)" "$(MINILIBX)" "$(VECT)" "$(MATRIX)"

INCLUDE:=$(addprefix -I, $(LIBS))
LIB_INCLUDE:=$(addprefix -L, $(LIBS))

FLAGS=-lft -lmlx -lgnl -lvect -lmatrix -framework OpenGL -framework AppKit

SRC=main.c fdf_draw.c fdf_point3.c fdf_reader.c fdf_render.c fdf_utils.c fdf_window.c

make:
	gcc $(SRC) $(INCLUDE) $(LIB_INCLUDE) $(FLAGS) -o fdf.out

build:
	@for i in $(LIBS); do \
		echo "Making $$i";	\
		make -C $$i $(CMD) LIBFT='$(LIBFT)'; \
	done

re: fclean make

retest:
	$(MAKE) fclean
	$(MAKE) test
	

fclean:
	make -C $(INCLUDE)