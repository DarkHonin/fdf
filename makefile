GNL=gnl
INCLUDE=libft
MINILIBX=minilibx/
MNXL=$(MINILIBX)/libmlx.a
FTLIB=$(INCLUDE)/libft.a

FLAGS=-lft -lmlx -framework OpenGL -framework AppKit

test: $(FTLIB) $(MNXL)
	gcc *.c $(GNL)/*.c -I $(INCLUDE) -I $(MINILIBX) -L $(INCLUDE) -L $(MINILIBX) -I $(GNL)/ $(FLAGS)

$(FTLIB):
	make -C $(INCLUDE)

$(MNXL):
	make -C $(MINILIBX)

retest:
	$(MAKE) fclean
	$(MAKE) test
	

fclean:
	make fclean -C $(INCLUDE)