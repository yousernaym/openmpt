/*
 * SoundDevicePulseSimple.h
 * ------------------------
 * Purpose: PulseAudio-Simple sound device driver class.
 * Notes  : (currently none)
 * Authors: OpenMPT Devs
 * The OpenMPT source code is released under the BSD license. Read LICENSE for more details.
 */


#pragma once

#include "openmpt/all/BuildSettings.hpp"

#include "SoundDeviceBase.h"
#include "SoundDeviceUtilities.h"

#if defined(MPT_WITH_PULSEAUDIO) && defined(MPT_WITH_PULSEAUDIOSIMPLE)
#include <pulse/pulseaudio.h>
#include <pulse/simple.h>
#endif // MPT_WITH_PULSEAUDIO && MPT_WITH_PULSEAUDIOSIMPLE


OPENMPT_NAMESPACE_BEGIN


namespace SoundDevice {


#if defined(MPT_WITH_PULSEAUDIO) && defined(MPT_WITH_PULSEAUDIOSIMPLE)


class PulseaudioSimple
	: public ThreadBase
{
private:
	static mpt::ustring PulseErrorString(int error);
public:
	static std::unique_ptr<SoundDevice::BackendInitializer> BackendInitializer() { return std::make_unique< SoundDevice::BackendInitializer>(); }
	static std::vector<SoundDevice::Info> EnumerateDevices(ILogger &logger, SoundDevice::SysInfo sysInfo);
public:
	PulseaudioSimple(ILogger &logger, SoundDevice::Info info, SoundDevice::SysInfo sysInfo);
	SoundDevice::Caps InternalGetDeviceCaps();
	SoundDevice::DynamicCaps GetDeviceDynamicCaps(const std::vector<uint32> &baseSampleRates);
	bool InternalIsOpen() const;
	bool InternalOpen();
	void InternalStartFromSoundThread();
	void InternalFillAudioBuffer();
	void InternalWaitFromSoundThread();
	SoundDevice::BufferAttributes InternalGetEffectiveBufferAttributes() const;
	SoundDevice::Statistics GetStatistics() const;
	void InternalStopFromSoundThread();
	bool InternalClose();
	~PulseaudioSimple();
private:
	pa_simple * m_PA_SimpleOutput;
	SoundDevice::BufferAttributes m_EffectiveBufferAttributes;
	std::vector<float32> m_OutputBuffer;
	std::atomic<uint32> m_StatisticLastLatencyFrames;
};


#endif // MPT_WITH_PULSEAUDIO && MPT_WITH_PULSEAUDIOSIMPLE


} // namespace SoundDevice


OPENMPT_NAMESPACE_END
