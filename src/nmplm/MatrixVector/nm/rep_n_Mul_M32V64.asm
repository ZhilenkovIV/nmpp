//------------------------------------------------------------------------
//
//  $Workfile:: mtrMul_MxxV64.as $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/01/12 14:05:15 $
//
//! \if file_doc
//!
//! \file   mtrMul_MxxV64.asm
//! \author ������ �������
//! \brief  ��������� ������� �� ������.
//!
//! \endif
//!
//------------------------------------------------------------------------
import from macros.mlb;

extern _nmppsTmpBuffer64_G_: long;
extern _nmppsTmpBuffer64_L_: long;
const GTmpLong1=_nmppsTmpBuffer64_G_;
const LTmpLong1=_nmppsTmpBuffer64_L_;
 	


// Warining: nSize of this macros must be equal to 16!
// xx=64 bit => Nwfifo=1
// xx=32 bit => Nwfifo=2
// xx=16 bit => Nwfifo=4
// xx=08 bit => Nwfifo=8
// Ndata = height of block of matrix = [1,2,3...31]
 	

macro MUL_MxxV64_REP(Ndata,Nwfifo)
	
	own Next_Mul_MxxV64_repN:label;
	own End_Mul_MxxV64_repN:label;

	if =0 delayed goto End_Mul_MxxV64_repN with gr7--;
		rep Nwfifo wfifo = [ar4++gr4];
		rep Ndata  data  = [ar0++gr0],ftw with vsum ,data,0;
	
	<Next_Mul_MxxV64_repN>
	//WTW_REG(gr3);
	if <>0 delayed skip gr5 with gr7--;	
		rep Nwfifo wfifo = [ar4++gr4],wtw;
		ar0 = ar1+gr1 with gr1+=gr2 noflags;
		rep Ndata   data = [ar0++gr0],ftw with vsum ,data,afifo;

	<End_Mul_MxxV64_repN>
	delayed return;
		rep Ndata [ar6++gr6] = afifo;
		gr5 = ar5;	// pop ar5,gr5
		wtw;
	nul;
	nul;
	nul;
	nul;
		
end MUL_MxxV64_REP;



