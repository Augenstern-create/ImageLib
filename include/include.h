#ifndef INCLUDE_H
#define INCLUDE_H
#include <stdio.h>
// Interface visibility
#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_DLL
    #ifdef __GNUC__
      #define PUBLIC __attribute__((dllexport))
    #else
      #define PUBLIC __declspec(dllexport)
    #endif
  #else
    #ifdef __GNUC__
      #define PUBLIC __attribute__((dllimport))
    #else
      #define PUBLIC __declspec(dllimport)
    #endif
  #endif
  #define LOCAL
#else
  #if __GNUC__ >= 4
    #define PUBLIC __attribute__((visibility("default")))
    #define LOCAL __attribute__((visibility("hidden")))
  #else
    #define PUBLIC
    #define LOCAL
  #endif
#endif

#ifdef __cplusplus
  #define NAN_API_C extern "C"
#else
  #define NAN_API_C
#endif

#if defined BUILDING_DLL
#define NAN_API NAN_API_C PUBLIC
#else
#define NAN_API NAN_API_C PUBLIC
#endif

#ifndef _MAX_DRIVE
#define _MAX_DRIVE 3
#endif
#ifndef _MAX_FNAME
#define _MAX_FNAME 256
#endif
#ifndef _MAX_EXT
#define _MAX_EXT 256
#endif
#ifndef _MAX_DIR
#define _MAX_DIR 256
#endif
#ifndef MIN
#define MIN(a, b)    ( (a) > (b) ? (b) : (a) )
#endif
#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifdef _AUTO_EXPOSURE
NAN_API void LocalExponentialCorrection(unsigned char *Input, unsigned char *Output, int Width, int Height, int Channels);
NAN_API void LocalColorCorrection(unsigned char *Input, unsigned char *Output, int Width, int Height, int Channels);
#endif

#endif