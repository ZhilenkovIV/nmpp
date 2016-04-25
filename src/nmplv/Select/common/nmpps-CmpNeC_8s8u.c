#include "nmplv.h"
#include "malloc32.h"
int nmppsCmpNeC_8s8u (nm8s* src,  int8b  nCmpVal, nm8u* dst,  int size)
{
	Tmp2BuffSpec spec;
	
	spec.buffer0=nmppsMalloc_8s(size);
		
	if (nmppsMallocSuccess()){
		nmppsCmpNeC_8s  ((nm8s*)src,nCmpVal,(nm8s*)spec.buffer0,size);
		nmppsSubCRev_8s ((nm8s*)spec.buffer0,0,(nm8s*)dst,size);
	}
	
	nmppsFree(spec.buffer0);
	
	return 0;
}


