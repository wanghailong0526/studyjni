#include <jni.h>
#include <string>
#include "base.h"

#define TAG "whl**"
#ifdef __cplusplus//如果当前是 C++ 环境
extern "C" { ;//以C的方式编译
#endif

JNIEXPORT jstring JNICALL
Java_com_whl_studyjni_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */) {
    LOGI(TAG, "\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    std::string hello = "Hello from C++";
    LOGE(TAG, "%s\n", hello.c_str());
    return env->NewStringUTF(hello.c_str());
}



#ifdef __cplusplus
}
#endif