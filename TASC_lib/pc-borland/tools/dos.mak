
#
# Borland C++ IDE generated makefile
#
.AUTODEPEND


#
# Borland C++ tools
#
IMPLIB  = Implib
BCCDOS  = Bcc +BccDos.cfg -DBCPATH="$(BCPATH:\=\\)"
TLINK   = TLink
TLIB    = TLib
TASM    = Tasm
#
# IDE macros
#


#
# Options
#
IDE_LFLAGSDOS =  -L$(BCPATH)\LIB
IDE_BFLAGS = 
LLATDOS_cslibdlib =  -c -Tde
RLATDOS_cslibdlib = 
BLATDOS_cslibdlib = 
LEAT_cslibdlib = $(LLATDOS_cslibdlib)
REAT_cslibdlib = $(RLATDOS_cslibdlib)
BEAT_cslibdlib = $(BLATDOS_cslibdlib)

#
# Dependency List
#
Dep_cslib = \
   cslib.lib

cslib : BccDos.cfg $(Dep_cslib)
  echo MakeNode cslib

Dep_cslibdlib = \
   genlib.obj \
   simpio.obj \
   strlib.obj \
   exceptio.obj \
   graphics.obj \
   random.obj

Lib_list = \
   +genlib.obj \
   +simpio.obj \
   +strlib.obj \  
   +exceptio.obj \
   +graphics.obj \
   +random.obj

cslib.lib : $(Dep_cslibdlib)
  if exist $< del $<
  $(TLIB) $< $(IDE_BFLAGS) $(BEAT_cslibdlib) $(Lib_list)

genlib.obj :  genlib.c
  $(BCCDOS) -P- -c $(CEAT_cslibdlib) -o$@ genlib.c

simpio.obj :  simpio.c
  $(BCCDOS) -P- -c $(CEAT_cslibdlib) -o$@ simpio.c

strlib.obj :  strlib.c
  $(BCCDOS) -P- -c $(CEAT_cslibdlib) -o$@ strlib.c

exceptio.obj :  exceptio.c
  $(BCCDOS) -P- -c $(CEAT_cslibdlib) -o$@ exceptio.c

graphics.obj :  graphics.c
  $(BCCDOS) -P- -c $(CEAT_cslibdlib) -o$@ graphics.c

random.obj :  random.c
  $(BCCDOS) -P- -c $(CEAT_cslibdlib) -o$@ random.c

# Compiler configuration file
BccDos.cfg : 
   Copy &&|
-W-
-R
-v
-vi
-X-
-H
-I$(BCPATH)\INCLUDE
-H=cslib.csm
-ml
-f-
| $@
