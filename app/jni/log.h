//
//  log.h
//  INet_HELP
//
//  Created by xianzhen on 14-6-17.
//  Copyright (c) 2014年 qinghua.liqh. All rights reserved.
//

#ifndef INet_HELP_log_h
#define INet_HELP_log_h

#define LOG_BUF_SIZE 1024

typedef enum LogPriority {
    UNKNOWN = 0,
    DEFAULT,    /* only for SetMinPriority() */
    LOG_VERBOSE,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_FATAL,
    LOG_SILENT,     /* only for SetMinPriority(); must be last */
} LogPriority;

// log开关，默认关闭
void wxLogEnable(bool enable);

void wxLog(int prio, const char* tag, ...);

void printLog(int prio, const char *tag, ...);

#define LOG_INFO(tag, ...) \
wxLog(LOG_INFO, tag, __VA_ARGS__)

#define LOG_WARN(tag, ...) \
wxLog(LOG_WARN, tag, __VA_ARGS__)

#define LOG_ERROR(tag, ...) \
wxLog(LOG_ERROR, tag, __VA_ARGS__)

#define LOG_TODO(...) \
wxLog(LOG_INFO, "TODO",  __VA_ARGS__)

#define LOG_DEBUG(tag, ...) \
wxLog(LOG_DEBUG, tag,  __VA_ARGS__)

#define TODO(...) \
wxLog(LOG_INFO, "TODO",  __VA_ARGS__)

#undef DEBUG_LOG
#define DEBUG_LOG(...) \
wxLog(LOG_INFO, "iOS",  __VA_ARGS__)

#define INET_PRINTF(...) \
wxLog(LOG_INFO, "iOS",  __VA_ARGS__)

#endif