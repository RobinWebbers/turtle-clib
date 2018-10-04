LIBS = $(subst /,,$(shell ls -d */))
ARGS =

.PHONY: all $(LIBS)

all: $(LIBS)

$(LIBS):
	$(MAKE) -C $@ $(ARGS)
