#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

// Disable debug and trace logging for relase builds.
#if AVRELEASE == 1
#define LOG_DEBUG_ENABLE 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum log_level {
    LOG_LEVEL_FATAL = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5
} log_level;

b8 intialize_logging();
void shutdown_logging();

AVAPI void log_output(log_level level, const char* message, ...);

// Log a fatal-level message.
#define AVFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, ##__VA_ARGS__);

#ifndef AVERROR
// Logs a error-level message.
#define AVERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
// Logs a warn-level message.
#define AVWARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
#define AVWARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
// Logs a warn-level message.
#define AVINFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
#define AVINFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
// Logs a warn-level message.
#define AVDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
#define AVDEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
// Logs a warn-level message.
#define AVTRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
#define AVTRACE(message, ...)
#endif