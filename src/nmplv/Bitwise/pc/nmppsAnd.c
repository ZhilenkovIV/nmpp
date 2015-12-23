#include "rpc-host.h"
#include "nmpp.h"

///////////////////////////////////////////////////////////////////////////////
// Dst[i] = Src1[i] & Src2[i];
void nmppsAnd_64u(
	nm64u*	Src1,		// Input Buffer
	nm64u*	Src2,		// Input Buffer
	nm64u*	Dst,		// Output Buffer
	int		nSize		// size of input buffer in 64 bit elements. nSize={1,2,..,n}
	)
{
	#ifdef RPC
	RPC_HOST_PPPI("nmppsAnd_64u",Src1,Src2,Dst,nSize,8);
	#else

	int i;
	for (i=0; i<nSize; i++)
		Dst[i] = Src1[i] & Src2[i];

	#endif
}

void nmppsAnd_32u(
	nm32u*	Src1,		// Input Buffer
	nm32u*	Src2,		// Input Buffer
	nm32u*	Dst,		// Output Buffer
	int		nSize		// size of input buffer in 64 bit elements. nSize={1,2,..,n}
	)
{
	#ifdef RPC
	RPC_HOST_PPPI("nmppsAnd_32u",Src1,Src2,Dst,nSize,4);
	#else

	int i;
	for (i=0; i<nSize; i++)
		Dst[i] = Src1[i] & Src2[i];

	#endif
}


void nmppsAnd_16u(
	nm16u*	Src1,		// Input Buffer
	nm16u*	Src2,		// Input Buffer
	nm16u*	Dst,		// Output Buffer
	int		nSize		// size of input buffer in 64 bit elements. nSize={1,2,..,n}
	)
{
	#ifdef RPC
	RPC_HOST_PPPI("nmppsAnd_16u",Src1,Src2,Dst,nSize,2);
	#else

	int i;
	for (i=0; i<nSize; i++)
		Dst[i] = Src1[i] & Src2[i];

	#endif
}


void nmppsAnd_8u(
	nm8u*	Src1,		// Input Buffer
	nm8u*	Src2,		// Input Buffer
	nm8u*	Dst,	// Output Buffer
	int		nSize		// size of input buffer in 64 bit elements. nSize={1,2,..,n}
	)
{
	#ifdef RPC
	RPC_HOST_PPPI("nmppsAnd_8u",Src1,Src2,Dst,nSize,1);
	#else

	int i;
	for (i=0; i<nSize; i++)
		Dst[i] = Src1[i] & Src2[i];

	#endif
}


