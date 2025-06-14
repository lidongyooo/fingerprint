//
// Created by lidongyooo on 2025/6/14.
//
//#include "binonic_asm.h"

#if defined(__aarch64__)

ENTRY(my_open)
    mov     x8, __NR_open       // open()
    svc     #0
    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal
    ret
END(my_open)

ENTRY(my_read)
    mov     x8, __NR_read       // read()
    svc     #0
    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal
    ret
END(my_read)

ENTRY(my_close)
    mov     x8, __NR_close      // close()
    svc     #0
    cmn     x0, #(MAX_ERRNO + 1)
    cneg    x0, x0, hi
    b.hi    __set_errno_internal
    ret
END(my_close)

#endif