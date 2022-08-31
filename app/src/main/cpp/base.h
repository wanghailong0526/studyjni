//
// Created by 王海龙 on 2022/8/30.
//
/**
 *
 * 类型签名
 *     JAVA      JNI
 *     boolean    Z
 *     byte       B
 *     char       C
 *     shot       S
 *     int        I
 *     long       J
 *     float      F
 *     double     D
 *     void       V
 *     String    Ljava/lang/String;
 *     Object    Ljava/lang/Object;
 *     数组类型   [类型 例 int[] = [I   String[] = [Ljava/lang/String;  Object[] = [Ljava/lang/Object;
 *     二维及多维数组(几维就是几个 "[" ) int[][] = [[I  String[][] = [[Ljava/lang/String;  Object[][] = [[Ljava/lang/Object;
 *
 * 方法签名 "(参数列表)返回值"
 *      String test(String s)   "(Ljava/lang/String;)Ljava/lang/String;"
 *      int add(int i,String s) "(ILjava/lang/String)I"
 *      void set(byte[] bytes)  "([B)V"
 *      构造方法                 "<init>"
 *
 *   JNIEnv
 *   1.c++ 中是结构体别名 JNIEnv *env  是一级指针 env->NewStringUTF(this,ljstring,"hello")
 *   2.c 中是结构体指针 JNIEnv *env 是二级指针 (*env)->NewStringUTF(env,jstring,"hello");
 *
 *   3.c++ 调用的是C的函数，在函数执行过程中需要 JNIEnv (例 NewStringUTF(env,"hello")) 因为 c++ 中有 this
 */


#ifndef STUDYJNI_BASE_H
#define STUDYJNI_BASE_H

#include <jni.h>
#include <android/log.h>
//__android_log_print(ANDROID_LOG_ERROR,"whl**","%s","k");
#define LOGV(TAG, FORMAT, ...) __android_log_print(ANDROID_LOG_VERBOSE,TAG,FORMAT,__VA_ARGS__)
#define LOGD(TAG, FORMAT, ...) __android_log_print(ANDROID_LOG_DEBUG,TAG,FORMAT,__VA_ARGS__)
#define LOGI(TAG, FORMAT, ...) __android_log_print(ANDROID_LOG_INFO,TAG,FORMAT,__VA_ARGS__)
#define LOGW(TAG, FORMAT, ...) __android_log_print(ANDROID_LOG_WARN,TAG,FORMAT,__VA_ARGS__)
#define LOGE(TAG, FORMAT, ...) __android_log_print(ANDROID_LOG_ERROR,TAG,FORMAT,__VA_ARGS__)

#endif //STUDYJNI_BASE_H
