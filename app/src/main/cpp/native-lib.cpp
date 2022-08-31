#include "base.h"
#include <string>
#include <stdlib.h>

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

JNIEXPORT void JNICALL
Java_com_whl_studyjni_MainActivity_show(JNIEnv *env, jclass clazz) {
    LOGI(TAG, "\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    //jni调用java方法 show(String) 签名_()Ljava/lang/String;
    jmethodID mid = env->GetStaticMethodID(clazz, "show", "(Ljava/lang/String;)V");
    jstring jstr = env->NewStringUTF("hello from jni");
    env->CallStaticVoidMethod(clazz, mid, jstr);
}

JNIEXPORT jint JNICALL
Java_com_whl_studyjni_MainActivity_delete(JNIEnv *env, jobject thiz, jint a, jint b) {
    LOGI(TAG, "\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    return a - b;
}


JNIEXPORT void JNICALL
Java_com_whl_studyjni_MainActivity_getNum(JNIEnv *env, jobject thiz) {
    LOGI(TAG, "\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    jclass clazz = env->GetObjectClass(thiz);
    jfieldID aid = env->GetFieldID(clazz, "arr", "I");
    jint a = env->GetIntField(thiz, aid);
    LOGE(TAG, "从java层获取到 a=%d\n", a);
}

JNIEXPORT void JNICALL
Java_com_whl_studyjni_MainActivity_getStaticNum(JNIEnv *env, jobject thiz) {
    LOGI(TAG, "\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    jclass clazz = env->GetObjectClass(thiz);
    jfieldID bid = env->GetStaticFieldID(clazz, "b", "I");
    jint b = env->GetStaticIntField(clazz, bid);
    LOGE(TAG, "从java层获取到 b=%d\n", b);
}

JNIEXPORT void JNICALL
Java_com_whl_studyjni_MainActivity_getString(JNIEnv *env, jobject thiz) {
    jclass sclazz = env->GetObjectClass(thiz);
    jfieldID sid = env->GetFieldID(sclazz, "s", "Ljava/lang/String;");
    jstring jstr = (jstring) env->GetObjectField(thiz, sid);
    const char *schar = env->GetStringUTFChars(jstr, JNI_FALSE);
    LOGE(TAG, "从java层获取到的s=%s", schar);
}

JNIEXPORT void JNICALL
Java_com_whl_studyjni_MainActivity_accessField(JNIEnv *env, jobject thiz) {
    jclass aClass = env->GetObjectClass(thiz);
    jfieldID aid = env->GetFieldID(aClass, "arr", "I");
    env->SetIntField(thiz, aid, 10);
}

JNIEXPORT jstring JNICALL
Java_com_whl_studyjni_MainActivity_getName(JNIEnv *env, jobject thiz) {
    //下面的方法可能会乱码
    char *content = "王海龙";
//    return env->NewStringUTF(str);

    //可以使用 java 的方法 String(byte bytes[], String charsetName)
    jsize contentLength = strlen(content);
    jclass strClazz = env->FindClass("java/lang/String");
    jmethodID strid = env->GetMethodID(strClazz, "<init>", "([BLjava/lang/String;)V");
    jstring charset = env->NewStringUTF("utf-8");
    jbyteArray bytes = env->NewByteArray(contentLength);//barr是空的
    //为 bytes 数组赋值
    env->SetByteArrayRegion(bytes, 0, contentLength, (jbyte *) content);
    return (jstring) env->NewObject(strClazz, strid, bytes, charset);

}

int compare(const void *a, const void *b) {
    return *((int *) a) - *((int *) b);
}

JNIEXPORT
void JNICALL
Java_com_whl_studyjni_MainActivity_sortArr(JNIEnv *env, jobject thiz, jintArray a) {
    //获取 java 传入的数组
    jint *elems = env->GetIntArrayElements(a, JNI_FALSE);
    jsize len = env->GetArrayLength(a);
    qsort(elems, len, sizeof(jint), compare);
    //JNI_COMMIT 数据将会复制回去，备份空间将不会被释放,会同步到 java
//    env->ReleaseIntArrayElements(a, elems, JNI_COMMIT);
    //JNI_ABORT 备份空间将会被释放;需要自己拷贝一份；里面所有的变更都会丢失不会同步到java
    env->ReleaseIntArrayElements(a, elems, JNI_ABORT);
}


#ifdef __cplusplus
}
#endif

