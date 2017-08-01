//***************************************************************************/
//*                                                                         */
//*                    Neuroprocessor NM3203 SDK v.1.2                      */
//*                                                                         */
//*               ������������ ���� fixpoint32  �������                     */
//*                1999 (c) RC Module Inc., Moscow, Russia                  */
//*                                                                         */
//*                                                                         */
//*  Date:28.12.99                                                          */
//***************************************************************************/
#ifdef __cplusplus
extern "C" 	{	
#endif


//=============================================================================
	/**
	\defgroup nmppcFixExp32 nmppcFixExp32
	\ingroup cFixpoint32
	\brief
		\ru ���������� ���������� ���������� ����� � ������� fixed-point (16.16)
		\en Calculation of exponent from number in fixed-point format (16.16)
		\~
	\~
	\param nVal
		\ru ������� ����� � ������������� ������ � ������� (16.16)
		\en input fixed-point number in format (16.16)
		\~
	\return 
		\ru ���������� ����� � ������� � ������������ ������ (16.16)
		\en Exponent in fixpoint format with fromat (16.16)

		\~
	\par
    \xmlonly
        <testperf> 
             <param> nVal </param> <values> 0x8000 0x10000 0x4000   </values>
			 <size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
int nmppcFixExp32( int nVal);
    //! \}
//=============================================================================
	/**
	\defgroup nmppcFixSinCos32 nmppcFixSinCos32
	\ingroup cFixpoint32
	\brief
		\ru ���������� ������ � �������� �� ��������� � ������� fixed-point (16.16)
		\en Calculation sine and cosine of argument in fixed-point format (16.16)

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
             <param> nArg </param> <values> 0x8000  </values>
			 <param> pnSin </param> <values>  &amp;n </values>
			 <param> pnCos </param> <values>  &amp;m </values>
			   <size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
void nmppcFixSinCos32(int nArg, int* pnSin, int* pnCos);
    //! \}

//=============================================================================
	/**
	\defgroup nmppcFixArcTan32 nmppcFixArcTan32
	\ingroup cFixpoint32
	\brief
		\ru ���������� ����������� �� ��������� � ������� fixed-point (16.16)
		\en Calculation of arctangent from argument in fixed-point format (16.16)

		\~
	\~
	\param nArg
		\ru ���� � ��������
		\en Angle in radians
		\~
	\return
		\ru ����������
		\en Arctangent
		\~
	\par
    \xmlonly
        <testperf> 
			<param> nArg </param> <values> 0x8000 </values>
			<size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
 int nmppcFixArcTan32(int nArg);
    //! \}


//=============================================================================
	/**
	\defgroup nmppcDoubleToFix32 nmppcDoubleToFix32
	\ingroup cFixpoint32
	\brief
		\ru ������� �������� �� Fixed-Point (16.16) � Double
		\en Convertion of number from double format to fixed-point format (16.16)

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
		\ru ����� � ������������ ������
		\en Number in fixpoint format

		\~
	\par
    \xmlonly
        <testperf> 
             <param> arg </param> <values> 0.5 10 1000 </values>
			 <size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{
int nmppcDoubleToFix32(double arg);
    //! \}


//=============================================================================


	/**
	\defgroup nmppcFix32ToDouble nmppcFix32ToDouble
	\ingroup cFixpoint32
	\brief
		\ru �������������� 32�. ����� � ������������� ������ (16.16) � ����� � �������� ������ ���� double 
		\en Conversion of 32 bit number of fixed-point format (16.16) to floating-point number with type of double

		\~
	\~
	\param arg
		\ru ������� 32�. ����� � ������� � ������������� ������ (16.16)
		\en Input 32 bit fixed-point number (16.16)
		\~
	\return 
		\ru ����� � ��������� ������
		\en Number with floating-point format
		\~
	\par
    \xmlonly
        <testperf> 
             <param> arg </param> <values> 1 10 1000 </values>
			 <size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{
double nmppcFix32ToDouble(int arg);
    //! \}
//=============================================================================
	/**
	\defgroup nmppcFixSqrt32 nmppcFixSqrt32
	\ingroup cFixpoint32
	\brief
		\ru ���������� ����������� ����� ����� � ������� fixed-point (16.16)
		\en Calculation of square root from number in fixed-point format (16.16)
		\~
	\~
	\param nVal
		\ru ������� ����� � ������������� ������ � ������� (16.16)
		\en input fixed-point number in format (16.16)
		\~
	\return 
		\ru ���������� ������ � ������� � ������������ ������ (16.16)
		\en Squared root in fixpoint format with fromat (16.16)

		\~
	\par
    \xmlonly
        <testperf> 
             <param> nVal </param> <values> 1 1000 1000000 </values>
			 <size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
	unsigned int nmppcFixSqrt32( unsigned int nVal );
	//! \}

//=============================================================================

	/**
	\defgroup nmppcFixMul32 nmppcFixMul32
	\ingroup cFixpoint32
	\brief
		\ru ���������� ������������ ���� ����� � ������� fixed-point (16.16)
		\en Calculation of product  of two numbers in fixed-point format (16.16)
		\~
	\~
	\param nX
		\ru ������ ������� ����� � ������������� ������ � ������� (16.16)
		\en First input fixed-point number in format (16.16)
		\~
	\param nY
		\ru ������ ������� ����� � ������������� ������ � ������� (16.16)
		\en First input fixed-point number in format (16.16)
		\~
	\return 
		\ru ����������� � ������� � ������������ ������ (16.16)
		\en Product in fixpoint format with fromat (16.16)

		\~
	\par
    \xmlonly
        <testperf> 
             <param> nX </param> <values> 1 </values>
			 <param> nY </param> <values> 1 </values>
			 <size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
	int nmppcFixMul32(int nX, int nY);
	//! \}

//=============================================================================
	/**
	\defgroup nmppcFixMul32 nmppcFixMul32
	\ingroup cFixpoint32
	\brief
		\ru ������� ���� ����� ����� � ������� ���������� � ������� fixed-point (16.16)
		\en Division of two integer numbers with return of result in fixed-point format (16.16)
		\~
	\~
	\param nX
		\ru ������� 
		\en Divisible
		\~
	\param nY
		\ru ��������
		\en Devisor
		\~
	\return 
		\ru ������� �� ������� � ������� � ������������ ������ (16.16)
		\en Quotient from divison in fixed-point format  (16.16)

		\~
	\par
    \xmlonly
        <testperf> 
             <param> nX </param> <values> 0x102340 0x10234 0x0080</values>
			 <param> nY </param> <values> 0x102340 0x10234 0x0080</values>
			 <size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
	int nmppcFixDiv32(int nX, int nY);
	//! \}
//=============================================================================
	/**
	\defgroup nmppcFixInv32 nmppcFixInv32
	\ingroup cFixpoint32
	\brief
		\ru ���������� ��������� �������� ������ ����� � ������� ���������� � ������� fixed-point 
		\en Calculation of inverse value of number with return of result in fixed-point format 
		\~
	
	\f[ 
        Res  =  2^nFixpoint/nVal
    \f]

	\~
	\param nVal
		\ru ��������
		\en Devisor
		\~
	\param nFixpoint
		\ru ������� �������� ����� � ������������� �����
		\en Position of binary point in result number
		\~
	\return 
		\ru ������� �� ������� ��� ������� � ������������ ������ (16.16)
		\en Quotient from divison in fixed-point format  (16.16)

		\~
	\par
    \xmlonly
        <testperf> 
             <param> nVal </param> <values> 0x102 0x1034 0x490000 </values>
			 <param> nFixpoint </param> <values> 8 16 24 </values>
			 <size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
	int nmppcFixInv32(int nVal, int nFixpoint);
	//! \}

//=============================================================================

	/**
	\defgroup nmppcTblFixArcSin32 nmppcTblFixArcSin32
	\ingroup cFixpoint32
	\brief
		\ru ���������� ������� arcsin �� �������. ������� � �������� �������� �������� � �������  fixed-point (16.16)
		\en Calculation of trigonometric function arcsin by table. Input and ouput value are set in fixed-point format (16.16)

		\~
	\~
	\param nArg
		\ru ������� ��������. 
		\en Angle in radians. Angle must be in range [-PI/2,...,+PI/2]
		\~
	\return 
		\ru ���� � ��������� �� -PI/2 �� +PI/2 � ������� fixed-point (16.16)
		\en Angle in range -PI/2 .. +PI/2 in fixed-point format (16.16)
		\~
	\par
    \xmlonly
        <testperf> 
            <param> nArg </param> <values> 0x8000  </values>
			<size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
	int nmppcTblFixArcSin32(int nArg);
    //! \}
//=============================================================================

	/**
	\defgroup nmppcTblFixArcCos32 nmppcTblFixArcCos32
	\ingroup cFixpoint32
	\brief
		\ru ���������� ������� arccos �� �������. ������� � �������� �������� �������� � �������  fixed-point (16.16)
		\en Calculation of trigonometric function arccos by table. Input and ouput value are set in fixed-point format (16.16)

		\~
	\~
	\param nArg
		\ru ������� ��������. 
		\en Input value  
		\~
	\return 
		\ru ���� � ��������� �� 0 �� PI � ������� fixed-point (16.16)
		\en Angle in range from 0..PI in fixed-point format (16.16)
		\~
	\par
    \xmlonly
        <testperf> 
            <param> nArg </param> <values> 0x8000  </values>
			<size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
	int nmppcTblFixArcCos32(int nArg);
    //! \}


//=============================================================================

	/**
	\defgroup nmppcTblFixCos32 nmppcTblFixCos32
	\ingroup cFixpoint32
	\brief
		\ru ���������� ������� cos �� �������. ������� � �������� �������� �������� � �������  fixed-point (16.16)
		\en Calculation of trigonometric function cos by table. Input and ouput value are set in fixed-point format (16.16)

		\~
	\~
	\param nArg
		\ru ���� � ��������� �� 0 �� PI � ������� fixed-point (16.16)
		\en Angle in range [0..PI] in fixed-point format (16.16)
		\~
	\return 
		\ru �������� cos � ������� fixed-point (16.16)
		\en cos value in fixed-point format (16.16)
		\~
	\par
    \xmlonly
        <testperf> 
            <param> nArg </param> <values> 0x8000  </values>
			<size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
	int nmppcTblFixCos32(int nArg);
    //! \}

//=============================================================================

	/**
	\defgroup nmppcTblFixSin32 nmppcTblFixSin32
	\ingroup cFixpoint32
	\brief
		\ru ���������� ������� sin �� �������. ������� � �������� �������� �������� � �������  fixed-point (16.16)
		\en Calculation of trigonometric function sin by table. Input and ouput value are set in fixed-point format (16.16)

		\~
	\~
	\param nArg
		\ru ���� � ��������� �� -PI/2 �� +PI/2 � ������� fixed-point (16.16)
		\en Angle in range -PI/2 .. +PI/2 in fixed-point format (16.16)
		\~
	\return 
		\ru �������� sin � ������� fixed-point (16.16)
		\en sin value in fixed-point format (16.16)
		\~
	\par
    \xmlonly
        <testperf> 
            <param> nArg </param> <values> 0x8000  </values>
			<size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
	int nmppcTblFixSin32(int nArg);
    //! \}

//=============================================================================

	/**
	\defgroup nmppcFixDivMod32 nmppcFixDivMod32
	\ingroup cFixpoint32
	\brief
		\ru ���������� �������� � ������� ��� ������� ����� � ������������� ������� � ������� fixed-point (16.16)
		\en Calculation of quotient and reminder at division of numbers in fixed-point dormat (16.16)

		\~
	\~
	\param nDividend
		\ru �������  � ������� fixed-point (16.16)
		\en Dividend in fixed-point format (16.16)
		\~
	\param nDivisor
		\ru �������� � ������� fixed-point (16.16)
		\en Divisor in fixed-point format (16.16)
		\~
	\retval pnQuotient
		\ru ������� �� ������� � ������� fixed-point (16.16)
		\en Quotient of division in  fixed-point format (16.16)
		\~
	\retval pnReminder
		\ru ������� �� ������� � ������� fixed-point (16.16)
		\en Reminder of division in  fixed-point format (16.16)
		\~
	\par
    \xmlonly
        <testperf> 
            <param> nDividend </param> <values> 0x5000  </values>
			<param> nDivisor  </param> <values> 0x6000  </values>
			<param> pnQuotient  </param> <values> &amp;n  </values>
			<param>	pnReminder  </param> <values> &amp;m  </values>
			<size> 1 </size>
        </testperf>
    \endxmlonly
	*/
    //! \{	
	void nmppcFixDivMod32(int nDividend, int nDivisor, int* pnQuotient, int* pnReminder);
	void nmppcFixDivPosMod32(unsigned int nDividend, unsigned int nDivisor,  int* pnQuotient, int* pnReminder);
    //! \}
#ifdef __cplusplus
		};
#endif

