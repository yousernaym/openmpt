
#pragma once

#if defined(MPT_PACKAGE)
#define OPENMPT_VERSION_IS_PACKAGE 1
#else
#define OPENMPT_VERSION_IS_PACKAGE 0
#endif

#if defined(MPT_SVNURL)
#define OPENMPT_VERSION_URL MPT_SVNURL
#endif

#if defined(MPT_SVNVERSION)
#define OPENMPT_VERSION_SVNVERSION MPT_SVNVERSION
#else
// VM is built without OpenMPT's revision-stamping step, so MPT_SVNVERSION is
// never supplied. Define a "0" revision fallback so version.cpp reports
// revision 0 (its existing behaviour) without emitting the compile-time
// "SVN revision unknown" #pragma message.
#define OPENMPT_VERSION_SVNVERSION "0"
#endif

#if defined(MPT_SVNDATE)
#define OPENMPT_VERSION_DATE MPT_SVNDATE
#endif

