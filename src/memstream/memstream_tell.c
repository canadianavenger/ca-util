#include <memstream.h>
#include <errno.h>

long memstream_tell(memstream_buf_t *buf) {
    if(NULL == buf) {
        errno = EBADF;
        return -1;
    }
    
    return buf->pos;
}