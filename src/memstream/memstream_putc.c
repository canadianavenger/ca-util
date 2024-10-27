#include <memstream.h>
#include <errno.h>

int memstream_putc(int val, memstream_buf_t *buf) {
    if(NULL == buf) {
        errno = EBADF;
        return -1;
    }

    if(buf->pos >= buf->len) {
        errno = ENOSPC;
        return EOF;
    }
    buf->data[buf->pos++] = val;
    return val;
}
