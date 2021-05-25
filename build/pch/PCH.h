

#pragma once


#if defined(MPT_BUILD_ENABLE_PCH)


#include "openmpt/all/BuildSettings.hpp"


#if defined(MODPLUG_TRACKER)
#if defined(MPT_WITH_MFC)
#include <afx.h>
#include <afxwin.h>
#include <afxext.h>
#include <afxcmn.h>
#include <afxcview.h>
#include <afxdlgs.h>
#ifdef MPT_MFC_FULL
#include <afxlistctrl.h>
#endif // MPT_MFC_FULL
#include <afxole.h>
#endif // MPT_WITH_MFC
#endif // MODPLUG_TRACKER


#if MPT_COMPILER_MSVC
#include <intrin.h>
#endif // MPT_COMPILER_MSVC


#if defined(MODPLUG_TRACKER)
#if MPT_OS_WINDOWS
#include <windows.h>
#include <windowsx.h>
#include <shlwapi.h>
#include <mmsystem.h>
#endif // MPT_OS_WINDOWS
#endif // MODPLUG_TRACKER


#include "mpt/base/aligned_array.hpp"
#include "mpt/base/span.hpp"
#include "mpt/crc/crc.hpp"
#include "mpt/crypto/hash.hpp"
#include "mpt/crypto/jwk.hpp"
#include "mpt/exception_text/exception_text.hpp"
#include "mpt/out_of_memory/out_of_memory.hpp"
#include "mpt/system_error/system_error.hpp"
#if defined(MODPLUG_TRACKER)
#include "mpt/uuid/guid.hpp"
#endif // MODPLUG_TRACKER
#include "mpt/uuid/uuid.hpp"

#include "openmpt/base/Endian.hpp"
#include "openmpt/base/Types.hpp"
#include "openmpt/logging/Logger.hpp"

#include "../common/mptBaseMacros.h"
#include "../common/mptBaseTypes.h"
#include "../common/mptAssert.h"
#include "../common/mptBaseUtils.h"
#include "../common/mptMemory.h"
#include "../common/mptString.h"
#include "../common/mptStringFormat.h"
#include "../common/mptStringParse.h"
#include "../common/mptPathString.h"
#include "../common/Logging.h"
#include "../common/misc_util.h"

#include "../common/ComponentManager.h"
#include "../common/FileReader.h"
#include "../common/FlagSet.h"
#include "../common/mptFileIO.h"
#include "../common/mptIO.h"
#include "../common/mptRandom.h"
#include "../common/mptStringBuffer.h"
#include "../common/mptTime.h"
#include "../common/Profiler.h"
#include "../common/serialization_utils.h"
#include "../common/version.h"

#include "../misc/mptCPU.h"
#include "../misc/mptLibrary.h"
#include "../misc/mptMutex.h"
#include "../misc/mptOS.h"
#include "../misc/mptWine.h"



#include <algorithm>
#include <array>
#include <atomic>
#if MPT_CXX_AT_LEAST(20)
#include <bit>
#endif
#include <bitset>
#include <chrono>
#include <exception>
#include <fstream>
#include <iomanip>
#include <ios>
#include <istream>
#include <iterator>
#include <limits>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <optional>
#include <ostream>
#include <random>
#include <set>
#include <sstream>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <thread>
#include <type_traits>
#include <utility>
#include <variant>
#include <vector>
#if MPT_CXX_AT_LEAST(20)
#include <version>
#endif


#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <ctime>


#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#endif // MPT_BUILD_ENABLE_PCH
