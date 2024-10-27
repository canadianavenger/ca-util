#include <memstream.h>
#include <errno.h>

int  memstream_seek(memstream_buf_t *buf, long pos, int whence) {
    ssize_t dest = 0;

    if(NULL == buf) {
        errno = EBADF;
        return -1;
    }

    switch (whence)
    {
    case SEEK_SET:
        dest = pos;
        break;
    
    case SEEK_CUR:
        dest = buf->pos + pos;
        break;

    case SEEK_END:
        dest = buf->len - pos;
        break;

    default: // unknown 'whence' value, return 
        errno = EINVAL;
        return -1;
    }

    // return ERANGE if seek was beyond the limits of the memory buffer
    if((0 > dest) || (dest > buf->len)) {
        errno = ERANGE;
        return -1;
    }

    buf->pos = dest;
    return 0;
}
