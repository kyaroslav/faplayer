
#include <jni.h>

extern "C" {

// definations from player.c
int player_open(const char* file);
void player_close();
int player_play(double start, int ast);
void player_pause();
void player_resume();
int player_seek(double time);

int player_get_duration();
double player_get_current_time();

int player_set_video_mode(int mode);

int player_get_video_width();
int player_get_video_height();

int player_is_playing();

// defination from ao_android_wrapper.cpp
jint attach(JNIEnv *env, jobject thiz, jobject surf);
void detach(JNIEnv *env, jobject thiz);

// exports
#ifndef CLASS
#error "?"
#endif

#define NAME1(CLZ, FUN) Java_##CLZ##_##FUN
#define NAME2(CLZ, FUN) NAME1(CLZ, FUN)

#define NAME(FUN) NAME2(CLASS, FUN)

JNIEXPORT jint JNICALL NAME(open)(JNIEnv *env, jobject thiz, jstring file) {
    jint result;
    const char *f;
    jboolean copy;

    f = env->GetStringUTFChars(file, &copy);
    result = player_open(f);
    env->ReleaseStringUTFChars(file, f);

    return result;
}

JNIEXPORT void JNICALL NAME(close)(JNIEnv *env, jobject thiz) {
    player_close();
}

JNIEXPORT jint JNICALL NAME(play)(JNIEnv *env, jobject thiz, jdouble start, jint ast) {
    return player_play(start, ast);
}

JNIEXPORT void JNICALL NAME(pause)(JNIEnv *env, jobject thiz) {
    player_pause();
}

JNIEXPORT void JNICALL NAME(resume)(JNIEnv *env, jobject thiz) {
    player_resume();
}

JNIEXPORT int JNICALL NAME(seek)(JNIEnv *env, jobject thiz, jdouble time) {
    return player_seek(time);
}

JNIEXPORT jint JNICALL NAME(getDuration)(JNIEnv *env, jobject thiz) {
    return player_get_duration();
}

JNIEXPORT jint JNICALL NAME(getCurrentTime)(JNIEnv *env, jobject thiz) {
    return player_get_current_time();
}

JNIEXPORT jint JNICALL NAME(setVideoMode)(JNIEnv *env, jobject thiz, jint mode) {
    if (mode < 0 || mode > 2)
        return -1;
    player_set_video_mode(mode);
}

JNIEXPORT jint JNICALL NAME(getVideoWidth)(JNIEnv *env, jobject thiz) {
    return player_get_video_width();
}

JNIEXPORT jint JNICALL NAME(getVideoHeight)(JNIEnv *env, jobject thiz) {
    return player_get_video_height();
}

JNIEXPORT jboolean JNICALL NAME(isPlaying)(JNIEnv *env, jobject thiz) {
    return player_is_playing() == 0 ? 1 : 0;
}

JNIEXPORT jint JNICALL NAME(attach)(JNIEnv *env, jobject thiz, jobject surf) {
    return attach(env, thiz, surf);
}

JNIEXPORT void JNICALL NAME(detach)(JNIEnv *env, jobject thiz) {
    detach(env, thiz);
}

}
