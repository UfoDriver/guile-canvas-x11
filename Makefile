IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) `guile-config2.2 compile`

ODIR=obj
LDIR =../lib

LIBS=-lm `guile-config2.2 link` -lX11

_DEPS = #.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = guile-canvas.o pointlist.o canvas.o guilefunc.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

guile-canvas: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
