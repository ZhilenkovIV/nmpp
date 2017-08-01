//***************************************************************************/
//*                                                                         */
//*                    Neuroprocessor NM6403 SDK v.1.2                      */
//*                                                                         */
//*               ������������ ���� fixpoint64  �������                     */
//*                1999 (c) RC Module Inc., Moscow, Russia                  */
//*                                                                         */
//*                                                                         */
//*  Date:28.12.99                                                          */
//***************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

//=============================================================================
	
	/**
	\defgroup nmppcSqrt nmppcSqrt
	\ingroup cInteger
	\brief
		\ru ���������� ����������� ����� 
		\en Calculation of square root

		\~
	\~
	\param x
		\ru ������� ����� 
		\en input number
		\~
	\return 
		\ru ���������� ������ 
		\en Squared root 
		\~
	\par
    \xmlonly
        <testperf> 
             <param> x </param> <values> 1 1000 10000000 </values>
			 <size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
	unsigned int nmppcSqrt_64u(unsigned long long x);
//unsigned int nmppcSqrt_32u(unsigned int x);
    //! \}
//=============================================================================

//     ������� ������� A/B ��� ����� ����� �� ������ 2*abs(A)<abs(B)         
void IDivInv64(
			long*		Dividend,		// ������� 
			long*		Divisor,		// ��������
	const	int			DivIterations,	// ���-�� �������� ��� ���������(���������) �������
			long*		Quotient		// �������
				);
long Fix64Exp01(long arg);




#ifdef __cplusplus
		};
#endif
