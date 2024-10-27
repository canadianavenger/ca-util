/*
 * memstream.h 
 * structure definitions for a simple memory stream buffer
 * 
 * This code is offered without warranty under the MIT License. Use it as you will 
 * personally or commercially, just give credit if you do.
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#ifndef CA_MEMSTREAM
#define CA_MEMSTREAM

typedef struct {
    size_t      len;         // length of buffer in bytes
    size_t      pos;         // current byte position in buffer
    uint8_t     *data;       // pointer to bytes in memory
} memstream_buf_t;

// stdio-like interface for memstream
int  memstream_eof(memstream_buf_t *buf);
int  memstream_getc(memstream_buf_t *buf);
int  memstream_putc(int val, memstream_buf_t *buf);
int  memstream_read(void *dst, size_t size, size_t n_items, memstream_buf_t *buf);
int  memstream_write(const void *src, size_t size, size_t n_items, memstream_buf_t *buf);
int  memstream_seek(memstream_buf_t *buf, long pos, int whence);
long memstream_tell(memstream_buf_t *buf);

// generalized stream_io, allowing functions to be written to accept stdio streams or memstream streams
// generalized function pointers for the stream_io functions
typedef int  (*stream_eof_t)(void *);
typedef int  (*stream_getc_t)(void *);
typedef int  (*stream_putc_t)(int, void *);
typedef int  (*stream_read_t)(void *, size_t, size_t, void *);
typedef int  (*stream_write_t)(void *, size_t, size_t, void *);
typedef int  (*stream_seek_t)(void *, long, int);
typedef long (*stream_tell_t)(void *);

// macro for casting a function to one of the stream functions
// for passing as a parameter to other functions, or storing in generalized structs
#define STREAM_EOF(A)   (stream_eof_t)(A)
#define STREAM_GETC(A)  (stream_getc_t)(A)
#define STREAM_PUTC(A)  (stream_putc_t)(A)
#define STREAM_READ(A)  (stream_read_t)(A)
#define STREAM_WRITE(A) (stream_write_t)(A)
#define STREAM_SEEK(A)  (stream_seek_t)(A)
#define STREAM_TELL(A)  (stream_tell_t)(A)

#endif