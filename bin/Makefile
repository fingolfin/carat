CC = gcc
CFLAGS = -fwritable-strings -DDIAG1 -pg
TOPDIR = /usb/carat

# LIB = -L$(TOPDIR)/lib -lcarat -lm
LIB = -L$(TOPDIR)/lib -lpresentation -lfunctions -lgmp -lm_alloc -lm
SRC = $(TOPDIR)/src
INCL = $(TOPDIR)/include
OBJ = $(TOPDIR)/obj

GLOBAL = -DTOPDIR=\"$(TOPDIR)\" -DTABLES=\"$(TOPDIR)/tables/\" \
         -DATOMS=\"$(TOPDIR)/tables/atoms/\" \
         -DTABLEDIM=\"$(TOPDIR)/tables/dim\"

COMP = $(CC) $(CFLAGS) $(GLOBAL) -I$(INCL)

ALL: DIR

#
#   PROGRAMS
#

PROGRAMS: Add Aut_grp Bravais_equiv\
          Bravais_grp Bravais_inclusions\
          Con Conjugated Conj_bravais\
          Conv Datei\
          Elt Extract Extensions\
          First_perfect Form_space Form_elt\
          Formtovec Full Fundamental_domain Gauss\
          Idem Inv Invar_space Isometry Is_finite\
          Kron Long_solve Ltm\
          Modp Mtl Mul Mink_red Minpol\
          Name Normalizer Normalizer_in_N Normlin\
          Orbit Order\
          Pair_red Pdet Perfect_neighbours Poincare Polyeder P_lse_solve\
          Presentation Q_catalog QtoZ Red_gen Rest_short\
          Rein Rform Reverse_name\
          Same_generators Scalarmul Scpr Short\
          Shortest Short_reduce Signature\
          Simplify_mat Symbol\
          Torsionfree Tr Trace Trbifo Tr_bravais\
          Vor_vertices Vectoform ZZprog Zass_main Z_equiv


DIR: ./Makefile ./config.guess
	if [ ! -d `./config.guess`-$(CC) ] ; then \
	   mkdir `./config.guess`-$(CC) ; \
	fi
	cp Makefile `./config.guess`-$(CC)
	cd `./config.guess`-$(CC) ;\
         make TOPDIR="$(TOPDIR)" CC="$(CC)" CFLAGS="$(CFLAGS)" PROGRAMS

#-------------------------------------------------------------

Add:  $(SRC)/add.c
	$(COMP) -o Add\
        $(SRC)/add.c  $(LIB)

Aut_grp:  $(SRC)/autgrp.c
	$(COMP) -o Aut_grp\
        $(SRC)/autgrp.c  $(LIB)

Bravais_equiv:  $(SRC)/bravais_equiv.c
	$(COMP) -o Bravais_equiv\
        $(SRC)/bravais_equiv.c  $(LIB)

Bravais_grp:  $(SRC)/bravaisgroup.c
	$(COMP) -o Bravais_grp\
        $(SRC)/bravaisgroup.c  $(LIB)

Bravais_inclusions:  $(SRC)/bravaisgroup.c
	$(COMP) -o Bravais_inclusions\
        $(SRC)/bravais_inclusions.c  $(LIB)

Con:  $(SRC)/con.c
	$(COMP) -o Con\
        $(SRC)/con.c  $(LIB)

Conjugated:  $(SRC)/conjugated.c
	$(COMP) -o Conjugated\
        $(SRC)/conjugated.c  $(LIB)

Conj_bravais:  $(SRC)/conj_bravais.c
	$(COMP) -o Conj_bravais\
        $(SRC)/conj_bravais.c  $(LIB)

Conv:  $(SRC)/conv.c
	$(COMP) -o Conv\
        $(SRC)/conv.c  $(LIB)

Datei:  $(SRC)/datei.c
	$(COMP) -o Datei\
        $(SRC)/datei.c  $(LIB)
	rm -f Bravais_catalog
	ln -f -s Datei Bravais_catalog

Elt:  $(SRC)/elt.c
	$(COMP) -o Elt\
        $(SRC)/elt.c  $(LIB)

Extract:  $(SRC)/extract.c
	$(COMP) -o Extract\
        $(SRC)/extract.c  $(LIB)
	rm -f Standard_affine_form
	ln -f -s Extract Standard_affine_form

