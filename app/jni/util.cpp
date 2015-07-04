#include "util.h"
#include "log.h"

static const char* TAG = "util@Native";

//extern JavaVM *gvm;

//JNIEnv 线程局部变量
//pthread_key_t gEnvKey;
//pthread_once_t gOnce = PTHREAD_ONCE_INIT;
//
//static void freeEnv(void *ptr)
//{
//    pthread_setspecific(gEnvKey, NULL);
//    gvm->DetachCurrentThread();
//    LOG_INFO(TAG, "freeEnv.\n");
//}

//static void init_once(void)
//{
//    pthread_key_create(&gEnvKey, freeEnv);
//}

//JNIEnv* getTsdEnv(void)
//{
//    void* ptr = NULL;
//    pthread_once(&gOnce, init_once);
//
//    if ((ptr = pthread_getspecific(gEnvKey)) == NULL) {
//        JNIEnv *env = NULL;
//        jint ret = gvm->AttachCurrentThread((JNIEnv**)&env, NULL);
//        if(ret == JNI_OK){
//            pthread_setspecific(gEnvKey, env);
//            ptr = env;
//        }
//    }
//    return (JNIEnv*)ptr;
//}

int registerNativeMethods(JNIEnv* env, const char* className,
                                 JNINativeMethod* gMethods, int numMethods)
{
    jclass clazz;
    clazz = env->FindClass(className);
    if (clazz == NULL) {
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods,numMethods) < 0){
        return JNI_FALSE;
    }
    
    return JNI_TRUE;
}

int getJavaIntField(JNIEnv *env, jobject obj, const char * name){
	jclass cls = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(cls, name, "I");
	env->DeleteLocalRef(cls);
	return env->GetIntField(obj, fid);
}

void setJavaIntField(JNIEnv *env, jobject obj, const char* name, jint value){
	jclass cls = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(cls, name, "I");
	env->SetIntField(obj, fid, (jint)value);
	env->DeleteLocalRef(cls);
}

unsigned char getJavaByteField(JNIEnv *env, jobject obj, const char * name){
	jclass cls = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(cls, name, "B");
	env->DeleteLocalRef(cls);
	return env->GetByteField(obj, fid);
}

void setJavaByteField(JNIEnv *env, jobject obj, const char * name, unsigned char value){
	jclass cls = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(cls, name, "B");
	env->DeleteLocalRef(cls);
	env->SetByteField(obj, fid, (jbyte)value);
}

string getJavaByteArrayField(JNIEnv *env, jobject obj, const char * name){
	jclass cls = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(cls, name, "[B");
	env->DeleteLocalRef(cls);

	jbyteArray fobj = (jbyteArray)env->GetObjectField(obj, fid);
	if(fobj == NULL){
		return "";
	}
	jbyte *bytearray = env->GetByteArrayElements(fobj, NULL);
	int len = env->GetArrayLength(fobj);

	string stdstr;
	stdstr.reserve(len);
	stdstr.append((const char*)bytearray, len);

	env->ReleaseByteArrayElements(fobj, bytearray, JNI_ABORT);
	env->DeleteLocalRef(fobj);
	return stdstr;
}

void setJavaByteArrayField(JNIEnv *env, jobject obj, const char * name, const string &value){
	jclass cls = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(cls, name, "[B");

	jbyteArray fobj = env->NewByteArray(value.length());

	env->SetByteArrayRegion(fobj, 0, value.length(), reinterpret_cast<const signed char*>(value.c_str()));
	env->SetObjectField(obj, fid, fobj);

	env->DeleteLocalRef(cls);
	env->DeleteLocalRef(fobj);
}

double getJavaDoubleField(JNIEnv *env, jobject obj, const char * name){
	jclass cls = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(cls, name, "D");
	env->DeleteLocalRef(cls);
	return env->GetDoubleField(obj, fid);
}


void setJavaDoubleField(JNIEnv *env, jobject obj, const char * name, double value){
	jclass cls = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(cls, name, "D");
	env->DeleteLocalRef(cls);
	env->SetDoubleField(obj, fid, (jdouble)value);
}

string getJavaStringField(JNIEnv *env, jobject obj, const char * name){
	jclass cls = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(cls, name, "Ljava/lang/String;");
	env->DeleteLocalRef(cls);

	jstring jstr = (jstring)env->GetObjectField(obj, fid);
	if(jstr == NULL){
		return "";
	}
	const char* str = env->GetStringUTFChars(jstr, NULL);
	string stdstr = str;
	env->ReleaseStringUTFChars(jstr, str);
	env->DeleteLocalRef(jstr);
	return stdstr;
}

void setJavaStringField(JNIEnv *env, jobject obj, const char * name, const string &value){
	jclass cls = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(cls, name, "Ljava/lang/String;");
	env->DeleteLocalRef(cls);

	jstring jvalue = env->NewStringUTF(value.c_str());
	env->SetObjectField(obj, fid, jvalue);
	env->DeleteLocalRef(jvalue);
}

jlong getJavaLongField(JNIEnv *env, jobject obj, const char * name){
	jclass cls = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(cls, name, "J");
	env->DeleteLocalRef(cls);
	return env->GetLongField(obj, fid);
}

void setJavaLongField(JNIEnv *env, jobject obj, const char* name, jlong value){
	jclass cls = env->GetObjectClass(obj);
	jfieldID fid = env->GetFieldID(cls, name, "J");
	env->SetLongField(obj, fid, value);
	env->DeleteLocalRef(cls);
}