macro REP_N_NUL_MxxV64(Nwfifo)
	own Mul_MxxV64_repN			:label;
	own Next_Mul_MxxV64_rep32	:label;
	own End_Mul_MxxV64_rep32	:label;
	own Next_Mul_MxxV64			:label;

	[LTmpLong1]=ar4	with gr1 = gr5>>5;
	nb1 = gr3;
	rep Nwfifo wfifo = [ar4++gr4],ftw;
	if =0 delayed goto Mul_MxxV64_repN;
		gr2=2;
	
	/////////////////////////////////////////////////////////////////////////////////////
	//  Multiplication 8,16,32,64-bit matrix with 32*nVal rows by 64-bit vector using rep32 instruction
	//  matrix height always is equal to 32
	//  (nHeight always assumed to be equal to 32)
	//
	//  INPUT REGISTERS: (ar0,gr0, ar4,gr4, ar6,gr6, gr2,gr3 )
	//	ar0-SrcMatrix
	//	gr0-SrcMatrix width in 32-bit words =[2,4,6.....]
	//  gr5-SrcMatrix height				=[0,1,2,....]
	//
	//	ar4-pSrcVec+gr4 (Two first longs of pSrcVec must be preloaded in shadow matrix and wfifo must be empty)
	//	gr4-pSrcVec reading step							in 32-bit words (mush be even)
	//	ar6-DstVecror
	//	gr6-pDstVec writing step							in 32-bit words (mush be even)
	//	
	//	gr2=2;
	//  gr3=nb1
	//	sb
	//

	ar3 = Next_Mul_MxxV64_rep32;
	push ar5,gr5	with gr5 >>=5;
					with gr7 = gr0>>1;
	<Next_Mul_MxxV64>
				  with gr1 = gr2 ;
		ar1 = ar0 with gr7--;
		//WTW_REG(gr3);
		rep Nwfifo wfifo = [ar4++gr4],wtw;
		if =0 delayed goto End_Mul_MxxV64_rep32 with gr7--;
			rep 32 data = [ar0++gr0],ftw with vsum ,data,0;
			push ar0,gr0;
		//	[StartBlock]=ar0;
		<Next_Mul_MxxV64_rep32>
			rep Nwfifo wfifo = [ar4++gr4];
			ar0 = ar1+gr1 with gr1+=gr2 noflags;
		if <>0 delayed goto ar3 with gr7--;
			wtw;//WTW_REG(gr3);
			rep 32 data = [ar0++gr0],ftw with vsum ,data,afifo;
			nul;

		<End_Mul_MxxV64_rep32>
		pop ar0,gr0;
		ar4=[LTmpLong1] with gr5--;
	if <>0 delayed goto Next_Mul_MxxV64 with gr7=gr0>>1;
		rep Nwfifo wfifo =[ar4++gr4],ftw;
		rep 32 [ar6++gr6] = afifo;

	pop ar5,gr5;
 
	/////////////////////////////////////////////////////////////////////////////////////
	//  Multiplication 8,16,32,64-bit matrix with nVal<32 rows by 64-bit vector using rep32 instruction
	//
	//  INPUT REGISTERS: (ar0,gr0, ar4,gr4, ar6,gr6, gr2,gr3 )
	//	ar0-SrcMatrix
	//	gr0-SrcMatrix width in 32-bit words =[2,4,6.....]
	//  gr5-SrcMatrix height				=[0,1,2,....]
	//	ar4-pSrcVec+gr4 (Two first longs of pSrcVec must be preloaded in shadow matrix and wfifo must be empty)
	//	gr4-pSrcVec reading step							in 32-bit words (mush be even)
	//	ar6-DstVecror
	//	gr6-pDstVec writing step							in 32-bit words (mush be even)
	//	
	//	gr2=2;
	//  gr3=nb1
	//	sb
	//
	<Mul_MxxV64_repN>
	ar1 = ar0	with gr7 = gr5<<27;
	ar5 = gr5	with gr7 >>=27; 	//push ar5,gr5 (pop in macro)
	
	
	gr1 = 2-16;
	if =0 delayed return with gr7<<=4;
		gr1+=gr7;
		wtw;//WTW_REG(gr3);		
		nul;
		
	 
	
	delayed skip gr1 with gr7=gr0>>1;	
		gr1 = gr2  with gr7--;
		gr5 = -4;
	
	MUL_MxxV64_REP(1,Nwfifo);
	MUL_MxxV64_REP(2,Nwfifo);
	MUL_MxxV64_REP(3,Nwfifo);
	MUL_MxxV64_REP(4,Nwfifo);
	MUL_MxxV64_REP(5,Nwfifo);
	MUL_MxxV64_REP(6,Nwfifo);
	MUL_MxxV64_REP(7,Nwfifo);
	MUL_MxxV64_REP(8,Nwfifo);
	MUL_MxxV64_REP(9,Nwfifo);
	MUL_MxxV64_REP(10,Nwfifo);
	MUL_MxxV64_REP(11,Nwfifo);
	MUL_MxxV64_REP(12,Nwfifo);
	MUL_MxxV64_REP(13,Nwfifo);
	MUL_MxxV64_REP(14,Nwfifo);
	MUL_MxxV64_REP(15,Nwfifo);
	MUL_MxxV64_REP(16,Nwfifo);
	MUL_MxxV64_REP(17,Nwfifo);
	MUL_MxxV64_REP(18,Nwfifo);
	MUL_MxxV64_REP(19,Nwfifo);
	MUL_MxxV64_REP(20,Nwfifo);
	MUL_MxxV64_REP(21,Nwfifo);
	MUL_MxxV64_REP(22,Nwfifo);
	MUL_MxxV64_REP(23,Nwfifo);
	MUL_MxxV64_REP(24,Nwfifo);
	MUL_MxxV64_REP(25,Nwfifo);
	MUL_MxxV64_REP(26,Nwfifo);
	MUL_MxxV64_REP(27,Nwfifo);
	MUL_MxxV64_REP(28,Nwfifo);
	MUL_MxxV64_REP(29,Nwfifo);
	MUL_MxxV64_REP(30,Nwfifo);
	MUL_MxxV64_REP(31,Nwfifo);
end REP_N_NUL_MxxV64;

