#ifndef _FFT_32FC_H_INCLUDED_
#define _FFT_32FC_H_INCLUDED_

#ifdef __cplusplus
		extern "C" {
#endif

#include "nmtype.h"


#define		NUMBUFF1		21
#define		NUMBUFF2		4

typedef struct
{   
    nm32fcr *Buffers[NUMBUFF1];
    nm32fcr *Buffs[NUMBUFF2];
    int order;
} NmppsFFTSpec_32fc;

typedef struct
{
  NmppsFFTSpec_32fc *specX;
  NmppsFFTSpec_32fc *specY;
} NmppiFFTSpec_32fc;

// sFFT_32fc


    /**
    \defgroup sDFT-8 DFT-8
    \ingroup sFFT_32fc
   	\brief ������� ��� ���������� ������� ��� � ��������� ������ ��� ��������, ��������� �� 8 ����������� �����
    */
    //! \{
void nmppsDFT8Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
    //! \}
	
	/**
 *  \ingroup sDFT-8 
	\brief ������� ��� ���������� ������� ��� � ��������� ������ ��� ��������, ��������� �� 8 ����������� �����
	
	\param [in] x ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] X �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] spec ��������, ���������� ����������� ������������, ��� ���������� ������� ��� ������������� �������
 * 
 */
void nmppsDFT8Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

    /**
    \defgroup sFFT-16 FFT-16
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT16Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
int nmppsFFT16FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
    //! \}	
	
	
	/**
 *  \ingroup sFFT-16
	\brief ������� ��� ���������� ������� ��� � ��������� ������ ��� ��������, ��������� �� 16 ����������� �����
	
	\param [in] x ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] X �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] spec ��������, ���������� ����������� ������������, ��� ���������� ������� ��� ������������� �������
 * 
 */
void nmppsFFT16Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-16
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ������� ���-16
 *  
	\param [in] addr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details 
 */
int nmppsFFT16FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);




    /**
    \defgroup sFFT-32 FFT-32
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT32Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
int nmppsFFT32FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
    //! \}	
	
	
	/**
 *  \ingroup sFFT-32
	\brief ������� ��� ���������� ������� ��� � ��������� ������ ��� ��������, ��������� �� 32 ����������� �����
	
	\param [in] x ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] X �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] spec ��������, ���������� ����������� ������������, ��� ���������� ������� ��� ������������� �������
 * 
 */
void nmppsFFT32Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-32
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ������� ���-32
 *  
	\param [in] addr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details 
 */
int nmppsFFT32FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);





    /**
    \defgroup sFFT-64 FFT-64
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT64Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
int nmppsFFT64FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
    //! \}	
	
	
	/**
 *  \ingroup sFFT-64
	\brief ������� ��� ���������� ������� ��� � ��������� ������ ��� ��������, ��������� �� 64 ����������� �����
	
	\param [in] x ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] X �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] spec ��������, ���������� ����������� ������������, ��� ���������� ������� ��� ������������� �������
 * 
 */
void nmppsFFT64Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-64
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ������� ���-64
 *  
	\param [in] addr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details 
 */
int nmppsFFT64FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);




    /**
    \defgroup sFFT-128 FFT-128
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT128Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
int nmppsFFT128FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
    //! \}	
	
	
	/**
 *  \ingroup sFFT-128
	\brief ������� ��� ���������� ������� ��� � ��������� ������ ��� ��������, ��������� �� 128 ����������� �����
	
	\param [in] x ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] X �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] spec ��������, ���������� ����������� ������������, ��� ���������� ������� ��� ������������� �������
 * 
 */
void nmppsFFT128Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-128
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ������� ���-128
 *  
	\param [in] addr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details 
 */
int nmppsFFT128FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);




    /**
    \defgroup sFFT-256 FFT-256
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT256Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
int nmppsFFT128FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
    //! \}	
	
	
	/**
 *  \ingroup sFFT-256
	\brief ������� ��� ���������� ������� ��� � ��������� ������ ��� ��������, ��������� �� 256 ����������� �����
	
	\param [in] x ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] X �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] spec ��������, ���������� ����������� ������������, ��� ���������� ������� ��� ������������� �������
 * 
 */
void nmppsFFT256Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-256
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ������� ���-256
 *  
	\param [in] addr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details 
 */
int nmppsFFT256FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);




    /**
    \defgroup sFFT-512 FFT-512
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT512Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
int nmppsFFT512FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
    //! \}	
	
	
	/**
 *  \ingroup sFFT-512
	\brief ������� ��� ���������� ������� ��� � ��������� ������ ��� ��������, ��������� �� 512 ����������� �����
	
	\param [in] x ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] X �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] spec ��������, ���������� ����������� ������������, ��� ���������� ������� ��� ������������� �������
 * 
 */
void nmppsFFT512Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-512
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ������� ���-512
 *  
	\param [in] addr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details 
 */
