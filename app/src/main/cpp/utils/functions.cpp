//
// Created by lidongyooo on 2025/6/14.
//

#include <stddef.h>
#include "sys/types.h"
#include "functions.h"
#include "syscall.h"
#include "sys/syscall.h"
#include "errno.h"

size_t my_strlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') ++len;
    return len;
}

char* my_strstr(const char* haystack, const char* needle) {
    if (!needle) {
        return (char*) haystack;
    }

    size_t h_len = my_strlen(haystack);
    size_t n_len = my_strlen(needle);

    for (size_t i = 0; i <= h_len; i++) {
        size_t j = 0;
        while (j < n_len && haystack[i + j] == needle[j]) {
            j++;
        }

        if (j == n_len) {
            return (char *) &haystack[i];
        }
    }

    return nullptr;
}


char* my_fgets(char *buf, int size, int fd) {
    if (buf == NULL || size <= 0 || fd < 0)
        return NULL;

    char *p = buf;
    int remaining = size - 1;
    ssize_t n;

    while (remaining > 0) {
        char c;
        n = _my_syscall(__NR_read, fd, &c, 1);

        if (n <= 0) {
            // 错误或 EOF
            break;
        }

        *p++ = c;
        remaining--;

        if (c == '\n') {
            break; // 遇到换行符则停止
        }
    }

    *p = '\0'; // 字符串结尾

    if (p == buf && n <= 0) {
        // 没有读取任何内容，且发生错误或 EOF
        return NULL;
    }

    return buf;
}