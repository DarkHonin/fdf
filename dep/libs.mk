WORKING_DIR:=$(realpath .)

LIBFT=		/goinfre/wgourley/fdf/dep/LIBFT
GNL=		/goinfre/wgourley/fdf/dep/GNL_PlanB
MATRIXFT=	/goinfre/wgourley/fdf/dep/matrix_ft
VECTFT=		/goinfre/wgourley/fdf/dep/vect_ft
3DFT=		/goinfre/wgourley/fdf/dep/3dft

LIBRAIRIES= $(LIBFT) $(GNL) $(MATRIXFT) $(VECTFT) $(3DFT)
ARCHIVES=$(LIBFT)/libft.a $(GNL)/libgnl.a $(MATRIXFT)/libmatrix.a $(VECTFT)/libvect.a $(3DFT)/lib3dft.a
LINKS=-lgnl -lvect -l3dft -lmatrix -lft
INCLUDE=$(addprefix -I,$(addsuffix /includes, $(LIBRAIRIES)))
