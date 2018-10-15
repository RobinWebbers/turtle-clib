.PHONY: clean

PDIR = $(shell basename "$$PWD")

IDIR = inc
SDIR = src
ODIR = obj

CC = gcc
CFLAGS = -I$(IDIR) -Wall -pedantic-errors 

INC := $(wildcard $(IDIR)/*.h)
SRC := $(wildcard $(SDIR)/*.c)
OBJ := $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))

$(ODIR)/%.o: $(SDIR)/%.c | $(ODIR)
	$(CC) -MMD $(CFLAGS) -fPIC -c -o $@ $<

lib$(PDIR).so: $(OBJ)
	$(CC) -o $@ $^ -shared $(CFLAGS)

$(ODIR):
	mkdir -p $@

clean:
	-rm -f $(ODIR)/*.o *~ core.* $(IDIR)/*~
	-rm -f $(ODIR)/*.d
	-rm -f lib*.so
