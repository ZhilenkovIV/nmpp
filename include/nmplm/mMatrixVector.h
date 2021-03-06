//------------------------------------------------------------------------
//
//  $Workfile:: mMatrixVec $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/01/12 14:03:24 $
//
//! \if file_doc
//!
//! \file   mtrArithm.h
//! \author ������ �������
//! \brief  ������ �������� ��� ���������� �������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#ifndef _MMATRIXVECTOR_H_INCLUDED_
#define _MMATRIXVECTOR_H_INCLUDED_

#ifdef __cplusplus
		extern "C" {
#endif

//*****************************************************************************

	/*
    *
    * \if Russian
    *     \defgroup mMatrixVector ��������-��������� ��������
    * \endif
    * \if English
    *     \defgroup mMatrixVector Vector-mtr operations.
    * \endif
    * \ingroup mtr
	*/

//*****************************************************************************

    /**
    \defgroup nmppmMul_mm nmppmMul_mm
    \ingroup mMatrixVector
    \brief
        \ru ��������� ������� �� �������. 
        \en Matrix by mtr multiplication. 
		\~
    \param	pSrcMtr1		
        \ru �������� �������. 
        \en Source mtr. 
		\~
    \param	pSrcMtr2		
        \ru �������-���������. 
        \en Multiplier mtr. 
		\~
    \param	nHeight1		
        \ru ����� ����� �������� �������. 
        \en Row count in source mtr. 
		\~
    \param	nWidth1		
        \ru ����� �������� �������� �������. 
        \en Column count in source mtr. 
		\~
    \param	nWidth2		
        \ru ����� �������� ������� ���������. 
        \en Column count in multiplier mtr. 
		\~
    \retval	pDstMtr		
        \ru �������������� �������. 
        \en The result mtr. 
		\~
    \return \e void
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcMtr1 </param> <values> L G </values>
             <param> pSrcMtr2 </param> <values> L G </values>
             <param> pDstMtr </param> <values> L G </values>
             <param> nHeight1 </param> <values> 64 </values>
             <param> nWidth2 </param> <values> 64 </values>
             <param> nWidth1 </param> <values> 128 </values>
             <size> nWidth1*nHeight1*nWidth2 </size>
        </testperf>
        <testperf> 
             <param> pSrcMtr1 </param> <values> G </values>
             <param> pSrcMtr2 </param> <values> L </values>
             <param> pDstMtr </param> <values> G </values>
             <param> nHeight1 </param> <values> 64 </values>
             <param> nWidth2 </param> <values> 64 </values>
             <param> nWidth1 </param> <values> 8 32 128 </values>
             <size> nWidth1*nHeight1*nWidth2 </size>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppmMul_mm_8s8s  ( nm8s* pSrcMtr1,  int nHeight1, int nWidth1,  nm8s* pSrcMtr2,  nm8s*  pDstMtr, int nWidth2);
void nmppmMul_mm_8s16s ( nm8s* pSrcMtr1,  int nHeight1, int nWidth1,  nm16s* pSrcMtr2, nm16s* pDstMtr, int nWidth2);
void nmppmMul_mm_8s32s ( nm8s* pSrcMtr1,  int nHeight1, int nWidth1,  nm32s* pSrcMtr2, nm32s* pDstMtr, int nWidth2);
void nmppmMul_mm_8s64s ( nm8s* pSrcMtr1,  int nHeight1, int nWidth1,  nm64s* pSrcMtr2, nm64s* pDstMtr, int nWidth2);

void nmppmMul_mm_16s16s( nm16s* pSrcMtr1, int nHeight1, int nWidth1,  nm16s* pSrcMtr2, nm16s* pDstMtr, int nWidth2);
void nmppmMul_mm_16s32s( nm16s* pSrcMtr1, int nHeight1, int nWidth1,  nm32s* pSrcMtr2, nm32s* pDstMtr, int nWidth2);
void nmppmMul_mm_16s64s( nm16s* pSrcMtr1, int nHeight1, int nWidth1,  nm64s* pSrcMtr2, nm64s* pDstMtr, int nWidth2);

void nmppmMul_mm_32s32s( nm32s* pSrcMtr1, int nHeight1, int nWidth1,  nm32s* pSrcMtr2, nm32s* pDstMtr, int nWidth2);
void nmppmMul_mm_32s64s( nm32s* pSrcMtr1, int nHeight1, int nWidth1,  nm64s* pSrcMtr2, nm64s* pDstMtr, int nWidth2);

void nmppmMul_mm_colmajor_8s8s  (const nm8s* pSrcMtr1,  int nHeight1, int nWidth1, const nm8s* pSrcMtr2,  nm8s*  pDstMtr, int nWidth2);
void nmppmMul_mm_colmajor_8s16s (const nm8s* pSrcMtr1,  int nHeight1, int nWidth1, const nm16s* pSrcMtr2, nm16s* pDstMtr, int nWidth2);
void nmppmMul_mm_colmajor_8s32s (const nm8s* pSrcMtr1,  int nHeight1, int nWidth1, const nm32s* pSrcMtr2, nm32s* pDstMtr, int nWidth2);
void nmppmMul_mm_colmajor_8s64s (const nm8s* pSrcMtr1,  int nHeight1, int nWidth1, const nm64s* pSrcMtr2, nm64s* pDstMtr, int nWidth2);
                                                                                   
void nmppmMul_mm_colmajor_16s16s(const nm16s* pSrcMtr1, int nHeight1, int nWidth1, const nm16s* pSrcMtr2, nm16s* pDstMtr, int nWidth2);
void nmppmMul_mm_colmajor_16s32s(const nm16s* pSrcMtr1, int nHeight1, int nWidth1, const nm32s* pSrcMtr2, nm32s* pDstMtr, int nWidth2);
void nmppmMul_mm_colmajor_16s64s(const nm16s* pSrcMtr1, int nHeight1, int nWidth1, const nm64s* pSrcMtr2, nm64s* pDstMtr, int nWidth2);
                                                                                   
void nmppmMul_mm_colmajor_32s32s(const nm32s* pSrcMtr1, int nHeight1, int nWidth1, const nm32s* pSrcMtr2, nm32s* pDstMtr, int nWidth2);
void nmppmMul_mm_colmajor_32s64s(const nm32s* pSrcMtr1, int nHeight1, int nWidth1, const nm64s* pSrcMtr2, nm64s* pDstMtr, int nWidth2);

    //! \}


	//*****************************************************************************

    /**
    \defgroup nmppmMul_mv_ nmppmMul_mv_
    \ingroup mMatrixVector
    \brief
        \ru ��������� ������� �� ������. 
        \en Matrix by vec multiplication. 
		\~
    \param	pSrcMtr		
        \ru �������� �������. 
        \en Source mtr. 
		\~
    \param	pSrcVec		
        \ru ������-���������. 
        \en Multiplier vec. 
		\~
    \param	pSrcVec8	
        \ru ������-��������� ����������� 8. 
        \en Multiplier vec of 8 elements. 
		\~
    \param	nHeight		
        \ru ����� ����� �������� �������. 
        \en Row count in source mtr. 
		\~
    \param	nWidth		
        \ru ����� �������� �������� �������. 
        \en Column count in source mtr. 
		\~
    \retval	pDstVec		
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void
    
    \par
    \xmlonly
        <testperf>
          <init> int nWidth=8; </init>
          <param> pSrcMtr </param> <values> L G </values>
          <param> pSrcVec </param> <values> L G </values>
          <param> pDstVec </param> <values> L G </values>
          <param> nHeight </param> <values> 128 </values>
          <param> nWidth </param> <values> 256 </values>
          <size> nHeight*nWidth </size>
        </testperf>
        <testperf>
          <init> int nWidth=8; </init>
          <param> pSrcMtr </param> <values> G </values>
          <param> pSrcVec </param> <values> L </values>
          <param> pDstVec </param> <values> G </values>
          <param> nHeight </param> <values> 128 </values>
          <param> nWidth </param> <values> 16 128 256 </values>
          <size> nHeight*nWidth </size>
        </testperf>

    \endxmlonly
    */
    //! \{
void nmppmMul_mv_8s64s( nm8s* pSrcMtr,  nm64s* pSrcVec, nm64s* pDstVec, int nHeight, int nWidth);
void nmppmMul_mv_16s64s( nm16s* pSrcMtr,  nm64s* pSrcVec, nm64s* pDstVec, int nHeight, int nWidth);
void nmppmMul_mv_32s64s( nm32s* pSrcMtr,  nm64s* pSrcVec, nm64s* pDstVec, int nHeight, int nWidth);
void nmppmMul_mv_8s16s_8xH( v8nm8s* pSrcMtr,  v8nm16s* pSrcVec, nm16s* pDstVec, int nHeight);
void nmppmMul_mv_16s16s_8xH( v8nm16s* pSrcMtr,  v8nm16s* pSrcVec, nm16s* pDstVec, int nHeight);

void nmppmMul_mv_colmajor_8s64s (const nm8s*  pSrcMtr,const  nm64s* pSrcVec, nm64s* pDstVec, int nHeight, int nWidth);
void nmppmMul_mv_colmajor_16s64s(const nm16s* pSrcMtr,const  nm64s* pSrcVec, nm64s* pDstVec, int nHeight, int nWidth);
void nmppmMul_mv_colmajor_32s64s(const nm32s* pSrcMtr,const  nm64s* pSrcVec, nm64s* pDstVec, int nHeight, int nWidth);

    //! \}

//*****************************************************************************

    /**
    \defgroup nmppmMul_mv__AddC nmppmMul_mv__AddC
    \ingroup mMatrixVector

 	\~
   \brief
        \ru ��������� ������� �� ������ � ����������� ���������. 
        \en Matrix by vec multiplication with addition of ant . 
		\~
    \param	pSrcMtr		
        \ru �������� �������. 
        \en Source mtr. 
		\~
    \param	pSrcVec		
        \ru ������-���������. 
        \en Multiplier vec. 
		\~
    \param	pSrcVec	
        \ru ������-��������� ����������� 2. 
        \en Multiplier vec of 2 elements. 
		\~
    \param	nAddVal	
        \ru ���������. 
        \en The ant. 
		\~
    \param	nHeight		
        \ru ����� ����� �������� �������. nHeight = [0, 2, 4, ...]. 
        \en Row count in source mtr. nHeight = [0, 2, 4, ...]. 
		\~
    \param	nWidth		
        \ru ����� �������� �������� �������. 
        \en Column count in source mtr. 
		\~
    \retval	pDstVec		
        \ru �������������� ������. 
        \en The result vec. 
		\~
    \return \e void
    
    \par
    \xmlonly
        <testperf>
          <init> int nWidth=8; </init>
          <param> pSrcMtr </param> <values> L G </values>
          <param> pnSrcVec </param> <values> L G </values>
          <param> pDstVec </param> <values> L G </values>
          <param> nAddVal </param> <values> -1 </values>
          <param> nHeight </param> <values> 128 </values>
          <size> nHeight </size>
        </testperf>
        <testperf>
          <init> int nWidth=8; </init>
          <param> pSrcMtr </param> <values> G </values>
          <param> pnSrcVec </param> <values> L </values>
          <param> pDstVec </param> <values> G </values>
          <param> nAddVal </param> <values> -1 </values>
          <param> nHeight </param> <values> 32 128 1024 </values>
          <size> nHeight </size>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppmMul_mv__AddC(v2nm32s* pSrcMtr, v2nm32s* pnSrcVec, int nAddVal, nm32s* pDstVec, int nHeight);
    //! \}


//*****************************************************************************

    /**
    \defgroup MTR_ProdUnitV MTR_ProdUnitV
    \ingroup mMatrixVector
    \brief
        \ru ��������� ������� �� ��������� ������. 
        \en Multiplication of a mtr by a unit vec. 
    
		\~
    
	\f[
        pDstVec(i) = \sum_{j=0}^{w-1} pSrcMtr(i, j)
    \f]
    
    \ru ������ ������� ������������ ������������ �������� �������.
        ������ �������, ��� ������� ������� ���������� ������ ������� 
        ����������� � �� ��������. 
    \en This function is equivalent to summation of mtr columns.
        Widths of a mtr for which this function is implemented 
        are indicated in the mtr name. 

		\~
		\~
    \param	pSrcMtr		
        \ru �������. 
        \en The mtr. 
		\~
    \param	nHeight		
        \ru ����� ����� �������. nHeight=[128,256,....]
        \en Row count in mtr. nHeight=[128,256,....]

		\~
    \retval	pDstVec		
        \ru �������������� ������. 
        \en The result vec. 

		\~
    \return \e void

    \par
    \xmlonly
      <testperf>
        <param> pSrcMtr </param> <values> L G </values>
        <param> pDstVec </param> <values> L G </values>
        <param> nHeight </param> <values> 128 </values>
      </testperf>

    \endxmlonly
    */
    //! \{    
void MTR_ProdUnitV_16s_4xH ( v4nm16s* pSrcMtr, nm16s* pDstVec, int nHeight);
void MTR_ProdUnitV_16s_16xH( v16nm8s* pSrcMtr, nm16s* pDstVec, int nHeight);
    //! \}

//*****************************************************************************

    /**
	\internal
    \defgroup MTR_MulC_AddVsVc MTR_MulC_AddVsVc
    \ingroup mMatrixVector
    \brief
        \ru ��������� ������� �� ��������� � ������������� ������� ������ � �������-�������. 
        \en Multiplication of a mtr by const with summation of vec-string and vec-column. 
    
		\~
    
	\f[
        pDstVec(i) = \sum_{j=0}^{w-1} pSrcMtr(i, j)
    \f]
    
  
    \~
    
    \par
    \xmlonly
        <testperf> 
             <param> pSrcMtr </param> <values> L G </values>
             <param> pDstMtr </param> <values> L G </values>
             <param> pSrcVecStr </param> <values> L G </values>
             <param> pSrcVecCol </param> <values> L G </values>
             <param> MulN </param> <values> 2 </values>
             <param> nHeight </param> <values> 128 </values>
             <param> nWidth </param> <values> 128 </values>
             <size> nHeight*nWidth </size>
        </testperf>
        <testperf> 
             <param> pSrcMtr </param> <values> L </values>
             <param> pDstMtr </param> <values> G </values>
             <param> pSrcVecStr </param> <values> G </values>
             <param> pSrcVecCol </param> <values> L </values>
             <param> MulN </param> <values> 2 </values>
             <param> nHeight </param> <values> 128 </values>
             <param> nWidth </param> <values> 8 32 128 </values>
             <size> nHeight*nWidth </size>
        </testperf>
    \endxmlonly
    *///--------------------------------------------------------------------
    //! \{
void MTR_MulC_AddVsVc(int MulN, nm32s* pSrcMtr, nm32s* pSrcVecStr, nm32s* pSrcVecCol, nm32s* pDstMtr, int nHeight, int nWidth);
    //! \}

#ifdef __cplusplus
		};
#endif

#endif // _MMATRIXVECTOR_H_INCLUDED_

