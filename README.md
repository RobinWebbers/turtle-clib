# Turtle C Library

Hi there fellow c programmer,

To make my (and hopefully your) life easier, I've made some c libraries. Use
them as you please. If you find any bugs or things I could improve on, I'd be
glad to hear.

## Usage

Use the Makefile in the root directory of this repository to compile the
libraries:
- To make a specific library, set the target to the corresponding directory.
- To set the target of the Makefiles of the libraries, set "ARGS" (e.g. to clean
  all libraries: make ARGS=clean)

## Fork

To make life easier when you want to contribute to the code, you can copy the
generic makefile in each of the library directories.

## Libraries

All libraries have header files with function definitions. Consult these if you
want to learn which functions there are and what their effects are.

### Data

The data library has all kinds of generic datastructures for you to use.
Datastructures postfixed with a "d", e.g. "Stackd" and "Queued" are dynamic
structures. Their respective static datastructure is postfixed with a "s", e.g.
"Stacks" and "Queues".

### Pack

Currently, pack only has functions to set integer data into a char array. This
library will probably be added to some other library a future update.

## Future plans
- Add hashtable to data library
- Add binary search tree to data library
- Add matrix to data library
