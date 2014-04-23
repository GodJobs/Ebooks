LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_PRELINK_MODULE := false
LOCAL_MODULE:= libChapServer
LOCAL_MODULE_TAGS := eng
LOCAL_ALLOW_UNDEFINED_SYMBOLS := true

LOCAL_CFLAGS := $(COMMON_CFLAGS) -Wall -fno-short-enums -fPIC
LOCAL_ALLOW_UNDEFINED_SYMBOLS := true

LOCAL_LDLIBS := -lutils -lcutils -lbinder -llog

LOCAL_SHARED_LIBRARIES := 
LOCAL_SHARED_LIBRARIES += libcutils libutils libbinder libsonivox libicuuc libexpat libdl libandroid_runtime
LOCAL_SHARED_LIBRARIES += libstlport libsqlite

LOCAL_SRC_FILES:= \
	src/IChapService.cpp \
	src/ChapService.cpp \
LOCAL_C_INCLUDES := \
        $(TOP)/external/stlport/stlport \
        $(TOP)/system/core/include/cutils \
        \

include $(BUILD_SHARED_LIBRARY)