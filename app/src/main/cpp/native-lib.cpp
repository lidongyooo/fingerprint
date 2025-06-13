#include <jni.h>
#include <string>
#include "netinet/in.h"
#include "arpa/inet.h"
#include "unistd.h"
#include "android/log.h"

#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, "fingerprintnative", __VA_ARGS__);

extern "C" JNIEXPORT jstring JNICALL
Java_com_lidongyooo_fingerprint_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jboolean JNICALL Java_com_lidongyooo_fingerprint_MainActivity_fridaPortCheck(JNIEnv *env, jobject /*this*/, jint port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        LOGE("socket() failed with errno: %d (%s)", errno, strerror(errno)); // 👈 关
        return JNI_FALSE;
    }

    struct sockaddr_in sa{};
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    if (inet_aton("127.0.0.1", &sa.sin_addr) <= 0) {
        close(sock);
        return JNI_FALSE;
    }

    int result = connect(sock, reinterpret_cast<struct sockaddr *>(&sa), sizeof(sa));
    close(sock);
    return (result == 0) ? JNI_TRUE : JNI_FALSE;
}


extern "C"
JNIEXPORT jboolean JNICALL Java_com_lidongyooo_fingerprint_MainActivity_fridaMapsCheck(JNIEnv *env, jobject /*this*/) {
    char line[512];
    FILE *fp;
    fp = fopen("/proc/self/maps", "r");
    if (fp) {
        while (fgets(line, 512, fp)) {
            LOGE("%s", line);
            if (strstr(line, "frida")) {
                return JNI_TRUE;
            }
        }
        fclose(fp);
    }

    return JNI_FALSE;
}

extern "C"
JNIEXPORT jboolean JNICALL Java_com_lidongyooo_fingerprint_MainActivity_fridaCheck(JNIEnv *env, jobject /*this*/) {
    char line[512];
    FILE *fp;
    fp = fopen("/proc/self/maps", "r");
    if (fp) {
        while (fgets(line, 512, fp)) {
            if (strstr(line, "frida")) {
                return JNI_TRUE;
            }
        }
        fclose(fp);
    }

    return JNI_FALSE;
}
