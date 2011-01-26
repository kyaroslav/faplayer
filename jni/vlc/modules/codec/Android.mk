
LOCAL_PATH := $(call my-dir)

# liblibmpeg2_plugin.so

include $(CLEAR_VARS)

# "^lib" is auto removed
#LOCAL_MODULE := liblibmpeg2_plugin

LOCAL_CFLAGS += \
    -std=c99 \
    -D__THROW= \
    -DHAVE_CONFIG_H \
    -DNDEBUG \
    -D__PLUGIN__ \
    -DMODULE_STRING=\"libmpeg2\"

LOCAL_C_INCLUDES += \
    $(VLCROOT)/compat \
    $(VLCROOT) \
    $(VLCROOT)/include \
    $(VLCROOT)/src \
    $(EXTROOT)/libmpeg2/include

LOCAL_SRC_FILES := \
    libmpeg2.c

LOCAL_SHARED_LIBRARIES += vlccore mpeg2

#include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

include $(call all-makefiles-under,$(LOCAL_PATH))

