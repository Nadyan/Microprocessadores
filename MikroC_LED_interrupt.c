/*      
 *      mikroC compiler test
 *      Running on PicSimLab
 *      On and off B1 LED with interrupt
 */

int counter = 0;

void main(){
  TRISB = 0;
  T0CON.F6 = 1;

  while(1){
    PORTB.F1 = 1;
    Delay_ms(1000);
    PORTB.F1 = 0;
    Delay_ms(1000);
  }
}

void interrupt(){
    counter++;
    TMR0L = 96;      //low
    INTCON = 0x20;   //interrupt controller
    
    if(counter > 100){
        counter = 0;
        PORTB.F4 = !PORTB.F4;
    }
}