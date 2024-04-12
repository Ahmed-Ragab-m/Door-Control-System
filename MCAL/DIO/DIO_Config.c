#include "DIO_Interface.h"


PIN_STATUS PINS_Arr[TOTAL_PINS]={
	INFREE,       // Port A Pin 0 ADC0
	INFREE,       // Port A Pin 1 ADC1
	OUTPUT,       // Port A Pin 2 
	OUTPUT,       // Port A Pin 3 
	OUTPUT,       // Port A Pin 4 
	OUTPUT,       // Port A Pin 5 
	OUTPUT,       // Port A Pin 6 
	OUTPUT,       // Port A Pin 7 - ADC7
	OUTPUT,       // Port B Pin 0 
	OUTPUT,       // Port B Pin 1   
	OUTPUT,		  // Port B Pin 2 - INT2
	OUTPUT,		  // Port B Pin 3 - OC0
	OUTPUT,		  // Port B Pin 4 - ss
	OUTPUT,	  // Port B Pin 5 - mosi
	OUTPUT,	  // Port B Pin 6 - miso
	INFREE,		  // Port B Pin 7 - clk
	OUTPUT,	  // Port C Pin 0 
	OUTPUT,	  // Port C Pin 1 
	OUTPUT,	  // Port C Pin 2 
	OUTPUT,	  // Port C Pin 3 
	OUTPUT,	  // Port C Pin 4 
	OUTPUT,		  // Port C Pin 5 
	INFREE,		  // Port C Pin 6 
	OUTPUT,		  // Port C Pin 7 
	OUTPUT,		  // Port D Pin 0 - RX
	OUTPUT,	      // Port D Pin 1 - TX
    OUTPUT,       // Port D Pin 2 - INT0
	INPULL_UP,       // Port D Pin 3 - INT1
	INPULL_UP,		  // Port D Pin 4 - OC1B
	OUTPUT,		  // Port D Pin 5 - OC1A
	INPULL_UP,		  // Port D Pin 6 - ICP
	INPULL_UP		  // Port D Pin 7 
};
