LIBS := $(subst /,,$(shell ls -d */))

.PHONY: all clean $(LIBS) 

all: $(LIBS)

clean: ARGS := clean
clean: $(LIBS)

$(LIBS):
	$(MAKE) -C $@ $(ARGS)
