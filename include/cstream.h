/*
 * cstream.h 
 * definitions for simple stream handling
 * 
 * This code is offered without warranty under the MIT License. Use it as you will 
 * personally or commercially, just give credit if you do.
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#ifndef CA_CSTREAM
#define CA_CSTREAM

// generalized stream_io, allowing functions to be written to accept stdio streams or custom streams
// generalized function pointers for the stream_io functions
typedef int  (*stream_eof_t)(void *);
typedef int  (*stream_getc_t)(void *);
typedef int  (*stream_putc_t)(int, void *);
typedef int  (*stream_read_t)(void *, size_t, size_t, void *);
typedef int  (*stream_write_t)(void *, size_t, size_t, void *);
typedef int  (*stream_seek_t)(void *, long, int);
typedef long (*stream_tell_t)(void *);
typedef int  (*stream_flush_t)(void *);

// macro for casting a function to one of the stream functions
// for passing as a parameter to other functions, or storing in generalized structs
#define STREAM_EOF(A)   (stream_eof_t)(A)
#define STREAM_GETC(A)  (stream_getc_t)(A)
#define STREAM_PUTC(A)  (stream_putc_t)(A)
#define STREAM_READ(A)  (stream_read_t)(A)
#define STREAM_WRITE(A) (stream_write_t)(A)
#define STREAM_SEEK(A)  (stream_seek_t)(A)
#define STREAM_TELL(A)  (stream_tell_t)(A)
#define STREAM_FLUSH(A) (stream_flush_t)(A)

#endif
