#include <nmtype.h>
#include <malloc.h>
//#include <stdio.h>
#include "fft_32fc.h"
#include "nmpp.h"

int main()
{
	int i, tm;
	nm32fcr *src, *dst;
	// best config (tm = 592, src - malloc, dst - malloc1)
	src = (nm32fcr *)malloc(64 * sizeof(nm32fcr));
	dst = (nm32fcr *)malloc(64 * sizeof(nm32fcr));
	for(i = 0; i < 64; i++) {
		src[i].im = 0;
		src[i].re = i;
		dst[i].im = 0;
		dst[i].re = 0;
	}
	NmppsFFTSpec_32fc *rat;
	tm = nmppsFFT64FwdInitAlloc_32fc(&rat);
	if(tm == 123) {
		return 123;
	}
	nmppsFFT64Fwd_32fc(src, dst, rat);
	tm = nmppsFFTFree_32fc(rat);
	unsigned int crc1 = 0;
	unsigned int crc2 = 0;
	nmppsCrcAcc_32f((nm32f *)dst, 11, 64*2, &crc1);
	tm = nmppsFFTFwdInitAlloc_32fc(&rat, 6);
	if(tm == 123) {
		return 123;
	}
	tm = nmppsFFTFwd_32fc(src, dst, rat);
	tm = nmppsFFTFree_32fc(rat);
	nmppsCrcAcc_32f((nm32f *)dst, 11, 64*2, &crc2);
	// printf("%d\n", crc1>>2);
	// printf("%d\n", crc2>>2);
	return (crc1+crc2)>>2;
}