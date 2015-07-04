#ifndef _JNI_UTILITY_H_
#define _JNI_UTILITY_H_
#include <string>
#include <android/log.h>
#include "jni.h"

using namespace std;

//JNIEnv* getTsdEnv(void);

#define NELEM(T) sizeof(T)/sizeof(JNINativeMethod)

int registerNativeMethods(JNIEnv* env, const char* className,
                                 JNINativeMethod* gMethods, int numMethods);

int getJavaIntField(JNIEnv *env, jobject obj, const char * name);
void setJavaIntField(JNIEnv *env, jobject obj, const char* name, jint value);

unsigned char getJavaByteField(JNIEnv *env, jobject obj, const char * name);
void setJavaByteField(JNIEnv *env, jobject obj, const char * name, unsigned char value);

string getJavaByteArrayField(JNIEnv *env, jobject obj, const char * name);
void setJavaByteArrayField(JNIEnv *env, jobject obj, const char * name, const string &value);

double getJavaDoubleField(JNIEnv *env, jobject obj, const char * name);
void setJavaDoubleField(JNIEnv *env, jobject obj, const char * name, double value);

string getJavaStringField(JNIEnv *env, jobject obj, const char * name);
void setJavaStringField(JNIEnv *env, jobject obj, const char * name, const string &value);

jlong getJavaLongField(JNIEnv *env, jobject obj, const char * name);
void setJavaLongField(JNIEnv *env, jobject obj, const char* name, jlong value);

#endif //_JNI_UTILITY_H_
