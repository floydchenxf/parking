LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_LDLIBS := -llog

LOCAL_MODULE    := graph

LOCAL_CPPFLAGS += -Wall
LOCAL_CPPFLAGS += -fexceptions
LOCAL_CPPFLAGS += -O2 #-rdynamic -g
LOCAL_CPPFLAGS += -DANDROID_OS_DEBUG -DANDROID_DADIAN
LOCAL_CPPFLAGS += -DCERTIFICATE_DEBUG

LOCAL_C_INCLUDES += $(LOCAL_PATH)/

LOCAL_SRC_FILES +=  log.cpp\
    util.cpp\
    graph.cpp\
    graph_jni.cpp\

LOCAL_DEFAULT_CPP_EXTENSION := cpp

#include $(BUILD_EXECUTABLE)
include $(BUILD_SHARED_LIBRARY)