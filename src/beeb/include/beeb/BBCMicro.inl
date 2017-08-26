//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// Changing these flags should have no side effects visible from
// inside the emulator.

#define ENAME BBCMicroDebugFlag
EBEGIN()
EPNV(TeletextDebug,1<<0)

#if !BBCMICRO_FINER_TELETEXT
EPNV(TeletextInterlace,1<<1)
#endif

EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define ENAME BBCMicroLEDFlag
EBEGIN()
EPNV(CapsLock,1<<0)
EPNV(ShiftLock,1<<1)

// For i<=0<NUM_DRIVES, drive i's bit is Drive0<<i. 
EPNV(Drive0,1<<16)
EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define ENAME BBCMicroType
EBEGIN()
EPN(B)
EPN(BPlus)
EPN(Master)
EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define ENAME BBCMicroTraceFlag
EBEGIN()
EPNV(6845VSync,1<<0)
EPNV(6845Scanlines,1<<1)
EPNV(RTC,1<<2)
EPNV(1770,1<<3)
EPNV(SystemVIA,1<<4)
EPNV(UserVIA,1<<5)
EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define ENAME BBCMicroHackFlag
EBEGIN()
EPNV(Paste,1<<0)
EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// Non-intrusive hack flags don't affect replay playback.

#define ENAME BBCMicroNonIntrusiveHackFlag
EBEGIN()
EPNV(CopyOSWRCH,1<<0)
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

#define ENAME DiscDriveType
EBEGIN()
//EPN(90mm)
EPN(133mm)
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
