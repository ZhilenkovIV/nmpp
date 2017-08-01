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
	\defgroup nmppcFixSqrt64 nmppcFixSqrt64
	\ingroup cFixpoint64
	\brief
		\ru ���������� ����������� ����� ����� � ������� fixed-point (32.32)
		\en Calculation of square root from number of fixed-point format (32.32)
		\~
	\~
	\param x
		\ru ������� ����� � ������������� ������ � ������� (32.32)
		\en input fixed-point number in format (32.32)
		\~
	\return 
		\ru ���������� ������ � ������� � ������������� ������ (32.32)
		\en Squared root in fixpoint format with fromat (32.32)

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
	unsigned long nmppcFixSqrt64(unsigned long x);
    //! \}
//=============================================================================
	/**
	\defgroup nmppcDoubleToFix64 nmppcDoubleToFix64
	\ingroup cFixpoint64
	\brief
		\ru ������� �������� �� Fixed-Point 64 � Double
		\en Convertion of number from double format to fixed-point format

		\~
	\~
	\param arg
		\ru ������� ����� � ��������� ������
		\en Input double number 
		\~
	\param fixpoint
		\ru ������� �������� �����
		\en position of binary point
		\~
	\return 
		\ru ����� � ������������� ������
		\en Number in fixpoint format

		\~
	\par
    \xmlonly
        <testperf> 
             <param> arg </param> <values> 0.5 10 1000 </values>
             <param> fixpoint </param> <values> 1 32 63 </values>
			 <size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{
long nmppcDoubleToFix64(double arg, int fixpoint);
    //! \}


//=============================================================================


	/**
	\defgroup nmppcFix64ToDouble nmppcFix64ToDouble
	\ingroup cFixpoint64
	\brief
		\ru �������������� 64�. ����� � ������������� ������ � ����� � �������� ������ ���� double 
		\en Conversion of 64 bit number of fixed-point format to floating-point number with type of double

		\~
	\~
	\param arg
		\ru ������� 64�. ����� � ������� � ������������� ������
		\en Input 64 bit fixed-point number 
		\~
	\param fixpoint
		\ru ������� �������� �����
		\en Position of binary point
		\~
	\return 
		\ru ����� � ��������� ������
		\en Number with floating-point format

		\~
	\par
    \xmlonly
        <testperf> 
             <param> arg </param> <values> 1 10 1000 </values>
             <param> fixpoint </param> <values> 1 32 63 </values>
			 <size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{
double nmppcFix64ToDouble(long arg , int fixpoint );
    //! \}
//=============================================================================


	/**
	\defgroup nmppcFixDiv64 nmppcFixDiv64
	\ingroup cFixpoint64
	\brief
		\ru ������� ���� ����� ����� � ������� ���������� � ������� fixed-point 
		\en Division of two integer numbers with retrun of result in fixed-point format 

		\~
	\~
	\param nDividend
		\ru �������
		\en Devident
		\~
	\param nDivisor
		\ru ��������. �������� ������ ���� �� ������ ������ ��� �������.
		\en Devisor. Devisor must be grater then devident in abslolute meaning
		\~
	\param nFixpoint
		\ru ������� �������� �����
		\en Position of binary point
		\~
	\retval nQuotient
		\ru ������� � ������� ����� � ������������� ������
		\en Quotinet with fixed-point format

		\~
	\par
    \xmlonly
        <testperf> 
             <param> nDividend </param> <values> 1 10 1000 </values>
			 <param> nDivisor  </param> <values> 10000 </values>
             <param> nFixpoint </param> <values> 16 32 48 </values>
			 <param> nQuotient </param> <values> &amp; n </values>
			 <size> 1 </size>
        </testperf>
    \endxmlonly

	*/
    //! \{
void nmppcFixDiv64(long* nDividend, long* nDivisor, int nFixpoint, long* nQuotient);
    //! \}
	//     ������� ������� A/B ��� ����� ����� �� ������ 2*abs(A)<abs(B)         

//=============================================================================
	/**
	\defgroup nmppcFixSinCos64 nmppcFixSinCos64
	\ingroup cFixpoint64
	\brief
		\ru ���������� ������ � �������� �� ��������� � ������� fixed-point (32.32)
		\en Calculation sine and cosine of argument in fixed-point format (32.32)

		\~
	\~
	\param nArg
		\ru ���� � ��������. ���� ������ ���� � ��������� �� -PI/2 �� +PI/2 
		\en Angle in radians. Angle must be in range [-PI/2,...,+PI/2]
		\~
	\retval pnSin
		\ru ��������� �� �����
		\en pointer to sine
		\~
	\retval pnCos
		\ru ��������� �� �������
		\en pointer to cosine
		\~
	\par
    \xmlonly
        <testperf> 
             <param> nArg </param> <values> 0x80000000  </values>
			 <param> pnSin </param> <values>  &amp;n </values>
			 <param> pnCos </param> <values>  &amp;m </values>
			   <size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
	void nmppcFixSinCos64(long nArg, long* pnSin, long *pnCos);
    //! \}
//=============================================================================
	/**
	\defgroup nmppcFixArcTan64 nmppcFixArcTan64
	\ingroup cFixpoint64
	\brief
		\ru ���������� ����������� �� ��������� � ������� fixed-point (32.32)
		\en Calculation of arctangent from argument in fixed-point format (32.32)

		\~
	\~
	\param nArg
		\ru ���� � ��������
		\en Angle in radians
		\~
	\retrun
		\ru ����������
		\en Arctangent
		\~
	\par
    \xmlonly
        <testperf> 
			<param> nArg </param> <values> 0x80000000 </values>
			<size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
 long nmppcFixArcTan64(long nArg);
    //! \}

 //=============================================================================
	/**
	\defgroup nmppcFix64Exp01 nmppcFix64Exp01
	\ingroup cFixpoint32
	\brief
		\ru ���������� ���������� ���������� ����� � ������� fixed-point (4.60)
		\en Calculation of exponent from number in fixed-point format (4.60)
		\~
	\~
	\param nVal
		\ru ������� ����� � ������������� ������ � ������� (4.60)
		\en input fixed-point number in format (4.60)
		\~
	\return 
		\ru ���������� ����� � ������� � ������������� ������ (4.60)
		\en Exponent in fixpoint format with fromat (4.60)

		\~
	\par
    \xmlonly
        <testperf> 
             <param> nArg </param> <values> 0x1000000000000000 </values>
			 <size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
	long nmppcFix64Exp01(long nArg);
    //! \}

	long nmppcFrExp(double nArg);

#ifdef __cplusplus
		};
#endif

