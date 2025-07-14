#pragma once

#include "defines.h"

// Disable assertion by commenting out the line below
#define AVASSERTIONS_ENABLED

#ifdef AVASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

AVAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define AVASSERT(expr)                                                \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }

#define AVASSERT_MSG(expr, message)                                        \
    {                                                                     \
        if (expr) {                                                       \
        } else {                                                          \
            report_assertion_failure(#expr, message, __FILE__, __LINE__); \
            debugBreak();                                                 \
        }                                                                 \
    }

#ifdef _DEBUG
#define AVASSERT_DEBUG(expr)                                          \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }
#else
#define AVASSERT_DEBUG(expr)  // Does nothing at all
#endif

#else
#define AVASSERT(expr)               // Does nothing at all
#define AVASSERT_MSG(expr, message)  // Does nothing at all
#define AVASSERT_DEBUG(expr)         // Does nothing at all
#endif