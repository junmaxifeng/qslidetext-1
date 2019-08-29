/*******************************************************************************
 * Copyright (c) 2017, Induspotis, Inc.
 * All rights reserved.
 *
 * qslidetext_config : QSLIDETEXT
 *
 * filename : qslidetext_config.h
 * author   : hunt978(hubq@initialsoft.com)
 * create   : 2017-04-21 08:30:05 UTC
 * modified : 2019-08-16 06:36:18 UTC
\******************************************************************************/

#ifndef __QSLIDETEXT_CONFIG_H__
#define __QSLIDETEXT_CONFIG_H__

////////////////////////////////////////////////////////////////////////////////
// Headers
//

////////////////////////////////////////////////////////////////////////////////
// Typedefs & Constants
//
/* Windows*/
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define XTLIB_ENV_WINDOWS

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef NOMINMAX
#define NOMINMAX
#endif

/* Linux */
#elif defined(linux) || defined(__linux)
#define XTLIB_ENV_LINUX

/* MacOS */
#elif defined(__APPLE__) || defined(MACOSX) || defined(macintosh) \
  || defined(Macintosh)
#define XTLIB_ENV_MACOS

/* FreeBSD */
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
#define XTLIB_ENV_FREEBSD

/* Others */
#else
#error This operating system is not supported by this library
#endif

/* export symbols */
#if defined(XTLIB_ENV_WINDOWS)
#ifndef XT_BUILD_STATIC
#ifdef BUILD_QSLIDETEXT
#define QSLIDETEXT_API __declspec(dllexport)
#else
#define QSLIDETEXT_API __declspec(dllimport)
#endif
#ifdef _MSC_VER
#pragma warning(disable : 4251)
#endif
#else
#define QSLIDETEXT_API
#endif
#else
#define QSLIDETEXT_API
#endif

////////////////////////////////////////////////////////////////////////////////
// Classes
//

////////////////////////////////////////////////////////////////////////////////
// Functions
//
#endif  // __QSLIDETEXT_CONFIG_H__

////////////////////////////////// EOF /////////////////////////////////////////