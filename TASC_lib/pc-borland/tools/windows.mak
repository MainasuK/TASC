
#
# Borland C++ IDE generated makefile
#
.AUTODEPEND


#
# Borland C++ tools
#
IMPLIB  = Implib
BCC     = Bcc +BccW16.cfg -DBCPATH="$(BCPATH:\=\\)"
TLINK   = TLink
TLIB    = TLib
BRC     = Brc
TASM    = Tasm
#
# IDE macros
#


#
# Options
#
IDE_LFLAGS =  -L$(BCPATH)\LIB
IDE_RFLAGS =  -I$(BCPATH)\INCLUDE
LLATW16_cslibdlib =  -Twe
RLATW16_cslibdlib =  -31
BLATW16_cslibdlib = 
LEAT_cslibdlib = $(LLATW16_cslibdlib)
REAT_cslibdlib = $(RLATW16_cslibdlib)
BEAT_cslibdlib = $(BLATW16_cslibdlib)

#
# Dependency List
#
Dep_cslib = \
   cslib.lib

cslib : BccW16.cfg $(Dep_cslib)
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
  $(BCC)   -P- -c $(CEAT_cslibdlib) -o$@ genlib.c

simpio.obj :  simpio.c
  $(BCC)   -P- -c $(CEAT_cslibdlib) -o$@ simpio.c

strlib.obj :  strlib.c
  $(BCC)   -P- -c $(CEAT_cslibdlib) -o$@ strlib.c

exceptio.obj :  exceptio.c
  $(BCC)   -P- -c $(CEAT_cslibdlib) -o$@ exceptio.c

graphics.obj :  graphics.c
  $(BCC)   -P- -c $(CEAT_cslibdlib) -o$@ graphics.c

random.obj :  random.c
  $(BCC)   -P- -c $(CEAT_cslibdlib) -o$@ random.c

# Compiler configuration file
BccW16.cfg :
	Copy &&|
-R
-v
-vi
-X-
-H
-I$(BCPATH)\INCLUDE
-H=cslib.csm
-ml
-WS
| $@


