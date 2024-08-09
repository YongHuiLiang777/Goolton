#include <jni.h>
#include <string>
#include <android/log.h>

#define LOG_TAG __FILE_NAME__
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_nativecamera2demo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_nativecamera2demo_MainActivity_nativeSendCameraData(JNIEnv *env, jobject thiz,
                                                                     jlong jts, jobject jdata,
                                                                     jint jwidth, jint jweight) {
  // TODO: implement nativeSendCameraData()
  auto ts = static_cast<int64_t>(jts);
  auto data_y_ptr = reinterpret_cast<jbyte*>(env->GetDirectBufferAddress(jdata));
  auto data = reinterpret_cast<uint8_t*>(data_y_ptr);
  auto width = reinterpret_cast<int>(jwidth);
  auto weight = reinterpret_cast<int>(jweight);
  LOGD("ts:%ld width:%d weight:%d", ts, width, weight);


}