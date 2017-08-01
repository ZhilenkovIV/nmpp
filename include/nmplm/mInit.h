//------------------------------------------------------------------------
//
//  $Workfile:: mInit.h  $
//
//  ��������-��������� ����������
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/01/12 14:03:24 $
//
//! \if file_doc
//!
//! \file   mtrInit.h
//! \author ������ �������
//! \brief  ����������� ������� ��� ������������� � �����������.
//!
//! \endif
//!
//------------------------------------------------------------------------
#ifndef _MINIT_H_INCLUDED_
#define _MINIT_H_INCLUDED_


#ifdef __cplusplus
		extern "C" {
#endif		

		
		
//*****************************************************************************

    //--------------------------------------------------------------------
    //! \ru
    //!     \defgroup mInit ������������� � �����������
    //! \en
    //!     \defgroup mInit Initialization and copy
    //! \~
    //! \ingroup MTR_Group
    //--------------------------------------------------------------------

//*****************************************************************************

    /**
    \defgroup nmppmCopyua nmppmCopyua
    \ingroup mInit
    \brief
        \ru ����������� ���������� � ������������� �� �������� 64- ���������� �����
			������� � �����������. 
        \en Copying a submatrix from an unaligned to 64 bit word position to an alighed one. 

		\~
		\~
    \param	pSrcMtr			
        \ru �������� �������. 
        \en Source mtr. 
		\~
    \param	nSrcStride	
        \ru ������ �������� ������� � ���������. 
        \en Source mtr width in elements. 
		\~
    \param	nSrcOffset			
        \ru �������� � ��������� �� ������ �������-���������. 
        \en nShift in elements from the source mtr origin. 
		\~
    \param	nDstStride	
        \ru ������ �������������� ������� � ���������. 
        \en Result mtr width in elements. 
		\~
    \param	nHeight		
        \ru ����� ����� ����������. 
        \en Row count in submatrix. 
		\~
    \param	nWidth		
        \ru ����� �������� ����������. 
        \en Column count in submatrix. 

		\~
    \retval	pDstMtr			
        \ru �������������� �������. 
        \en The result mtr. 

		\~
    \return \e void
    
    \restr 
        \ru 
			- ������� � �������� ������� �� ������ ������������� � ������
            - ����� �������� ���������� ���������� nWidth ������ ���� ������ ����� 
			  ��������� � 64-� ��������� �����. 
        \en 
			- The input and output matrixes should not overlap in memory.
            - nWidth should be divisible by element count in 64-bit word. 
    
        
		\~
    \par
    \xmlonly
        <testperf> 
             <param> pSrcMtr </param> <values> L G </values>
             <param> pDstMtr </param> <values> L G </values>
             <param> nDstStride </param> <values> nSrcStride/2 </values>
             <param> nSrcOffset </param> <values> 8 </values>
             <param> nHeight </param> <values> 8 </values>
             <param> nWidth </param> <values> nSrcStride/4 </values>
             <param> nSrcStride </param> <values>  256 </values>
             <size>  nHeight* nWidth </size>
        </testperf>
        <testperf> 
             <param> pSrcMtr </param> <values> L </values>
             <param> pDstMtr </param> <values> G </values>
             <param> nDstStride </param> <values> nSrcStride/2 </values>
             <param> nSrcOffset </param> <values> 8 </values>
             <param> nHeight </param> <values> 8 </values>
             <param> nWidth </param> <values> nSrcStride/4 </values>
             <param> nSrcStride </param> <values> 32 128 256 </values>
             <size>  nHeight* nWidth </size>
        </testperf>
    \endxmlonly
    */
    //! \{
void nmppmCopyua_8s (  nm8s* pSrcMtr, int nSrcStride, int nSrcOffset, nm8s* pDstMtr,  int nDstStride,int nHeight, int nWidth);
void nmppmCopyua_16s( nm16s* pSrcMtr, int nSrcStride, int nSrcOffset, nm16s* pDstMtr, int nDstStride,int nHeight, int nWidth);
void nmppmCopyua_32s( nm32s* pSrcMtr, int nSrcStride, int nSrcOffset, nm32s* pDstMtr, int nDstStride,int nHeight, int nWidth);
    //! \}


//*****************************************************************************

    /**
    \defgroup MTR_Copyau MTR_Copyau
    \ingroup mInit
    \brief
        \ru ����������� ���������� � ����������� �� ������� 64-� ��������� ����
			������� � ������������� �������.
        \en Copying a submatrix from an aligned to 64 bit word position to an unalighed one. 
		\~
    \param	pSrcMtr			
        \ru �������� �������. 
        \en Source mtr. 
		\~
    \param	nSrcStride	
        \ru ������ �������� ������� � ���������. 
        \en Source mtr width in elements. 
		\~
    \retval	pDstMtr			
        \ru �������������� �������. 
        \en The result mtr. 
		\~
    \param	nDstStride	
        \ru ������ �������������� ������� � ���������. 
        \en Result mtr width in elements. 
		\~
    \param	nDstOffset			
        \ru ������ ������� (� ���������) ���� ������������ �������. 
        \en nShift in elements from the source mtr origin. 
		\~
    \param	nHeight		
        \ru ����� ����� ����������. 
        \en Row count in submatrix. 
		\~
    \param	nWidth		
        \ru ����� �������� ����������. 
        \en Column count in submatrix. 
		\~
    \return \e void
    
    \restr 
        \ru
            - ������� � �������� ������� �� ������ ������������� � ������
            - ����� �������� ���������� ���������� nWidth ������ ���� ������� 64-�����. 
        \en 
            - The input and output matrixes should not overlap in memory.
            - The Column count of the copied submatrix nWidth should be divisible by 64 bits.
    
		\~
    \par
    \xmlonly
        <testperf> 
             <param> pSrcMtr </param> <values> L G </values>
             <param> pDstMtr </param> <values> L G </values>
             <param> nDstStride </param> <values> nSrcStride*2 </values>
             <param> nDstOffset </param> <values> nSrcStride/2 </values>
             <param> nHeight </param> <values> 8 </values>
             <param> nWidth </param> <values> nSrcStride/4 </values>
             <param> nSrcStride </param> <values> 128 </values>
             <size>  nHeight* nWidth </size>
        </testperf>
        <testperf> 
             <param> pSrcMtr </param> <values> L </values>
             <param> pDstMtr </param> <values> G </values>
             <param> nDstStride </param> <values> nSrcStride*2 </values>
             <param> nDstOffset </param> <values> nSrcStride/2 </values>
             <param> nHeight </param> <values> 8 </values>
             <param> nWidth </param> <values> nSrcStride/4 </values>
             <param> nSrcStride </param> <values> 32 64 128 </values>
             <size>  nHeight* nWidth </size>
        </testperf>
    \endxmlonly
     
    */
    //! \{
void nmppmCopyau_8s (  nm8s* pSrcMtr, int nSrcStride, nm8s* pDstMtr,  int nDstStride, int nDstOffset,int nHeight, int nWidth);
void nmppmCopyau_16s( nm16s* pSrcMtr, int nSrcStride, nm16s* pDstMtr, int nDstStride, int nDstOffset,int nHeight, int nWidth);
void nmppmCopyau_32s( nm32s* pSrcMtr, int nSrcStride, nm32s* pDstMtr, int nDstStride, int nDstOffset,int nHeight, int nWidth);
    //! \}


//*****************************************************************************

    /**
    \defgroup MTR_Copy MTR_Copy
    \ingroup mInit
    \brief
        \ru ������� ����������� ������������� �������� ������ ����� ���������� ���������. 
        \en Functions of copying rectangular memory areas between two-dimensional arrays. 
		\~
    \param	pSrcMtr			
        \ru �������� �������. 
        \en Source mtr. 
		\~
    \param	nSrcStride	
        \ru ������ �������� ������� � ���������. 
        \en Source mtr width in elements. 
		\~
    \param	nDstStride	
        \ru ������ �������������� ������� � ���������. 
        \en Result mtr width in elements. 
		\~
    \param	nHeight		
        \ru ����� ����� ����������. 
        \en Row count in submatrix. 
		\~
    \param	nWidth		
        \ru ����� �������� ����������. 
        \en Column count in submatrix. 
		\~
    \retval	pDstMtr			
        \ru �������������� �������. 
        \en The result mtr. 
		\~
    \return \e void
    
    \restr 
        \ru �������� ������� �� ����� ���� ������������ (�.�. �������� ��������������� 
            �� ����� �������) 
        \en The output mtr cannot be rewritten (i.e. placed directly to the 
            input mtr location). 
    
		\~
    \par
    \xmlonly
        <testperf> 
             <param> pSrcMtr </param> <values> L G </values>
             <param> pDstMtr </param> <values> L G </values>
             <param> nDstStride </param> <values> nSrcStride </values>
             <param> nHeight </param> <values> 128 </values>
             <param> nWidth </param> <values> nSrcStride </values>
             <param> nSrcStride </param> <values> 256 </values>
             <size> nHeight*nWidth </size>
        </testperf>
        <testperf> 
             <param> pSrcMtr </param> <values> L </values>
             <param> pDstMtr </param> <values> G </values>
             <param> nDstStride </param> <values> nSrcStride </values>
             <param> nHeight </param> <values> 128 </values>
             <param> nWidth </param> <values> nSrcStride </values>
             <param> nSrcStride </param> <values> 8 128 256 </values>
             <size> nHeight*nWidth </size>
        </testperf>
    \endxmlonly
       
    */
    //! \{
void nmppmCopy_8s (  nm8s* pSrcMtr, int nSrcStride,  nm8s* pDstMtr, int nDstStride, int nHeight, int nWidth);
void nmppmCopy_16s( nm16s* pSrcMtr, int nSrcStride, nm16s* pDstMtr, int nDstStride, int nHeight, int nWidth);
void nmppmCopy_32s( nm32s* pSrcMtr, int nSrcStride, nm32s* pDstMtr, int nDstStride, int nHeight, int nWidth);
void nmppmCopy_64s( nm64s* pSrcMtr, int nSrcStride, nm64s* pDstMtr, int nDstStride, int nHeight, int nWidth);
    //! \}


//*****************************************************************************


	/**
	\internal
	\defgroup MTR_Fill MTR_Fill 
	\ingroup mInit
	\brief
		\ru ������� ������������� ���������� ���������� ���������. 
		\en Function of submatrix initialization with a ant value.  

		\~
	\~
	\param pMtr
        \ru �������������� ����������. 
        \en The result submatrix. 
		\~
	\param nVal
        \ru ���������. 
        \en A ant. 
		\~
	\param nMtrStride
		\ru ������ ���� ������� \n
			(���������� � 32-� ��������� ������). 
         \en Width of whole mtr \n
            (measured in 32-bit words). 
	\param nMtrHeight
        \ru ������ ����������. 
        \en Submatrix height. 
		\~
	\param nMtrWidth
		\ru ������ ����������� � ���������
		\en Submatrix width in elements

		\~
    \par
    \xmlonly
        <testperf> 
             <param> pMtr </param> <values> L G </values>
             <param> nVal </param> <values> n </values>
             <param> nMtrStride </param> <values> nMtrWidth/2 </values>
             <param> nMtrHeight </param> <values> 8 </values>
             <param> nMtrWidth </param> <values> 8 32 128 </values>
             <size>  nMtrHeight*nMtrWidth </size>
        </testperf>
    \endxmlonly

	*/
    //! \{
void MTR_Fill_8s(nm8s* pMtr,  int8b nVal, int nMtrStride, int nMtrHeight, int nMtrWidth);
    //! \}
    

#ifdef __cplusplus
		};
#endif
    

#endif // _MINIT_H_INCLUDED_
