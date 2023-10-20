//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define ENAME BBCMicroLEDFlag
EBEGIN()
EPNV(CapsLock, 1 << 0)
EPNV(ShiftLock, 1 << 1)

// For i<=0<NUM_DRIVES, drive i's bit is Drive0<<i.
EPNV(Drive0, 1 << 16)
EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define ENAME BBCMicroTraceFlag
EBEGIN()
EPNV(6845, 1 << 0)
EPNV(6845Scanlines, 1 << 1)
EPNV(6845ScanlinesSeparators, 1 << 2)
EPNV(RTC, 1 << 3)
EPNV(1770, 1 << 4)
EPNV(SystemVIA, 1 << 5)
EPNV(UserVIA, 1 << 6)
EPNV(VideoULA, 1 << 7)
EPNV(SN76489, 1 << 8)
EPNV(BeebLink, 1 << 9)
EPNV(SystemVIAExtra, 1 << 10)
EPNV(UserVIAExtra, 1 << 11)
EPNV(Tube, 1 << 12)
EPNV(ADC, 1 << 13)
EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define ENAME BBCMicroHackFlag
EBEGIN()
EPNV(Paste, 1 << 0)
EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define ENAME BBCMicroPasteState
EBEGIN()
// No pasting. Hack flags paste bit must be reset.
EPN(None)

// Wait for the fake keypress that hopefully prods OSRDCH into action.
EPN(Wait)

// Delete the fake keypress with a DELETE.
EPN(Delete)

// Paste the string.
EPN(Paste)
EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#if BBCMICRO_ENABLE_DISC_DRIVE_SOUND

// These are the samples that come with MAME.
//
// Should this enum go somewhere else??

#define ENAME DiscDriveSound
EBEGIN()
EPN(Seek2ms)
EPN(Seek6ms)
EPN(Seek12ms)
EPN(Seek20ms)
EPN(SpinEmpty)
EPN(SpinEnd)
EPN(SpinLoaded)
EPN(SpinStartEmpty)
EPN(SpinStartLoaded)
EPN(Step)
EPN(EndValue)
EEND()
#undef ENAME

#endif

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#if BBCMICRO_DEBUGGER
//#define ENAME BBCMicroDebugByteFlag
//EBEGIN()
//EPNV(BreakExecute,1<<0)
//EPNV(BreakRead,1<<1)
//EPNV(BreakWrite,1<<2)
//EEND()
#undef ENAME

#define ENAME BBCMicroStepType
EBEGIN()
EPN(None)
EPN(StepIn)
EPN(StepIntoIRQHandler)
EPN(Count)
EEND()
#undef ENAME

#endif

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define ENAME BBCMicroVIAID
EBEGIN()
EPN(SystemVIA)
EPN(UserVIA)
EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define ENAME BBCMicroCloneImpediment
EBEGIN()
EPNV(BeebLink, 1 << 0)
EPNV(Drive0, 1 << 24)
// ...up to DriveN, which is Drive0<<(NUM_DRIVES-1)
EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#if BBCMICRO_DEBUGGER
// 8-bit quantity.
#define ENAME BBCMicroByteDebugFlag
EBEGIN()
EPNV(BreakExecute, 1 << 0)
EPNV(TempBreakExecute, 1 << 1)
EPNV(BreakRead, 1 << 2)
EPNV(BreakWrite, 1 << 3)
EQPNV(AnyBreakReadMask, BBCMicroByteDebugFlag_BreakExecute | BBCMicroByteDebugFlag_TempBreakExecute | BBCMicroByteDebugFlag_BreakRead)
EQPNV(AnyBreakWriteMask, BBCMicroByteDebugFlag_BreakWrite)
EEND()
#undef ENAME
#endif

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define ENAME BBCMicroUpdateResultFlag
EBEGIN()
EPNV(AudioUnit, 1 << 0)
EPNV(VideoUnit, 1 << 1)
EPNV(Host, 1 << 2)
EPNV(Parasite, 1 << 3)
EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define ENAME BBCMicroInitFlag
EBEGIN()
// Set if the video ULA is in fact a Video NuLA.
EPNV(VideoNuLA, 1 << 0)

// Set if the ExtMem is present.
EPNV(ExtMem, 1 << 1)

// Set if the power-on brr... tone should sound when doing a power-on reset
// (this ended up here because it's convenient, not because it makes sense).
EPNV(PowerOnTone, 1 << 2)

// Set if the state is a clone: a simple value copy of an existing state,
// possibly itself a clone.
//
// Clones are simple copies, so the following apply:
//
// - the various ROM and RAM shared_ptr'd buffers refer to the same buffers as
//   the original state. They may be out of sync relative to the rest of the
//   hardware state!
// - any hardware Handler or Trace pointers (etc.) are not valid
//
// This means that a cloned state is kind of useless! They're there purely for
// the debugger to use for updating its UI without having to have each window
// take a lock (or have the debugger copy all of BBC memory).
//
// The potential discrepancy between RAM contents and hardware state doesn't
// matter; when the BBC is running, it's impossible to tell, and when it's
// stopped, the two are actually in sync.
//
// (Any actual modification to the BBCMicro state is done via BeebThread
// messages or with a BBCMicro pointer obtained from
// BeebThread::LockMutableBeeb.)
EPNV(Clone, 1 << 3)
EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