int nmppsFFT512FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);



    /**
    \defgroup sFFT-1024 FFT-1024
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT1024Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
int nmppsFFT1024FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
    //! \}	
	
	
	/**
 *  \ingroup sFFT-1024
	\brief ������� ��� ���������� ������� ��� � ��������� ������ ��� ��������, ��������� �� 1024 ����������� �����
	
	\param [in] x ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] X �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] spec ��������, ���������� ����������� ������������, ��� ���������� ������� ��� ������������� �������
 * 
 */
void nmppsFFT1024Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-1024
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ������� ���-1024
 *  
	\param [in] addr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details 
 */
int nmppsFFT1024FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);



    /**
    \defgroup sFFT-2048 FFT-2048
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT2048Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
int nmppsFFT2048FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);
    //! \}	
	
	
	/**
 *  \ingroup sFFT-2048
	\brief ������� ��� ���������� ������� ��� � ��������� ������ ��� ��������, ��������� �� 2048 ����������� �����
	
	\param [in] x ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] X �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] spec ��������, ���������� ����������� ������������, ��� ���������� ������� ��� ������������� �������
 * 
 */
void nmppsFFT2048Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-2048
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ������� ���-2048
 *  
	\param [in] addr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details 
 */
int nmppsFFT2048FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);

	
	
	
	/**
    \defgroup sIDFT-8 IDFT-8
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsDFT8Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
    //! \}	
	
	
	/**
 *  \ingroup sIDFT-8
	\brief ������� ��� ���������� ��������� ��� � ��������� ������ ��� ��������, ��������� �� 8 ����������� �����
	
	\param [in] ix ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] iX �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] ispec ��������, ���������� ����������� ������������, ��� ���������� ��������� ��� ������������� �������
 * 
 */
void nmppsDFT8Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);

	
	

	/**
    \defgroup sIFFT-16 IFFT-16
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT16Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
int nmppsFFT16InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
    //! \}	
	
	
	/**
 *  \ingroup sIFFT-16
	\brief ������� ��� ���������� ��������� ��� � ��������� ������ ��� ��������, ��������� �� 16 ����������� �����
	
	\param [in] ix ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] iX �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] ispec ��������, ���������� ����������� ������������, ��� ���������� ��������� ��� ������������� �������
 * 
 */
void nmppsFFT16Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-16
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ��������� ���-16
 *  
	\param [in] iaddr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details
 */
int nmppsFFT16InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	
	
	
	
	/**
    \defgroup sIFFT-32 IFFT-32
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT32Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
int nmppsFFT32InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
    //! \}	
	
	
	/**
 *  \ingroup sIFFT-32
	\brief ������� ��� ���������� ��������� ��� � ��������� ������ ��� ��������, ��������� �� 32 ����������� �����
	
	\param [in] ix ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] iX �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] ispec ��������, ���������� ����������� ������������, ��� ���������� ��������� ��� ������������� �������
 * 
 */
void nmppsFFT32Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-32
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ��������� ���-32
 *  
	\param [in] iaddr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details
 */
int nmppsFFT32InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	
	
	
	
	/**
    \defgroup sIFFT-64 IFFT-64
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT64Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
int nmppsFFT64InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
    //! \}	
	
	
	/**
 *  \ingroup sIFFT-64
	\brief ������� ��� ���������� ��������� ��� � ��������� ������ ��� ��������, ��������� �� 64 ����������� �����
	
	\param [in] ix ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] iX �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] ispec ��������, ���������� ����������� ������������, ��� ���������� ��������� ��� ������������� �������
 * 
 */
void nmppsFFT64Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-64
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ��������� ���-64
 *  
	\param [in] iaddr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details
 */
int nmppsFFT64InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	
	
	
	
	/**
    \defgroup sIFFT-128 IFFT-128
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT128Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
int nmppsFFT128InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
    //! \}	
	
	
	/**
 *  \ingroup sIFFT-128
	\brief ������� ��� ���������� ��������� ��� � ��������� ������ ��� ��������, ��������� �� 128 ����������� �����
	
	\param [in] ix ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] iX �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] ispec ��������, ���������� ����������� ������������, ��� ���������� ��������� ��� ������������� �������
 * 
 */
void nmppsFFT128Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-128
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ��������� ���-128
 *  
	\param [in] iaddr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details
 */
int nmppsFFT128InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	
	
	
	
	
	/**
    \defgroup sIFFT-256 IFFT-256
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT256Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
int nmppsFFT256InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
    //! \}	
	
	
	/**
 *  \ingroup sIFFT-256
	\brief ������� ��� ���������� ��������� ��� � ��������� ������ ��� ��������, ��������� �� 256 ����������� �����
	
	\param [in] ix ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] iX �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] ispec ��������, ���������� ����������� ������������, ��� ���������� ��������� ��� ������������� �������
 * 
 */
void nmppsFFT256Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);

/**
 *  \ingroup sIFFT-256
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ��������� ���-256
 *  
	\param [in] iaddr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details
 */
int nmppsFFT256InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	


	/**
    \defgroup sIFFT-512 IFFT-512
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT512Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
int nmppsFFT512InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
    //! \}	
	
	
	/**
 *  \ingroup sIFFT-512
	\brief ������� ��� ���������� ��������� ��� � ��������� ������ ��� ��������, ��������� �� 512 ����������� �����
	
	\param [in] ix ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] iX �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] ispec ��������, ���������� ����������� ������������, ��� ���������� ��������� ��� ������������� �������
 * 
 */
