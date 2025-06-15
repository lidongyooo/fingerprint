// Our customized __set_errno_internal for syscall.S to use.
// we do not use the one from libc due to issue https://github.com/android/ndk/issues/1422
#include "errno.h"

extern "C" long __set_errno_internal(int n) {
    errno = n;
    return -1;
}