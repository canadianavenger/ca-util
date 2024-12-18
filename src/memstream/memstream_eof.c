#include <memstream.h>
#include <errno.h>
#include <string.h>

// stdio-like interface
int memstream_eof(memstream_buf_t *buf) {
    if(NULL == buf) {
        errno = EBADF;
        return -1;
    }
    return buf->pos >= buf->len;
}
