#include "rpc-host.h"
#include "nmplv.h"
#include "malloc32.h"
#include "time.h"
int nmppsCmpLtC_8s (nm8s* pSrcVec,  int8b  nCmpVal, nm8s* pDstVec,  int nSize, Tmp2BuffSpec *pspec)
{
	#ifdef RPC
	RPC_HOST_PIPI("nmppsCmpLtC_8s",pSrcVec,nCmpVal,pDstVec,nSize,1);
	#else

	Tmp2BuffSpec s;
	Tmp2BuffSpec* spec=&s;
	
	spec->buffer0=nmppsMalloc_16s(nSize);
	spec->buffer1=nmppsMalloc_16s(nSize);
		
	if (nmppsMallocSuccess()){
		nmppsConvert_8s16s (pSrcVec, (nm16s*)spec->buffer0, nSize);
		nmppsCmpLtC_16s15b ((nm16s*)spec->buffer0,nCmpVal,(nm16s*)spec->buffer1,nSize);
		nmppsConvert_16s8s ((nm16s*)spec->buffer1,pDstVec,nSize);
	}
	
	nmppsFree(spec->buffer0);
	nmppsFree(spec->buffer1);
	
	#endif
	
	return 0;
}



int nmppsCmpLtC_8sAlloc  (nm8s* pSrcVec, nm8s* pDstVec,int nSize, Tmp2BuffSpec *spec)
{
	unsigned heapIndx0;
	unsigned heapIndx1;
	fseq64   testRoute;
	fseq64 	 bestRoute=0xFFFFFF00;
	clock_t t0,t1,bestTime=0x7FFFFFFF;
	if (spec->mode){
		for(heapIndx0=0; heapIndx0<4; heapIndx0++){
			for(heapIndx1=0; heapIndx1<4; heapIndx1++){
				testRoute =0xF0|(heapIndx1<<4)|(heapIndx0); 
				nmppsMallocSetRouteMode(testRoute);
				spec->buffer0=nmppsMalloc_16s(nSize);
				spec->buffer1=nmppsMalloc_16s(nSize);
				if (nmppsMallocSuccess()){
					t0=clock();
					nmppsCmpLtC_8s(pSrcVec,0,pDstVec, nSize,spec);
					t1=clock();
					if (bestTime>t1-t0){
						bestTime=t1-t0;
						nmppsMallocGetHistory(&spec->route,2);
						//spec->optimized=1;
					}
				}
				else 
					nmppsMallocResetStatus();
				nmppsFree(spec->buffer0);
				nmppsFree(spec->buffer1);
			}
		}
	}
	if (spec->status )
	nmppsMallocSetRouteMode(spec->route);
	spec->buffer0=nmppsMalloc_16s(nSize);
	spec->buffer1=nmppsMalloc_16s(nSize);
	//spec->isAllocated=nmppsMallocSucces();
	return nmppsMallocStatus();
}

void nmppsCmpLtC_Free  (Tmp2BuffSpec *spec)
{
	nmppsFree(spec->buffer0);
	nmppsFree(spec->buffer1);
}



	/*
	void nmppsCmpLtC_16s     (nm16s* pSrcVec, int16b nCmpVal, nm16s* pDstVec, int nSize, Tmp2BuffSpec *spec);
	void nmppsCmpLtC_32s     (nm32s* pSrcVec, int32b nCmpVal, nm32s* pDstVec, int nSize, Tmp2BuffSpec *spec);
	void nmppsCmpLtC_64s     (nm64s* pSrcVec, int64b nCmpVal, nm64s* pDstVec, int nSize, Tmp2BuffSpec *spec);
	*/