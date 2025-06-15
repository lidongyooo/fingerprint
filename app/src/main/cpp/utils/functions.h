//
// Created by lidongyooo on 2025/6/14.
//

#ifndef FINGERPRINT_FUNCTIONS_H
#define FINGERPRINT_FUNCTIONS_H
char* my_strstr(const char* haystack, const char* needle);
char* my_fgets(char *buf, int size, int fd);
#include "android/log.h"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "fingerprintnative", __VA_ARGS__);
// 在 functions.cpp 或 native-lib.cpp 中
#endif //FINGERPRINT_FUNCTIONS_H
