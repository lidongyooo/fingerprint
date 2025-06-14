//
// Created by lidongyooo on 2025/6/14.
//

#include <stddef.h>
#include "sys/types.h"
#include "functions.h"

size_t my_strlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') ++len;
    return len;
}

char* my_strstr(const char* haystack, const char* needle) {
    if (!needle) {
        return (char*) &haystack;
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

ssize_t my_getline(char *buf, size_t size, int fd) {
    if (!buf || size <= 0) return -1;

    size_t i = 0;
    char c;

    while (i < size - 1) {
        ssize_t n = my_read(fd, &c, 1);
        if (n <= 0) break; // EOF or error

        buf[i++] = c;
        if (c == '\n') break;
    }

    buf[i] = '\0';
    return i > 0 ? (ssize_t)i : -1;
}