Extensions:  $(SRC)/extensions.c
	$(COMP) -o Extensions\
        $(SRC)/extensions.c  $(LIB)
	rm -f Vector_systems
	ln -f -s Extensions Vector_systems

First_perfect:  $(SRC)/first_perfect.c
	$(COMP) -o First_perfect\
        $(SRC)/first_perfect.c  $(LIB)

Form_space:  $(SRC)/form_space.c
	$(COMP) -o Form_space\
        $(SRC)/form_space.c  $(LIB)

Form_elt: $(SRC)/form_elt.c
	$(COMP) -o Form_elt\
        $(SRC)/form_elt.c  $(LIB)

Formtovec:  $(SRC)/formtovec.c
	$(COMP) -o Formtovec\
        $(SRC)/formtovec.c  $(LIB)

Full:  $(SRC)/full.c
	$(COMP) -o Full\
        $(SRC)/full.c  $(LIB)

Fundamental_domain:  $(SRC)/fundamental_domain.c
	$(COMP) -o Fundamental_domain\
        $(SRC)/fundamental_domain.c  $(LIB)

Gauss:  $(SRC)/gauss.c
	$(COMP) -o Gauss\
        $(SRC)/gauss.c  $(LIB)

#Gittstab:  $(SRC)/gittstab.c
#	$(COMP) -o Gittstab\
#        $(SRC)/gittstab.c  $(LIB)

#Hypisom:  $(SRC)/hypisom.c
#	$(COMP) -o Hypisom\
#        $(SRC)/hypisom.c  $(LIB)
#
#Hypstab:  $(SRC)/hypstab.c
#	$(COMP) -o Hypstab\
#        $(SRC)/hypstab.c  $(LIB)

Idem:  $(SRC)/idem.c
	$(COMP) -o Idem\
        $(SRC)/idem.c  $(LIB)

Inv:  $(SRC)/inv.c
	$(COMP) -o Inv\
        $(SRC)/inv.c  $(LIB)

Invar_space:  $(SRC)/invar_space.c
	$(COMP) -o Invar_space\
        $(SRC)/invar_space.c  $(LIB)

Isometry:  $(SRC)/isometry.c
	$(COMP) -o Isometry\
        $(SRC)/isometry.c  $(LIB)

Is_finite:  $(SRC)/is_finite.c
	$(COMP) -o Is_finite\
        $(SRC)/is_finite.c  $(LIB)

Kron:  $(SRC)/kron.c
	$(COMP) -o Kron\
        $(SRC)/kron.c  $(LIB)

Long_solve:  $(SRC)/long_solve.c
	$(COMP) -o Long_solve\
        $(SRC)/long_solve.c  $(LIB)

Ltm:  $(SRC)/ltm.c
	$(COMP) -o Ltm\
        $(SRC)/ltm.c  $(LIB)

Modp:  $(SRC)/modp.c
	$(COMP) -o Modp\
        $(SRC)/modp.c  $(LIB)

Mtl:  $(SRC)/mtl.c
	$(COMP) -o Mtl\
        $(SRC)/mtl.c  $(LIB)

Mink_red:  $(SRC)/mink_red.c
	$(COMP) -o Mink_red\
        $(SRC)/mink_red.c  $(LIB)

Minpol:  $(SRC)/minpol.c
	$(COMP) -o Minpol\
        $(SRC)/minpol.c  $(LIB)

Mul:  $(SRC)/mul.c
	$(COMP) -o Mul\
        $(SRC)/mul.c  $(LIB)

Name:  $(SRC)/name.c
	$(COMP) -o Name\
        $(SRC)/name.c  $(LIB)

Normalizer:  $(SRC)/normalizer.c
	$(COMP) -o Normalizer\
        $(SRC)/normalizer.c  $(LIB)

Normalizer_in_N:  $(SRC)/normalizer_in_n.c
	$(COMP) -o Normalizer_in_N\
        $(SRC)/normalizer_in_n.c  $(LIB)

Normlin:  $(SRC)/normlin.c
	$(COMP) -o Normlin\
        $(SRC)/normlin.c  $(LIB)

Orbit:  $(SRC)/orbit.c
	$(COMP) -o Orbit\
        $(SRC)/orbit.c  $(LIB)

