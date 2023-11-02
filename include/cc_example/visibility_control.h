#ifndef CC_EXAMPLE__VISIBILITY_CONTROL_H_
#define CC_EXAMPLE__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define CC_EXAMPLE_EXPORT __attribute__ ((dllexport))
    #define CC_EXAMPLE_IMPORT __attribute__ ((dllimport))
  #else
    #define CC_EXAMPLE_EXPORT __declspec(dllexport)
    #define CC_EXAMPLE_IMPORT __declspec(dllimport)
  #endif
  #ifdef CC_EXAMPLE_BUILDING_LIBRARY
    #define CC_EXAMPLE_PUBLIC CC_EXAMPLE_EXPORT
  #else
    #define CC_EXAMPLE_PUBLIC CC_EXAMPLE_IMPORT
  #endif
  #define CC_EXAMPLE_PUBLIC_TYPE CC_EXAMPLE_PUBLIC
  #define CC_EXAMPLE_LOCAL
#else
  #define CC_EXAMPLE_EXPORT __attribute__ ((visibility("default")))
  #define CC_EXAMPLE_IMPORT
  #if __GNUC__ >= 4
    #define CC_EXAMPLE_PUBLIC __attribute__ ((visibility("default")))
    #define CC_EXAMPLE_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define CC_EXAMPLE_PUBLIC
    #define CC_EXAMPLE_LOCAL
  #endif
  #define CC_EXAMPLE_PUBLIC_TYPE
#endif
#endif  // CC_EXAMPLE__VISIBILITY_CONTROL_H_
// Generated 01-Nov-2023 22:52:32
// Copyright 2019-2020 The MathWorks, Inc.
