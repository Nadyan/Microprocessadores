/*
 * Project name: 7-Segment
 * Copyright:
     (c)www.studentcompanion.co.za,  2014
 * Test configuration:
     MCU:             PIC18F45K22
                      http://ww1.microchip.com/downloads/en/DeviceDoc/41412D.pdf
     Oscillator:      HS, 8.0000 MHz
     SW:              mikroC PRO for PIC V6.4.0
                      http://www.mikroe.com/en/compilers/mikroc/pro/pic/
*/
#define SW1 PORTC.RC0

void set_num(int digit);
void display_num();

unsigned char  const SEGMENT_MAP[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};
unsigned char digit=0;
unsigned int count = 0;

void main() {
     display_num();
     set_num(5);
}

void display_num(){
// ANSELC = 0;           // Configure PORTC as digital I/O
  //ANSELB = 0;           // Configure PORTB as digital I/O
  TRISD  = 0;           //Configure PORTB as Outputs

  TRISC0_bit  = 1;      //Configure RC0 as intput


  while(1){

      if (!SW1)          //Check if switch SW1 is closed
      {
         delay_ms(100);  //wait for 100ms  (switch debouncing)
         if (!SW1)       //Check if switch SW1 is still closed
         {
        LATD = (SEGMENT_MAP[digit]);


   delay_ms(1000);      //Delay 1 second
   digit++;
   if (digit>9){
      digit=0;
   }
         }
      }
      else
      {
        LATD = (SEGMENT_MAP[digit]);

      }
    }
}

void set_num(int digit){
  TRISD  = 0;           //Configure PORTB as Outputs
  TRISC0_bit  = 1;      //Configure RC0 as intput
  LATD = (SEGMENT_MAP[digit]);
}
