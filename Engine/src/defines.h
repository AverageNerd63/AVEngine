#pragma once

// Unsigned int types.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed int types.
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// Floating point types
typedef float f32;
typedef double f64;

// Boolean types
typedef int b32;
typedef char b8;

// Properly define static assertions.
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Ensure all types are of the correct size.
STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u16 to be 2 bytes.");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u32 to be 4 bytes.");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u64 to be 8 bytes.");

STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 bytes.");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 bytes.");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 bytes.");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 bytes.");
STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 bytes.");

#define TRUE 1
#define FALSE 0

// Platform detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) 
#define AVPLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on Windows!"
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
// Linux OS
#define AVPLATFORM_LINUX 1
#if defined(__ANDROID__)
#define AVPLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
// Catch anything not caught by the above.
#define AVPLATFORM_UNIX 1
#elif defined(_POSIX_VERSION)
// Posix
#define AVPLATFORM_POSIX 1
#elif __APPLE__
// Apple platforms
#define AVPLATFORM_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// iOS Simulator
#define AVPLATFORM_IOS 1
#define AVPLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define AVPLATFORM_IOS 1
// iOS device
#elif TARGET_OS_MAC
// Other kinds of Mac OS
#else
#error "Unknown Apple platform"
#endif
#else
#error "Unknown platform!"
#endif

#ifdef AVEXPORT
// Exports
#ifdef _MSC_VER
#define AVAPI __declspec(dllexport)
#else
#define AVAPI __attribute__((visibility("default")))
#endif
#else
// Imports
#ifdef _MSC_VER
#define AVAPI __declspec(dllimport)
#else
#define AVAPI
#endif
#endif

#define AVCLAMP(value, min, max) (value <= min) ? min : (value >= max) ? max \
                                                                      : value;
                                                                      
// Inlining
#ifdef _MSC_VER
#define AVINLINE __forceinline
#define AVNOINLINE __declspec(noinline)
#else
#define AVINLINE static inline
#define AVNOINLINE
#endif