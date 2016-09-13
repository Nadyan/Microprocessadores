#include "picconfig.h"
#include "delays.h"

void hdw_setup(){
	ADCON0 = 0b00000000;
	ADCON1 = 0b00000000;

	TRISA = 0b00000011;
	TRISB = 0b00000000;
	TRISC = 0b10000000;
	TRISD = 0b00000000;
	TRISE = 0b00000000;

	PORTB = 0b00000000;
}

void main(){
	UINT cont = 1;
	UINT a = 1;
	UINT b = 1;

	hdw_setup();

	LED = 1;
	
	while(1){
		if(!(cont % 3)){
			LED = a ? a-- : a++;
		}

		if(!(cont % 7)){
			PORTBbits.RB1 = b ? b-- : b++;
		}

		delay_ms(1000);

		cont += 1;
		
		if(cont == 21){
            cont = 1;
		}
	}
}




