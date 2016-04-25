#include "rpc-host.h"
#include "nmtype.h"

int nmppsCmpLt_16s8um (nm16s* src1, nm16s* src2, nm8u* dst,  int size)
{
	int ret;	
	struct aura_buffer *iobuf_src1 = aura_buffer_request(n, size*2);	
	struct aura_buffer *iobuf_src2 = aura_buffer_request(n, size*2);	
	struct aura_buffer *iobuf_dst  = aura_buffer_request(n, size*1);	
	memcpy(iobuf_src1->data,src1,size*2);	
	memcpy(iobuf_src2->data,src2,size*2);	
	struct aura_buffer *retbuf; 
	ret = aura_call(n, "nmppsCmpLt_16s8um", &retbuf,  iobuf_src1,  iobuf_src2, iobuf_dst, size); 
	if (ret != 0) {
		BUG(n, "Call nmppsCmpLt_16s8um failed!"); 
	}
	memcpy(dst,iobuf_dst->data,size*1); 
	aura_buffer_release( iobuf_dst); 
	aura_buffer_release( iobuf_src2);
	aura_buffer_release( iobuf_src1);
	aura_buffer_release( retbuf); 
	slog(0, SLOG_INFO, "ARM: Call nmppsCmpLt_16s8um -ok"); 
	
	return 0;
}