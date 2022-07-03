/*
 * mptPathString.h
 * ---------------
 * Purpose: Wrapper class around the platform-native representation of path names. Should be the only type that is used to store path names.
 * Notes  : Currently none.
 * Authors: OpenMPT Devs
 * The OpenMPT source code is released under the BSD license. Read LICENSE for more details.
 */


#pragma once

#include "openmpt/all/BuildSettings.hpp"

#include "mpt/base/detect.hpp"
#include "mpt/base/namespace.hpp"
#include "mpt/path/basic_path.hpp"
#include "mpt/path/native_path.hpp"
#include "mpt/path/os_path.hpp"
#include "mpt/string/types.hpp"

#include "mptString.h"



OPENMPT_NAMESPACE_BEGIN



namespace mpt
{



#if defined(MPT_ENABLE_CHARSET_LOCALE)

using PathString = mpt::native_path;

#define MPT_PATHSTRING_LITERAL(x) MPT_OS_PATH_LITERAL( x )
#define MPT_PATHSTRING(x) mpt::PathString::FromNative(MPT_OS_PATH_LITERAL( x ))

#else // !MPT_ENABLE_CHARSET_LOCALE

using PathString = mpt::BasicPathString<mpt::Utf8PathTraits, false>;

#define MPT_PATHSTRING_LITERAL(x) ( x )
#define MPT_PATHSTRING(x) mpt::PathString::FromNative( x )

#endif // MPT_ENABLE_CHARSET_LOCALE

using RawPathString = PathString::raw_path_type;

#define PC_(x) MPT_PATHSTRING_LITERAL(x)
#define PL_(x) MPT_PATHSTRING_LITERAL(x)
#define P_(x) MPT_PATHSTRING(x)



#if defined(MPT_ENABLE_CHARSET_LOCALE)
inline std::string ToAString(const mpt::PathString &x)
{
	return x.ToLocale();
}
#else
inline std::string ToAString(const mpt::PathString &x)
{
	return x.ToUTF8();
}
#endif
inline mpt::ustring ToUString(const mpt::PathString &x)
{
	return x.ToUnicode();
}
#if MPT_WSTRING_FORMAT
inline std::wstring ToWString(const mpt::PathString &x)
{
	return x.ToWide();
}
#endif



#if MPT_OS_WINDOWS
#if !(MPT_OS_WINDOWS_WINRT && (_WIN32_WINNT < 0x0a00))
// Returns the absolute path for a potentially relative path and removes ".." or "." components. (same as GetFullPathNameW)
mpt::PathString GetAbsolutePath(const mpt::PathString &path);
#endif
#endif // MPT_OS_WINDOWS

#if defined(MODPLUG_TRACKER) && MPT_OS_WINDOWS

// Relative / absolute paths conversion

mpt::PathString AbsolutePathToRelative(const mpt::PathString &p, const mpt::PathString &relativeTo); // similar to std::fs::path::lexically_approximate
	
mpt::PathString RelativePathToAbsolute(const mpt::PathString &p, const mpt::PathString &relativeTo);

#endif // MODPLUG_TRACKER && MPT_OS_WINDOWS



#if MPT_OS_WINDOWS
#if !MPT_OS_WINDOWS_WINRT
int PathCompareNoCase(const PathString &a, const PathString &b);
#endif // !MPT_OS_WINDOWS_WINRT
#endif



} // namespace mpt



#if defined(MODPLUG_TRACKER)

// Sanitize a filename (remove special chars)

mpt::PathString SanitizePathComponent(const mpt::PathString &filename);

mpt::ustring SanitizePathComponent(mpt::ustring str);

#if defined(MPT_WITH_MFC)
CString SanitizePathComponent(CString str);
#endif // MPT_WITH_MFC

#endif // MODPLUG_TRACKER



OPENMPT_NAMESPACE_END
