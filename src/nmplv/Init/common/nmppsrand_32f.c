//------------------------------------------------------------------------
//
//  $Workfile:: InitRand.cp $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:02 $
//
//! \if file_doc
//!
//! \file   InitRand.cpp
//! \author ������ �������
//! \brief  ������� ������������� � ����������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#include "nmtype.h"
////////////////////////////////////////////////////////////////////////////
//  Random initalization of 32-bit buffer

 
//! 
//! \perfinclude _nmppsRandUniform__FPUiiUi_.html
//! 


static long long				Randomize=-1;
////////////////////////////////////////////////////////////////////////////
//  Random initialization of 64-bit Buffer
void nmppsRand_32f(
		nm32f*			pDstVec,		// array									:int Global [SizeInt]
		int				nSize, 		// nSize of Source array in 64-bit elements	:nSize=    [0,1,2,3,4...]
		float low,
		float hi
		)
{
	//__int64 Rand=Randomize&0xFFFFFFFFL;
	int i;
	unsigned int r,rounder;
	float k,temp;
	float* pointer_float;
	unsigned int* pointer;
	const float range = 1.0/(float)(0x100000000);
	float b = 0.5*(hi+low);
	if((low == 0)&(hi == 0)){return;}
	k = (hi-low)*range;
	for(i=0;i<nSize;i++)
	{
		unsigned long long R=Randomize<<63;
		Randomize>>=1;
		Randomize|=R;
		Randomize=1664525*Randomize+1013904223;
		r=Randomize;
		temp = k*r+b;
		pointer = (unsigned int*)&temp;
		rounder = *pointer;
		rounder>>=9;
		rounder<<=9;
		pointer_float = (float*)&rounder;
		pDstVec[i] = *pointer_float;
	}
	
	return;
	//Randomize=Rand;
}

