WORKING_DIR:=$(realpath .)

LIBFT=		/goinfre/wgourley/LIBFT
GNL=		/c/Users/Honin/Documents/Code/C/Wolf3D/dep/gnl
MATRIXFT=	/c/Users/Honin/Documents/Code/C/Wolf3D/dep/matrix
VECTFT=		/c/Users/Honin/Documents/Code/C/Wolf3D/dep/vect_ft
3DFT=		/c/Users/Honin/Documents/Code/C/Wolf3D/dep/3dft

LIBRAIRIES= $(LIBFT) $(GNL) $(MATRIXFT) $(VECTFT) $(3DFT)
ARCHIVES=$(LIBFT)/libft.a $(GNL)/libgnl.a $(MATRIXFT)/libmatrix.a $(VECTFT)/libvect.a $(3DFT)/lib3dft.a
LINKS=-lgnl -lvect -l3dft -lmatrix -lft
INCLUDE=$(addprefix -I,$(addsuffix /includes, $(LIBRAIRIES)))