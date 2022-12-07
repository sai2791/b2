#ifndef HEADER_068D76EBAC274785B70753E8DD2FB9B8 // -*- mode:c++ -*-
#define HEADER_068D76EBAC274785B70753E8DD2FB9B8

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#include <beeb/conf.h>

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// Number of vblank tick count records to keep. These are stored in a
// couple of places.
static const size_t NUM_VBLANK_RECORDS = 250;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#if BUILD_TYPE_Debug

#define ENABLE_IMGUI_DEMO 1
#define ENABLE_DEBUG_MENU 1
#define ENABLE_IMGUI_TEST 1

#elif BUILD_TYPE_RelWithDebInfo

#define ENABLE_IMGUI_DEMO 1
#define ENABLE_DEBUG_MENU 1
#define ENABLE_IMGUI_TEST 1

#elif BUILD_TYPE_Final

#define ENABLE_IMGUI_DEMO 0
#define ENABLE_DEBUG_MENU 0
#define ENABLE_IMGUI_TEST 0

#else
#error unexpected build type
#endif

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// these aren't meaningfully tweakable - they're just used in more
// than one place.

#define AUDIO_FORMAT (AUDIO_F32SYS)
#define AUDIO_NUM_CHANNELS (1)

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

static const float MAX_DB = 0.f;
static const float MIN_DB = -72.f;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

// Number of frames to render when creating an ordinary thumbnail. The
// first may be a partial one, and the second will be complete.
static const size_t NUM_THUMBNAIL_RENDER_FRAMES = 2;

// Number of frames to render when creating a thumbnail starting from
// a cold boot. Takes longer due to memory clear, ROM init, etc.
static const size_t NUM_BOOTUP_THUMBNAIL_RENDER_FRAMES = 11;

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#endif
