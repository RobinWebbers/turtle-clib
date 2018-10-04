.PHONY: clean

IDIR = inc
SDIR = src
ODIR = obj

CC = gcc
CFLAGS = -I$(IDIR) -Wall

INC := $(wildcard $(IDIR)/*.h)
SRC := $(wildcard $(SDIR)/*.c)
OBJ := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) -MMD $(CFLAGS) -fPIC -c -o $@ $<

libpack.so: $(OBJ)
	$(CC) -o $@ $^ -shared $(CFLAGS)

clean:
	-rm -f $(ODIR)/*.o *~ core.* $(IDIR)/*~
	-rm -f $(ODIR)/*.d
	-rm -f lib*.so