void nmppsFFT512Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-512
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ��������� ���-512
 *  
	\param [in] iaddr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details
 */
int nmppsFFT512InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	
	
	
	
	/**
    \defgroup sIFFT-1024 IFFT-1024
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT1024Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
int nmppsFFT1024InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
    //! \}	
	
	
	/**
 *  \ingroup sIFFT-1024
	\brief ������� ��� ���������� ��������� ��� � ��������� ������ ��� ��������, ��������� �� 1024 ����������� �����
	
	\param [in] ix ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] iX �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] ispec ��������, ���������� ����������� ������������, ��� ���������� ��������� ��� ������������� �������
 * 
 */
void nmppsFFT1024Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-1024
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ��������� ���-1024
 *  
	\param [in] iaddr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details
 */
int nmppsFFT1024InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	
	
	
	
	/**
    \defgroup sIFFT-2048 IFFT-2048
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFT2048Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
int nmppsFFT2048InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
    //! \}	
	
	
	/**
 *  \ingroup sIFFT-2048
	\brief ������� ��� ���������� ��������� ��� � ��������� ������ ��� ��������, ��������� �� 2048 ����������� �����
	
	\param [in] ix ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] iX �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] ispec ��������, ���������� ����������� ������������, ��� ���������� ��������� ��� ������������� �������
 * 
 */
void nmppsFFT2048Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-2048
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ��������� ���-2048
 *  
	\param [in] iaddr ������� ��������� �� ��������� �������������
	\return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details
 */
int nmppsFFT2048InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	

	
	
	
	/**
    \defgroup sFFT-Common FFT-Common
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFTFwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);
int nmppsFFTFwdInitAlloc_32fc(NmppsFFTSpec_32fc **Spec, int Order);
    //! \}	
	
	
	/**
 *  \ingroup sFFT-Common
	\brief ������� ��� ���������� ������� ��� � ��������� ������ ��� �������� ����� �� 8 �� 2048
	
	\param [in] x ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] X �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] spec ��������, ���������� ����������� ������������, ��� ���������� ������� ��� ������������� �������
 * 
 */
void nmppsFFTFwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);


/**
 *  \ingroup sFFT-Common
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ������� ��� � ��������� ������ ��� �������� ����� �� 8 �� 2048
 *  
 *	\param [in] Spec ������� ��������� �� ��������� �������������
 *  \param [in] Order ����������� ���, ������� ����� ���������, ��������, ��� ���256 ���� �������� ����� 8 (�.�. 2^8 = 256)
 *  \return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details
 */
int nmppsFFTFwdInitAlloc_32fc(NmppsFFTSpec_32fc **Spec, int Order);
	
	
	
	
	
	/**
    \defgroup sIFFT-Common IFFT-Common
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsFFTInv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
int nmppsFFTInvInitAlloc_32fc(NmppsFFTSpec_32fc **iSpec, int iOrder);
    //! \}	
	
	
	/**
 *  \ingroup sIFFT-Common
	\brief ������� ��� ���������� ��������� ��� � ��������� ������ ��� �������� ����� �� 8 �� 2048
	
	\param [in] ix ������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\retval [out] iX �������� ������ ����������� ����� (�� ������ � �������������� ����� ����� ��� float)
	\param [in] ispec ��������, ���������� ����������� ������������, ��� ���������� ��������� ��� ������������� �������
 * 
 */
void nmppsFFTInv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-Common
 *  \brief ������� ������������� ��������� �������������, ����������� ��� ���������� ��������� ��� � ��������� ������ ��� �������� ����� �� 8 �� 2048
 *  
 *	\param [in] iSpec ������� ��������� �� ��������� �������������
 *  \param [in] iOrder ����������� ���, ������� ����� ���������, ��������, ��� ���256 ���� �������� ����� 8 (�.�. 2^8 = 256)
 *  \return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 *  \details
 */
int nmppsFFTInvInitAlloc_32fc(NmppsFFTSpec_32fc **iSpec, int iOrder);
	
	

	
	
		/**
    \defgroup sFFTFree FFTFree
    \ingroup sFFT_32fc
    */
    //! \{
int nmppsFFTFree_32fc(NmppsFFTSpec_32fc *spec);
    //! \}	
	
	
	/**
 *  \ingroup sFFTFree
	\brief ������� ����������� ������, ���������� ��� ������������, ����������� ��� ���������� ��� ������������� ������� 
	
	\param [in] spec ��������, ���������� ����������� ������������, ��� ���������� ��������� ��� ������������� �������
    \return ������� ���������� 0 � ������ �������� ������������� � ������������� ����� (�� -1 � ������) � ������ ������
 * 
 */
int nmppsFFTFree_32fc(NmppsFFTSpec_32fc *spec);





#ifdef __cplusplus
		};
#endif

#endif // _FFT_32FC_H_INCLUDED_