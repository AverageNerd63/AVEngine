#pragma once

// Unsigined Int Types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Signed Int Types
typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

// Floating Point Types
typedef float f32;
typedef double f64;

// Boolean Types
typedef int b32;
typedef char b8;

// Properly define static assertions
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Ensure all types are the correct size
STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be size of 1 byte");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u8 to be size of 2 byte");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u8 to be size of 4 byte");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u8 to be size of 8 byte");

STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be size of 1 byte");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i8 to be size of 2 byte");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i8 to be size of 4 byte");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i8 to be size of 8 byte");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f8 to be size of 4 byte");
STATIC_ASSERT(sizeof(f64) == 8, "Expected f8 to be size of 8 byte");

#define TRUE 1
#define FALSE 0

// Platform detection
#if defined(WIN32) || defined (_WIN32) || defined (__WIN32__)
#define APLATFORM_WINDOWS 1
#ifndef _WIN64
#error "64-bit is required on Windows!"
#endif
#elif defined(__linux__) || defined (__gnu_linux__)
#define APLATFORM_LINUX 1
#if defined(__ANDROID__)
#define APLATFORM_ANDROID 1
#endif
#elif defined(__unix__)
#define APLATFORM_UNIX 1
#elif __APPLE__
#define APLATFORM_APPLE 1
#include <TargetCondionals.h>
#if TARGET_IPHONE_SIMULATOR
#define APLATFORM_IOS 1
#define APLATFORM_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define APLATFORM_IOS 1
#elif TARGET_OS_MAC
#else
#error "Unkown Apple Platform"
#endif
#else
#error "Unkown Error"
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
