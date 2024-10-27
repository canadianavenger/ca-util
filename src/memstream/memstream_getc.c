#include <memstream.h>
#include <errno.h>

int memstream_getc(memstream_buf_t *buf) {
    if(NULL == buf) {
        errno = EBADF;
        return -1;
    }

    if(buf->pos >= buf->len) {
        errno = EIO;
        return EOF;
    }
    return buf->data[buf->pos++];
}
