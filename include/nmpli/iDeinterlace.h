#include "nmpp.h"
#include "nmpli.h"


 //! \defgroup funcs ������� ���������������
 //! \ingroup nmppcGroup
 //! \{
	//! ������� ��������� ���� �� ��� ���������.
	//! \param pSrcImg ��������� �� �������� ����.
	//! \param nSrcWidth ������ ��������� ����� � ��������.
	//! \param nSrcHeight ������ �������� ����� � ��������.
	//! \param pDstEven ��������� �� ����� ������� ���������
	//! \param pDstOdd ��������� �� ����� ��������� ���������
	//! \return \e void 
void IMG_DeinterlaceSplit(nm8u* pSrcImg, int nSrcWidth, int nSrcHeight, nm8u* pDstEven, nm8u* pDstOdd);

	//! ������� ���������� ��� �������� � ���� ������ ����.
	//! \param pSrcEven ��������� �� ������ ��������.
	//! \param nSrcOdd ��������� �� �������� ��������.
	//! \param nSrcWidth ������ ������� ���������� � ��������.
	//! \param pSrcHeight ������ ������� ���������� � ��������.
	//! \param pDst ��������� �� ����� ��������������� ����
	//! \return \e void 
void IMG_DeinterlaceBlend(nm8u* pSrcEven, nm8u* pSrcOdd, int nSrcWidth, int nSrcHeight, nm8u* pDst);

//! \}