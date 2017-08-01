//------------------------------------------------------------------------
//
//  $Workfile:: vStat.h  $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2004/11/22 13:50:02 $
//
//! \if file_doc
//!
//! \file   vMinMax.h
//! \author ������ �������
//! \brief  ����������� ������� ������ �������� � ���������
//!
//! \endif
//!
//------------------------------------------------------------------------

 
#ifndef _VSTAT_H_INCLUDED_
#define _VSTAT_H_INCLUDED_

#ifdef __cplusplus
		extern "C" {
#endif

    /**
	\internal
    \defgroup nmppsCrc_ nmppsCrc_
    \ingroup vStat
		\brief 
		    \ru ������� ������������ ����.
		    \en Cyclic code calculation.

		\~
	  \~
		\param pSrcVec
			\ru ������� ������.
			\en Input vec.
		\~
		\param nSize
			\ru ������ �������� �������.
			\en Input vec size.

		\~
		\retval nCrc
			\ru ����������� ���.
			\en Cyclic code.

		\~
    \par
    \xmlonly
				<testperf>
          <param> pSrcVec </param> <values> L G 		</values>
          <param> nCrc  </param> <values> nn 		</values>
          <param> nSize     </param> <values> 10240 	</values>
				</testperf>
				<testperf>
          <param> pSrcVec </param> <values> G 		</values>
          <param> nCrc  </param> <values> nn 		</values>
          <param> nSize     </param> <values> 8 128 1024 10240 	</values>
				</testperf>

    \endxmlonly
    */
    //! \{
	unsigned nmppsCrc_32u		(const unsigned int* pSrcVec, int nSize);
	unsigned nmppsCrcAcc_32u	(const unsigned int* pSrcVec, int nSize, unsigned int* crcAccumulator);
	unsigned nmppsCrcMask_32u	(const unsigned int* pSrcVec, unsigned mask, int nSize);
	unsigned nmppsCrcMaskAcc_32u(const unsigned int* pSrcVec, unsigned int mask, int nSize, unsigned int* crcAccumulator);
	
	
   
__INLINE__ unsigned  nmppsCrc_64s(nm64s* pSrcVec, int nSize) {  return nmppsCrc_32u((unsigned*)pSrcVec, nSize<<1); }
__INLINE__ unsigned  nmppsCrc_32s(nm32s* pSrcVec, int nSize) {  return nmppsCrc_32u((unsigned*)pSrcVec, nSize   ); }           
__INLINE__ unsigned  nmppsCrc_16s(nm16s* pSrcVec, int nSize) {  return nmppsCrc_32u((unsigned*)pSrcVec, nSize>>1); }
__INLINE__ unsigned  nmppsCrc_8s (nm8s*  pSrcVec, int nSize) {  return nmppsCrc_32u((unsigned*)pSrcVec, nSize>>2); }
__INLINE__ unsigned  nmppsCrc_64u(nm64u* pSrcVec, int nSize) {  return nmppsCrc_32u((unsigned*)pSrcVec, nSize<<1); }
                                                                
//__INLINE__ unsigned  nmppsCrc_32f(nm32f* pSrcVec, int numBitsToClear, int nSize) {  return nmppsCrcMask_32u((unsigned*)pSrcVec,(-1<<numBitsToClear),nSize>>1); }
																
__INLINE__ unsigned  nmppsCrc_16u(nm16u* pSrcVec, int nSize) {  return nmppsCrc_32u((unsigned*)pSrcVec, nSize>>1); }
__INLINE__ unsigned  nmppsCrc_8u (nm8u*  pSrcVec, int nSize) {  return nmppsCrc_32u((unsigned*)pSrcVec, nSize>>2); }


__INLINE__ unsigned nmppsCrcAcc_64s(nm64s* pSrcVec, int nSize, unsigned int* crcAccumulator) {  return nmppsCrcAcc_32u((unsigned*)pSrcVec, nSize<<1, crcAccumulator); }
__INLINE__ unsigned nmppsCrcAcc_32s(nm32s* pSrcVec, int nSize, unsigned int* crcAccumulator) {  return nmppsCrcAcc_32u((unsigned*)pSrcVec, nSize,    crcAccumulator); }           
__INLINE__ unsigned nmppsCrcAcc_16s(nm16s* pSrcVec, int nSize, unsigned int* crcAccumulator) {  return nmppsCrcAcc_32u((unsigned*)pSrcVec, nSize>>1, crcAccumulator); }
__INLINE__ unsigned nmppsCrcAcc_8s (nm8s*  pSrcVec, int nSize, unsigned int* crcAccumulator) {  return nmppsCrcAcc_32u((unsigned*)pSrcVec, nSize>>2, crcAccumulator); }
__INLINE__ unsigned nmppsCrcAcc_64u(nm64u* pSrcVec, int nSize, unsigned int* crcAccumulator) {  return nmppsCrcAcc_32u((unsigned*)pSrcVec, nSize<<1, crcAccumulator); }


__INLINE__ unsigned nmppsCrcAcc_16u(nm16u* pSrcVec, int nSize, unsigned int* crcAccumulator) {  return nmppsCrcAcc_32u((unsigned*)pSrcVec, nSize>>1, crcAccumulator); }
__INLINE__ unsigned nmppsCrcAcc_8u (nm8u*  pSrcVec, int nSize, unsigned int* crcAccumulator) {  return nmppsCrcAcc_32u((unsigned*)pSrcVec, nSize>>2, crcAccumulator); }

unsigned nmppsCrcAcc_32f(const nm32f* pSrcVec, int numBitsToClear, int nSize,  unsigned int* crcAccumulator) ;                                                                                                          
unsigned nmppsCrcAcc_64f(const nm64f* pSrcVec, int numBitsToClear, int nSize,  unsigned int* crcAccumulator) ;

    //! \}
	


//*****************************************************************************
	/**
	\internal
    \defgroup nmppsSadV16_ nmppsSadV16_
    \ingroup vStat
	\brief 
		\ru ����� ���������� ��������� ���� �������� (SAD) �������� � 16 ��������� 
		\en Sum of absolute differences (SAD) between two array with size of 16 numbers 

		\~
	\param pSrc1
		\ru ������ �� 16 ���������. 
        \en array of 16 numbers
		\~
	\param pSrc2
		\ru ������ �� 16 ���������. 
        \en array of 16 numbers
		\~
	\return int		
		\ru SAD. 
        \en SAD

		\~
  \par
	\xmlonly
	 <testperf> 
			<param> pSrc1 </param> <values> L G </values>
			<param> pSrc2 </param> <values> L G </values>
			<size> 1 </size>
	 </testperf>
	\endxmlonly
    */

    //! \{
int nmppsSadV16_16s(nm16s* pSrc1,nm16s* pSrc2);
int nmppsSadV16_8s(nm8s*  pSrc1,nm8s*  pSrc2);
    //! \}

	
#ifdef __cplusplus
		};
#endif

#endif // _VSTAT_H_INCLUDED_