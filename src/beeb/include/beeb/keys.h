#ifndef HEADER_687498503073434D86BE53322F578658
#define HEADER_687498503073434D86BE53322F578658

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

/* Workaround for X.h crap. */
#ifdef None
#undef None
#endif

#include <shared/enum_decl.h>
#include "keys.inl"
#include <shared/enum_end.h>

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

int IsNumericKeypadKey(BeebKey beeb_key);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#endif
