//***************************************************************************/
//*                     RC Module Inc., Moscow, Russia                      */
//*                     NeuroMatrix(r) NM640x Software                      */
//*                                                                         */
//*   Software design:  A.Brodyazhenko                                      */
//*                                                                         */
//*   File:             nmpps-FFTFwd_32fc.c                             	*/
//*   Contents:         Routine for forward FFT (32, 64, ..., 2048)         */
//*                     of complex array with 32 bit elements               */                                                        */
//***************************************************************************/

#include "fft_32fc.h"

int nmppsFFTFwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *Spc)
{
	if(Spc->order == 5) {
		nmppsFFT32Fwd_32fc(x, X, Spc);
	} else if(Spc->order == 6) {
		nmppsFFT64Fwd_32fc(x, X, Spc);
	} else if(Spc->order == 7) {
		nmppsFFT128Fwd_32fc(x, X, Spc);
	} else if(Spc->order == 8) {
		nmppsFFT256Fwd_32fc(x, X, Spc);
	} else if(Spc->order == 9) {
		nmppsFFT512Fwd_32fc(x, X, Spc);
	} else if(Spc->order == 10) {
		nmppsFFT1024Fwd_32fc(x, X, Spc);
	} else if(Spc->order == 11) {
		nmppsFFT2048Fwd_32fc(x, X, Spc);
	} else { 
		return -1;
	}
	return 0;
}