begin ".text_nmplm"
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Low level function of multyplying 8-bit matrix(SrcMatrix) by matrix(pSrcVec)
// with user-defined bit capacity and summary bit width of row = 64 bits.
// User-defined matrix(pSrcVec) and result product(pDstVec) are represented 
// as vectors of 64-bit packed words(long), partition of wich is defined by gr3(nb1) register.
//
// INPUT REGISTERS:
// ar0->SrcMatrix											:long Global[nHeight*Width/2]
// gr0= SrcMatrix nWidth in 32-bit words						:=[2,4,6...]
// gr5= SrcMatrix nHeight									:=[0,1,2,3..]
//
// ar4->pSrcVec											:long Local [nWidth*gr4/2]
// gr4= pSrcVec long to long reading step in 32-bit words :=[0,2,4,6....]
//
// ar6->pDstVec											:long Global[nHeight*gr6/2]
// gr6= pDstVec long to long writing step in 32-bit words	:=[0,2,4,6....]
//
// gr3= nb1
// COMMENTS: gr4 and gr6 registers are need for vector extraction and placing directly from/into matrixes
// 
// NOTE:  Registers : ar0,ar1,   ,ar3,ar4,ar5,ar6,   ,
//                   ,   ,gr1,gr2,   ,   ,   ,   ,gr7   will be changed after return !
// wtw must be on return
global  rep_n_Mul_M8V64:label;
<rep_n_Mul_M8V64>
	sb=02020202h;
	REP_N_NUL_MxxV64(8);
.wait;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Low level function of multyplying 16-bit matrix(SrcMatrix) by matrix(pSrcVec)
// with user-defined bit capacity and summary bit width of row = 64 bits.
// User-defined matrix(pSrcVec) and result product(pDstVec) are represented 
// as vectors of 64-bit packed words(long), partition of wich is defined by gr3(nb1) register.
//
// INPUT REGISTERS:
// ar0->SrcMatrix											:long Global[nHeight*Width/2]
// gr0= SrcMatrix nWidth in 32-bit words						:=[2,4,6...]
// gr5= SrcMatrix nHeight									:=[0,1,2,3..]
//
// ar4->pSrcVec											:long Local [nWidth*gr4/2]
// gr4= pSrcVec long to long reading step in 32-bit words :=[0,2,4,6....]
//
// ar6->pDstVec											:long Global[nHeight*gr6/2]
// gr6= pDstVec long to long writing step in 32-bit words	:=[0,2,4,6....]
//
// gr3= nb1
// COMMENTS: gr4 and gr6 registers are need for vector extraction and placing directly from/into matrixes
// 
// NOTE:  Registers : ar0,ar1,   ,ar3,ar4,ar5,ar6,   ,
//                   ,   ,gr1,gr2,   ,   ,   ,   ,gr7   will be changed after return !
// wtw must be on return
global  rep_n_Mul_M16V64:label;
<rep_n_Mul_M16V64>
	sb=00020002h;
	REP_N_NUL_MxxV64(4);
	
.wait;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Low level function of multyplying 32-bit matrix(SrcMatrix) by matrix(pSrcVec)
// with user-defined bit capacity and summary bit width of row = 64 bits.
// User-defined matrix(pSrcVec) and result product(pDstVec) are represented 
// as vectors of 64-bit packed words(long), partition of wich is defined by gr3(nb1) register.
//
// INPUT REGISTERS:
// ar0->SrcMatrix											:long Global[nHeight*Width/2]
// gr0= SrcMatrix nWidth in 32-bit words						:=[2,4,6....]
// gr5= SrcMatrix nHeight									:=[0,1,2,3..]
//
// ar4->pSrcVec											:long Local [nWidth*gr4/2]
// gr4= pSrcVec long to long reading step in 32-bit words :=[0,2,4,6....]
//
// ar6->pDstVec											:long Global[nHeight*gr6/2]
// gr6= pDstVec long to long writing step in 32-bit words	:=[0,2,4,6....]
//
// gr3= nb1
// COMMENTS: gr4 and gr6 registers are need for vector extraction and placing directly from/into matrixes
// 
// NOTE:  Registers : ar0,ar1,   ,ar3,ar4,ar5,ar6,   ,
//                   ,   ,gr1,gr2,   ,   ,   ,   ,gr7   will be changed after return !
// wtw must be on return
global  rep_n_Mul_M32V64:label;
<rep_n_Mul_M32V64>
	sb=2;
	REP_N_NUL_MxxV64(2);
.wait;


end ".text_nmplm"; 
