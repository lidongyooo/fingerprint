#include "binonic_asm.h"

#if defined(__aarch64__)
ENTRY(_my_syscall)
    mov     x8, x0
    mov     x0, x1
    mov     x1, x2
    mov     x2, x3
    mov     x3, x4
    mov     x4, x5
    mov     x5, x6
    svc     #0
    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal
    ret
END(_my_syscall)
#endif