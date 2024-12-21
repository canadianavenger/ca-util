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

/// @brief memstream equivalent of feof()
/// @param buf pointer to a memstream struct
/// @return -1 on error (errno set), non zero if eof, otherwise zero
/// errno = EBADF: bad memstream pointer
int  memstream_eof(memstream_buf_t *buf);

/// @brief memstream equivalent of fgetc()
/// @param buf pointer to a memstream struct
/// @return the character at the current position in the stream. EOF if error or end of stream (errno is set)
/// errno = EBADF: bad memstream pointer
/// errno = EIO: attempt to read past end of memory buffer
int  memstream_getc(memstream_buf_t *buf);

/// @brief memstream equivalent of fputc()
/// @param val value of byte to write
/// @param buf pointer to a memstream struct
/// @return the character written to the stream. EOF if error or end of stream (errno is set)
/// errno = EBADF: bad memstream pointer
/// errno = ENOSPC: attempt to write past end of memory buffer
int  memstream_putc(int val, memstream_buf_t *buf);

/// @brief memstream equivalent of fread()
/// @param dst pointer to the destination buffer 
/// @param size size of the element to read in bytes
/// @param n_items number of elelments to read
/// @param buf pointer to a memstream struct
/// @return the number of items read, if != n_items errno is set
/// errno = EBADF: bad memstream pointer
/// errno = EFAULT: bad destination pointer
/// errno = EIO: attempt to read past end of memory buffer
int  memstream_read(void *dst, size_t size, size_t n_items, memstream_buf_t *buf);

/// @brief memstream equicalent of fwrite()
/// @param src pointer to the source data buffer
/// @param size size of the element to write in bytes
/// @param n_items number of elelments to write
/// @param buf pointer to a memstream struct
/// @return the number of items written, if != n_items errno is set
/// errno = EBADF: bad memstream pointer
/// errno = EFAULT: bad destination pointer
/// errno = ENOSPC: attempt to write past end of memory buffer
int  memstream_write(const void *src, size_t size, size_t n_items, memstream_buf_t *buf);

/// @brief memstream equivalent of fseek()
/// @param buf pointer to a memstream struct
/// @param pos position where to seek to relative to 'whence' value
/// @param whence SEEK_SET, SEEK_CUR, or SEEK_END
/// @return 0 on success, otherwise errno is set
/// errno = EBADF: bad memstream pointer
/// errno = EINVAL: invalid 'whence' value
/// errno = ERANGE: seek would result in a position beyond the bounds of the buffer
int  memstream_seek(memstream_buf_t *buf, long pos, int whence);

/// @brief memstream equivalent of ftell()
/// @param buf pointer to a memstream struct
/// @return current position in the buffer where a read or write would happen. -1 on error with errno set
/// errno = EBADF: bad memstream pointer
long memstream_tell(memstream_buf_t *buf);

#endif
