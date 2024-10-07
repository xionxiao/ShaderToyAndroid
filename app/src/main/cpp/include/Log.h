//
// Created by xhui on 2024/10/6.
//

#ifndef SHADERTOYANDROID_LOG_H
#define SHADERTOYANDROID_LOG_H

#pragma once

#include <android/log.h>

#ifndef LOG_NDEBUG
#ifdef NDEBUG
#define LOG_NDEBUG 1
#else
#define LOG_NDEBUG 0
#endif
#endif


/*
 * Basic log message macros intended to emulate the behavior of log/log.h
 * in system core.  This should be dependent only on ndk exposed logging
 * functionality.
 */

#ifndef ALOG
#define ALOG(priority, tag, fmt, ...) \
    __android_log_print(ANDROID_##priority, tag, fmt, __VA_ARGS__)
#endif

#ifndef ALOGV
#if LOG_NDEBUG
#define ALOGV(...)   ((void)0)
#else
#define ALOGV(...) ((void)ALOG(LOG_VERBOSE, LOG_TAG, __VA_ARGS__))
#endif
#endif

#ifndef ALOGD
#define ALOGD(...) ((void)ALOG(LOG_DEBUG, LOG_TAG, __VA_ARGS__))
#endif

#ifndef ALOGI
#define ALOGI(...) ((void)ALOG(LOG_INFO, LOG_TAG, __VA_ARGS__))
#endif

#ifndef ALOGW
#define ALOGW(...) ((void)ALOG(LOG_WARN, LOG_TAG, __VA_ARGS__))
#endif

#ifndef ALOGE
#define ALOGE(...) ((void)ALOG(LOG_ERROR, LOG_TAG, __VA_ARGS__))
#endif

#ifndef ALOGF
#define ALOGF(...) ((void)ALOG(LOG_FATAL, LOG_TAG, __VA_ARGS__))
#endif

/*
 * Log a fatal error if cond is true. The condition test is inverted from
 * assert(3) semantics. The test and message are not stripped from release
 * builds
 */
#ifndef ALOG_ALWAYS_FATAL_IF
#define ALOG_ALWAYS_FATAL_IF(cond, ...) \
    if (cond) __android_log_assert(#cond, LOG_TAG, __VA_ARGS__)
#endif

#endif //SHADERTOYANDROID_LOG_H
