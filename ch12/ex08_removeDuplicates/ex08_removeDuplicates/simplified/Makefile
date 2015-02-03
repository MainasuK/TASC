# Makefile for cslib/simplified directory
# Last modified on Sat Oct  1 11:59:01 1994 by eroberts
#****************************************************************

OBJECTS = \
    genlib.o \
    strlib.o \
    simpio.o \
    random.o \
    graphics.o

CSLIB = cslib.a

CC = gcc
CFLAGS = -g -I. $(CCFLAGS)

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(CSLIB)

# ***************************************************************
# Standard entries to remove files from the directories
#    tidy    -- eliminate unwanted files
#    clean   -- delete derived files in preparation for rebuild
#    scratch -- synonym for clean

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy

# ***************************************************************
# C compilations

genlib.o: genlib.c genlib.h
	$(CC) $(CFLAGS) -c genlib.c

strlib.o: strlib.c strlib.h genlib.h
	$(CC) $(CFLAGS) -c strlib.c

simpio.o: simpio.c simpio.h strlib.h genlib.h
	$(CC) $(CFLAGS) -c simpio.c

graphics.o: graphics.c graphics.h genlib.h
	$(CC) $(CFLAGS) -c graphics.c

random.o: random.c random.h genlib.h
	$(CC) $(CFLAGS) -c random.c

# ***************************************************************
# Entry to reconstruct the library archive

$(CSLIB): $(OBJECTS)
	-rm -f $(CSLIB)
	ar cr $(CSLIB) $(OBJECTS)
	ranlib $(CSLIB)
