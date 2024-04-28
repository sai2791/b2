// The IRQ/NMI flags for host and parasite could be separate, but they aren't. No danger of running out just yet.

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define ENAME BBCMicroIRQDevice
EBEGIN()
EPNV(SystemVIA, 1 << 0)
EPNV(UserVIA, 1 << 1)
EPNV(HostTube, 1 << 2)
EPNV(ParasiteTube, 1 << 3)
EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

#define ENAME BBCMicroNMIDevice
EBEGIN()
EPNV(1770, 1 << 0)
EPNV(ParasiteTube, 1 << 1)
EEND()
#undef ENAME

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