#Orbit_representatives:  $(SRC)/orbit_representatives.c
#	$(COMP) -o Orbit_representatives\
#        $(SRC)/orbit_representatives.c  $(LIB)

#Orbrep:  $(SRC)/orbrep.c
#	$(COMP) -o Orbrep\
#        $(SRC)/orbrep.c  $(LIB)

Order:  $(SRC)/order.c
	$(COMP) -o Order\
        $(SRC)/order.c  $(LIB)

Pair_red:  $(SRC)/pair_red.c
	$(COMP) -o Pair_red\
        $(SRC)/pair_red.c  $(LIB)

Pdet:  $(SRC)/pdet.c
	$(COMP) -o Pdet\
        $(SRC)/pdet.c  $(LIB)

Perfect_neighbours:  $(SRC)/perfect_neighbours.c
	$(COMP) -o Perfect_neighbours\
        $(SRC)/perfect_neighbours.c  $(LIB)

Poincare:  $(SRC)/poincare.c
	$(COMP) -o Poincare\
        $(SRC)/poincare.c  $(LIB)

Polyeder:  $(SRC)/polyeder.c
	$(COMP) -o Polyeder\
        $(SRC)/polyeder.c  $(LIB)

P_lse_solve:  $(SRC)/p_lse_solve.c
	$(COMP) -o P_lse_solve\
        $(SRC)/p_lse_solve.c  $(LIB)

Q_catalog:  $(SRC)/Q_catalog.c
	$(COMP) -o Q_catalog\
        $(SRC)/Q_catalog.c  $(LIB)

QtoZ:  $(SRC)/qtoz.c
	$(COMP) -o QtoZ\
        $(SRC)/qtoz.c  $(LIB)

Presentation:  $(SRC)/presentation.c
	$(COMP) -o Presentation\
        $(SRC)/presentation.c $(LIB)

Red_gen:  $(SRC)/red_gen.c
	$(COMP) -o Red_gen\
        $(SRC)/red_gen.c  $(LIB)

Rein:  $(SRC)/rein.c
	$(COMP) -o Rein\
        $(SRC)/rein.c  $(LIB)

Rest_short:  $(SRC)/rest_short.c
	$(COMP) -o Rest_short\
        $(SRC)/rest_short.c  $(LIB)

Rform:  $(SRC)/rform.c
	$(COMP) -o Rform\
        $(SRC)/rform.c  $(LIB)

Reverse_name:  $(SRC)/reverse_name.c
	$(COMP) -o Reverse_name\
        $(SRC)/reverse_name.c  $(LIB)

Same_generators:  $(SRC)/same_generators.c
	$(COMP) -o Same_generators\
        $(SRC)/same_generators.c  $(LIB)

Scalarmul:  $(SRC)/scalarmul.c
	$(COMP) -o Scalarmul\
        $(SRC)/scalarmul.c  $(LIB)

Scpr:  $(SRC)/scpr.c
	$(COMP) -o Scpr\
        $(SRC)/scpr.c  $(LIB)

Short:  $(SRC)/short.c
	$(COMP) -o Short\
        $(SRC)/short.c  $(LIB)

Shortest:  $(SRC)/shortest.c
	$(COMP) -o Shortest\
        $(SRC)/shortest.c  $(LIB)

Short_reduce:  $(SRC)/short_reduce.c
	$(COMP) -o Short_reduce\
        $(SRC)/short_reduce.c  $(LIB)

Signature:  $(SRC)/signature.c
	$(COMP) -o Signature\
        $(SRC)/signature.c  $(LIB)

Simplify_mat:  $(SRC)/simplify_mat.c
	$(COMP) -o Simplify_mat\
        $(SRC)/simplify_mat.c  $(LIB)

#Solve:  $(SRC)/solve.c
#	$(COMP) -o Solve\
#        $(SRC)/solve.c  $(LIB)

Symbol:  $(SRC)/symbol.c
	$(COMP) -o Symbol\
        $(SRC)/symbol.c  $(LIB)
	rm -f Bravais_type
	ln -f -s Symbol Bravais_type

Torsionfree:  $(SRC)/torsionfree.c
	$(COMP) -o Torsionfree\
        $(SRC)/torsionfree.c  $(LIB)

