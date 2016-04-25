//------------------------------------------------------------------------
//
//  $Workfile:: Mul_VxxVxx.cp $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:15 $
//
//! \if file_doc
//!
//! \file   Mul_VxxVxx.cpp
//! \author ������ �������
//! \brief  ������� ��������� ��� ��������.
//!
//! \endif
//!
//------------------------------------------------------------------------

#include "nmpp.h"


//////////////////////////////////////////////////////////////////////////////////////
// Vector multiplication
//////////////////////////////////////////////////////////////////////////////////////
void nmppsDotProd_64s64s(
	nm64s*	srcVec0,	//Input0 buffer		:long Local [Size].
	nm64s*	srcVec1,	//Input1 buffer		:long Global[Size].
	int		size,		//Size of input vec
	int64b*	dst			//Output buffer		:long Any
	)
{

	int i;
	*dst=0;
	for (i=0; i<size; i++)
		*dst += ((nm64s)srcVec0[i])*((nm64s)srcVec1[i]);

}

//////////////////////////////////////////////////////////////////////////////////////
void nmppsDotProd_32s64s(
	nm32s*	srcVec0,	//Input0 buffer		:long Local [Size].
	nm64s*	srcVec1,	//Input1 buffer		:long Global[Size].
	int		size,		//Size of input vec
	int64b*	dst			//Output buffer		:long Any
	)
{
	int i;
	*dst = 0;
	for (i=0; i<size; i++)
		*dst += ((nm64s)srcVec0[i])*((nm64s)srcVec1[i]);

}

//////////////////////////////////////////////////////////////////////////////////////
void nmppsDotProd_16s64s(
	nm16s*	srcVec0,	//Input0 buffer		:long Local [Size].
	nm64s*	srcVec1,	//Input1 buffer		:long Global[Size].
	int		size,		//Size of input vec
	int64b*	dst			//Output buffer		:long Any
	)
{
	int i;
	*dst = 0;
	for (i=0; i<size; i++)
		*dst += ((nm64s)srcVec0[i])*((nm64s)srcVec1[i]);
}

//////////////////////////////////////////////////////////////////////////////////////
void nmppsDotProd_8s64s(
	nm8s*	srcVec0,	//Input0 buffer		:long Local [Size].
	nm64s*	srcVec1,	//Input1 buffer		:long Global[Size].
	int		size,		//Size of input vec
	int64b*	dst			//Output buffer		:long Any
	)
{
	int i;
	*dst = 0;
	for (i=0; i<size; i++)
		*dst += ((nm64s)srcVec0[i])*((nm64s)srcVec1[i]);

}
