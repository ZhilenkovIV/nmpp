#ifndef _CARITHMETIC_H_INCLUDED_
#define _CARITHMETIC_H_INCLUDED_

#include "nmtype.h"



	/**
	\defgroup nmppcDivC nmppcDivC
	\ingroup <cArithmetic>
	\brief
		\ru ������� ���� ����������� �����
		\en

	\~
	\param *pnSrcA
		\ru ��������� �� �������.
		\en
	\param *pnSrcB
		\ru ��������� �� ��������.
		\en
	\param *Dst
		\ru ��������� �� �������.
		\en
	*/
	//! \{	
void nmppcDivC(nm64sc *pnSrcA, nm64s *pnSrcB, nm64sc *Dst);
    //! \}

	/**
	\defgroup nmppcProdC nmppcProdC
	\ingroup cArithmetic
	\brief
		\ru ������������ ���� ����������� �����.
		\en

	\~
	\param *pnSrcA
		\ru ��������� �� ������ ���������.
		\en
	\param *pnSrcB
		\ru ��������� �� ������ ���������.
		\en
	\param *Dst
		\ru ��������� �� ������������.
		\en
	*/
//! \{	
void nmppcProdC(nm64sc *pnSrcA, nm64sc *pnSrcB, nm64sc *Dst);//ASM
//! \}

#endif
