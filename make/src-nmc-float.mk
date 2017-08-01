INC_DIRS         = -I../../include -I$(NEURO)/include

SRC_DIRS = $(ROOT)/src/nmpls/Metric
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/FFT0032/nm
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/IFFT0032/nm 
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/FFT0064/nm
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/IFFT0064/nm
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/FFT0128/nm
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/IFFT0128/nm
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/FFT0256/nm
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/IFFT0256/nm
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/FFT0512/nm
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/IFFT0512/nm
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/FFT1024/nm
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/IFFT1024/nm
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/FFT2048/nm
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/IFFT2048/nm
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/common
SRC_DIRS+= $(ROOT)/src/nmpls/FFT_32fc/FFTFree/common
SRC_DIRS+= $(ROOT)/src/nmplv/Support/nm
SRC_DIRS+= $(ROOT)/src/nmplv/Support/common
SRC_DIRS+= $(ROOT)/src/nmplv/Stat/nm
SRC_DIRS+= $(ROOT)/src/nmplv/Stat/common
SRC_DIRS+= $(ROOT)/src/nmplv/Arithmetics/common
SRC_DIRS+= $(ROOT)/src/nmplv/Init/common


