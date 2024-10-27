# ca-util
General utilities used across my projects. This repository contains no stand-alone executables. Instead it is meant to be included as a git module and linked into other projects.

#### Why single function files?
This is due to how compiling and linking work in terms of translation or compilation units. By keeping things in separate files we can guarantee that only the code for the functions used are actually linked into the final binary.

## Library contents
Some of these utility functions replicate functions or capabilities within gnu-libc, but are provided here to be compiler agnostic. 

- utils.h - types, macros, and function declarations for general convenience utilities
  - filename.c : function to return the filename portion of a given path string
  - drop_extension.c: function to remove the extension portion fo a given filename string
  - filesize.c: convenience function to return the size of a given open file.
- memstream.h - types, macros, and function declarations for memory as a stream with stdio like functions
  - memstream_eof.c: function that returns true if the current position is at the end of the given memstream
  - memstream_getc.c / memstream_putc.c: functions for reading and writing a single character/byte to/from the given memstream
  - memstream_read.c / memstream_write.c: functions for reading and writing one or more bytes to/from the given memstream
  - memstream_tell.c / memstream_seek.c: functions for getting and setting the position within the given memstream