Tr:  $(SRC)/tr.c
	$(COMP) -o Tr\
        $(SRC)/tr.c  $(LIB)

Trace:  $(SRC)/trace.c
	$(COMP) -o Trace\
        $(SRC)/trace.c  $(LIB)

Trbifo:  $(SRC)/trbifo.c
	$(COMP) -o Trbifo\
        $(SRC)/trbifo.c  $(LIB)

Tr_bravais:  $(SRC)/tr_bravais.c
	$(COMP) -o Tr_bravais\
        $(SRC)/tr_bravais.c  $(LIB)

Vor_vertices:  $(SRC)/vor_vertices.c
	$(COMP) -o Vor_vertices\
        $(SRC)/vor_vertices.c  $(LIB)

Vectoform:  $(SRC)/vectoform.c
	$(COMP) -o Vectoform\
        $(SRC)/vectoform.c  $(LIB)

ZZprog:  $(SRC)/ZZprog.c
	$(COMP) -o ZZprog\
        $(SRC)/ZZprog.c  $(LIB)
	rm -f Sublattices
	ln -f -s ZZprog Sublattices

Zass_main:  $(SRC)/zass_main.c
	$(COMP) -o Zass_main\
        $(SRC)/zass_main.c  $(LIB)

Z_equiv:  $(SRC)/z_equiv.c
	$(COMP) -o Z_equiv\
        $(SRC)/z_equiv.c  $(LIB)

test:  $(SRC)/test.c
	$(COMP) -o test\
        $(SRC)/test.c  $(LIB)

minset:  $(SRC)/minset.c
	$(COMP) -o minset\
        $(SRC)/minset.c  $(LIB)

min_in:  $(SRC)/min_in.c
	$(COMP) -o min_in\
        $(SRC)/min_in.c  $(LIB)

clean:
	rm -f Add
	rm -f Aut_grp
	rm -f Bravais_flok
	rm -f Bravais_catalog
	rm -f Bravais_inclusions
	rm -f Con
	rm -f Conv
	rm -f Datei
	rm -f Dsylv
	rm -f Elt
	rm -f First_perfect
	rm -f Form_elt
	rm -f Form_space
	rm -f Formtovec
	rm -f Full
	rm -f Fundamental_domain
	rm -f Gauss
	rm -f Gittstab
	rm -f Hypisom
	rm -f Hypstab
	rm -f Idem
	rm -f Inv
	rm -f Invar_space
	rm -f Isometry
	rm -f Is_finite
	rm -f Conj_bravais
	rm -f Kron
	rm -f Long_solve
	rm -f Ltm
	rm -f Malloc_liste
	rm -f Mink_red
	rm -f Modp
	rm -f Mtl
	rm -f Mul
	rm -f Normalizer
	rm -f Normalizer_in_N
	rm -f Normlin
	rm -f Orbit
	rm -f Orbit_representatives
	rm -f Orbrep
	rm -f Order
	rm -f P_lse_solve
	rm -f Pair_red
	rm -f Pdet
	rm -f Perfect_neighbours
	rm -f Polyeder
	rm -f Poincare
	rm -f Rein
	rm -f Reverse_name
	rm -f Rest_short
	rm -f Rform
	rm -f Same_generators
	rm -f Scalarmul
	rm -f Scpr
	rm -f Short
	rm -f Short_reduce
	rm -f Shortest
	rm -f Signature
	rm -f Simplify_mat
	rm -f Solve
	rm -f Symbol ; rm -f Bravais_type
	rm -f Torsionfree
	rm -f Tr
	rm -f Tr_bravais
	rm -f Trace
	rm -f Trbifo
	rm -f Vor_vertices
	rm -f ZZprog ; rm -f Sublattices
	rm -f Zass
	rm -f Zass_main
	rm -f Bravais_flok
	rm -f Extensions ; rm -f Vector_systems
	rm -f Extract ; rm -f Standard_affine_form
	rm -f Name
	rm -f Minpol
	rm -f Red_gen
	rm -f Conjugated
	rm -f Order
	rm -f Malloc_liste
	rm -f Presentation
	rm -f Q_catalog
	rm -f QtoZ
	rm -f Z_equiv
	rm -f Bravais_equiv
	rm -f Bravais_grp
	rm -f Vectoform
	rm -f Malloc_liste
	rm -f core

strip:
	strip *

