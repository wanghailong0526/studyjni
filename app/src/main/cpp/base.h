//
// Created by 王海龙 on 2022/8/30.
//

#ifndef STUDYJNI_BASE_H
#define STUDYJNI_BASE_H

#include <android/log.h>
//__android_log_print(ANDROID_LOG_ERROR,"whl**","%s","k");
#define LOGV(TAG, FORMAT, ...) __android_log_print(ANDROID_LOG_VERBOSE,TAG,FORMAT,__VA_ARGS__)
#define LOGD(TAG, FORMAT, ...) __android_log_print(ANDROID_LOG_DEBUG,TAG,FORMAT,__VA_ARGS__)
#define LOGI(TAG, FORMAT, ...) __android_log_print(ANDROID_LOG_INFO,TAG,FORMAT,__VA_ARGS__)
#define LOGW(TAG, FORMAT, ...) __android_log_print(ANDROID_LOG_WARN,TAG,FORMAT,__VA_ARGS__)
#define LOGE(TAG, FORMAT, ...) __android_log_print(ANDROID_LOG_ERROR,TAG,FORMAT,__VA_ARGS__)

#endif //STUDYJNI_BASE_H
