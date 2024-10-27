#include <memstream.h>
#include <string.h>
#include <errno.h>

int memstream_read(void *dst, size_t size, size_t n_items, memstream_buf_t *buf) {
    if(NULL == buf) {
        errno = EBADF;
        return -1;
    }

    if(NULL == dst) {
        errno = EFAULT;
        return -1;
    }

    if((0 == size) || (0 == n_items)) return 0; // nothing to do

    int count = 0;
    while(0 != n_items) {
        if(size > (buf->len - buf->pos)) {
            errno = EIO;
            return count;
        }
        memcpy(dst, &buf->data[buf->pos], size);
        buf->pos += size;
        dst += size;
        n_items--;
        count++;
    }
    return count;
}
