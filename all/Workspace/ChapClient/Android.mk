#
# Copyright (C) 2008 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := chapclient
LOCAL_MODULE_TAGS := eng
LOCAL_PRELINK_MODULE := false

LOCAL_CFLAGS := $(COMMON_CFLAGS) -Wall -fno-short-enums -fPIC
#LOCAL_LDLIBS := -lbinder -llog -lutils -lcutils

LOCAL_SRC_FILES := \
    src/ChapClient.cpp \

LOCAL_SHARED_LIBRARIES := \
        libnativehelper \
        libcutils \
        libutils \
        libbinder \
        libnetutils \
        libChapServer \

LOCAL_C_INCLUDES += \
    \
    $(TOP)/external/skia/include/core \
    $(TOP)/external/skia/include/utils \
    $(TOP)/framework/native/include/ui \
    $(TOP)/framework/native/include/utils \
    \
    src/IChapService.h \
    src/ChapService.h \

LOCAL_ALLOW_UNDEFINED_SYMBOLS := true

include $(BUILD_EXECUTABLE)

