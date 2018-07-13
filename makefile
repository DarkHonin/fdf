GNL:=$(realpath gnl)
LIBFT:=$(realpath libft)
MINILIBX:=$(realpath minilibx)
VECT:=$(realpath vect_ft)
MATRIX:=$(realpath matrix_ft)

LIBS:= "$(GNL)" "$(LIBFT)" "$(MINILIBX)" "$(VECT)" "$(MATRIX)"

INCLUDE:=$(addprefix -I, $(LIBS))
LIB_INCLUDE:=$(addprefix -L, $(LIBS))

FLAGS=-lft -lmlx -lgnl -lvect -lmatrix -framework OpenGL -framework AppKit

make:
	gcc main.c fdf*.c $(INCLUDE) $(LIB_INCLUDE) $(FLAGS) -o fdf.out

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