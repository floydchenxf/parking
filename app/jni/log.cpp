#include "log.h"
#include <stdarg.h>
#include <stdio.h>
#include <string>

bool logEnable = false;
void wxLogEnable(bool enable)
{
    logEnable = enable;
}

#ifdef __ANDROID__
#include <android/log.h>
//This funciton defined in android jni.
extern void nativeLog(int level, const std::string& tag, const std::string& log);

void  wxLog(int prio, const char *tag, ...)
{
    if( !logEnable ){
        return;
    }
    
    va_list ap;
    char buf[LOG_BUF_SIZE];
    va_start(ap, tag);
    char* fmt = va_arg(ap, char*);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);
    __android_log_write(prio, tag, buf);
}

void printLog(int prio, const char *tag, ...) {
    va_list ap;
    char buf[LOG_BUF_SIZE];
    va_start(ap, tag);
    char* fmt = va_arg(ap, char*);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);
    __android_log_write(prio, tag, buf);
}
#else
void  wxLog(int prio, const char *tag, ...)
{
    if( !logEnable )
        return;
    
    va_list ap;
    char buf[LOG_BUF_SIZE];
    va_start(ap, tag);
    char* fmt = va_arg(ap, char*);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);
    printf("\n");
    printf("%s : ", tag);
    printf("%s", buf);
}

void printLog(int prio, const char *tag, ...) {
    va_list ap;
    char buf[LOG_BUF_SIZE];
    va_start(ap, tag);
    char* fmt = va_arg(ap, char*);
    vsnprintf(buf, LOG_BUF_SIZE, fmt, ap);
    va_end(ap);
    printf("\n");
    printf("%s : ", tag);
    printf("%s", buf);
}
#endif

