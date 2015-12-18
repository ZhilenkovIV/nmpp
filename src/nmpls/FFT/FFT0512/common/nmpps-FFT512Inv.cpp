#include "fft.h"
#include "time.h"
#include "malloc32.h"






extern "C" {
	#include "fft2.h"
	#include "rpc-host.h"	

	void nmppsFFT512Inv(nm32sc* src, nm32sc* dst, NmppsFFTSpec* spec)
	{
	#ifdef RPC
		int ret;	
		int size=512;
		int k=8;
		struct aura_buffer *iobuf_src = aura_buffer_request(n, size*k);	
		struct aura_buffer *iobuf_dst = aura_buffer_request(n, size*k);	
		memcpy(iobuf_src->data,src,size*k);	
		struct aura_buffer *retbuf; 
		ret = aura_call(n, "nmppsFFT512Inv", &retbuf,  iobuf_src, iobuf_dst, spec); 
		if (ret != 0) {
			slog(0, SLOG_ERROR, "call nmppsFFT512Inv  failed, reason: %d\n", ret);
			BUG(n, "Call nmppsFFT512Inv failed!"); 
		}
		memcpy(dst,iobuf_dst->data,size*k);
		aura_buffer_release(n, iobuf_dst); 
		aura_buffer_release(n, iobuf_src); 
		aura_buffer_release(n, retbuf); 
		slog(0, SLOG_INFO, "ARM: Call nmppsFFT512Inv -ok"); 
	#else 
		FFT_Inv512(src, dst, spec->buffer[0], spec->buffer[1], spec->shift[0], spec->shift[1] );
	#endif
	}

	int nmppsFFT512InvInitAllocCustom(  NmppsFFTSpec** specFFT, Malloc32Func* allocate, Free32Func* free, int settings)
	{
		NmppsFFTSpec* spec=(NmppsFFTSpec*)malloc(sizeof(NmppsFFTSpec));
		*specFFT = spec;
		if (spec==0) return -1;
		spec->buffer[0]=allocate(512*2*3);
		spec->buffer[1]=allocate(512*2*3);
		spec->buffer[2]=0;
		spec->buffer[3]=0;
		spec->shift [0]=9;
		spec->shift [1]=-1;
		spec->free=free;
		if (spec->buffer[0]==0) return -1;
		if (spec->buffer[1]==0) return -1;
		
		#ifndef RPC		
		FFT_Inv512Set7bit();
		#endif
		return 0;
	}




	int nmppsFFT512InvInitAlloc( NmppsFFTSpec** spec, void* src, void* dst, int settings)
	{
#ifdef RPC
		struct aura_buffer *iobuf_src = aura_buffer_request(n, 512*8);	
		struct aura_buffer *iobuf_dst = aura_buffer_request(n, 512*8);	
		struct aura_buffer *retbuf; 
		int ret =  aura_call(n, "nmppsFFT512InvInitAlloc", &retbuf,  iobuf_src, iobuf_dst, settings); 
		if (ret != 0) {
			slog(0, SLOG_ERROR, "call failed, reason: %d\n", ret);
			BUG(n, "Call nmppsFFT512InvInitAlloc failed!"); 
		}
		*spec = (NmppsFFTSpec*) aura_buffer_get_u32(retbuf);
		ret   = aura_buffer_get_u32(retbuf);
		aura_buffer_release(n, iobuf_src); 
		aura_buffer_release(n, iobuf_dst); 
		aura_buffer_release(n, retbuf); 
		slog(0, SLOG_INFO, "ARM: Call nmppsFFT512InvInitAlloc -ok"); 
		return ret;
#else
		int ret;
		if (settings&NMPP_OPTIMIZE_DISABLE){}
		else {
			fseq64 allocRoute;
			ret=nmppsFFT512InvOptimize(src, dst, &allocRoute);
			nmppsMallocSetRouteMode(allocRoute); 
		}
		ret = nmppsFFT512InvInitAllocCustom(spec, nmppsMalloc32, nmppsFree, settings);
		return ret;
	#endif
	}
	int nmppsFFT512InvOptimize(void* src, void* dst, fseq64* allocOrder) 
	{
		unsigned heapIndx0;
		unsigned heapIndx1;
		fseq64   route;
		*allocOrder=0xFFFFFF00;
		clock_t t0,t1,bestTime=0x1000000;

		for(heapIndx0=0; heapIndx0<4; heapIndx0++){
			for(heapIndx1=0; heapIndx1<4; heapIndx1++){


				route =0xF00|(heapIndx1<<4)|(heapIndx0); 
				nmppsMallocSetRouteMode(route);
				NmppsFFTSpec* spec;
				if (nmppsFFT512InvInitAllocCustom(&spec, nmppsMalloc32, nmppsFree, NMPP_OPTIMIZE_DISABLE )==NMPP_OK){
					t0=clock();
					nmppsFFT512Inv((nm32sc*)src, (nm32sc*)dst, spec);
					t1=clock();

					if (bestTime>t1-t0){
						bestTime=t1-t0;
						nmppsMallocGetHistory(allocOrder,2);
					}
				}
				nmppsMallocSpec.status=0;
				nmppsFFTFree(spec);
			}
		}
		if (bestTime<0x1000000)	return NMPP_OK;
		else					return NMPP_ERROR;
	}

};
