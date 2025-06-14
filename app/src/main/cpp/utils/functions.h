//
// Created by lidongyooo on 2025/6/14.
//

#ifndef FINGERPRINT_FUNCTIONS_H
#define FINGERPRINT_FUNCTIONS_H
char* my_strstr(const char* haystack, const char* needle);
ssize_t my_getline(char *buf, size_t size, int fd);
extern "C" {
    extern int my_open(const char *pathname, int flags);
    extern ssize_t my_read(int fd, void *buf, size_t count);
    extern int my_close(int fd);
}
#endif //FINGERPRINT_FUNCTIONS_H
