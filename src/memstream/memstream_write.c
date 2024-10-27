#include <memstream.h>
#include <string.h>
#include <errno.h>

int memstream_write(const void *src, size_t size, size_t n_items, memstream_buf_t *buf) {
    if(NULL == buf) {
        errno = EBADF;
        return -1;
    }

    if(NULL == src) {
        errno = EFAULT;
        return -1;
    }

    if((0 == size) || (0 == n_items)) return 0; // nothing to do

    int count = 0;
    while(0 != n_items) {
        if(size > (buf->len - buf->pos)) {
            errno = ENOSPC;
            return count;
        }
        memcpy(&buf->data[buf->pos], src, size);
        buf->pos += size;
        src += size;
        n_items--;
        count++;
    }
    return count;
}
