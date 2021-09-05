#include <mega16.h>
#include <stdio.h>
void initialization_USART(int baudrate,int RX,int TX)
{
int x,a=0,b=0,c=0,d=0,e=0,f=0;

c=RX/10;  d=RX%10;  e=TX/10;  f=TX%10;
x=(500000/baudrate)-1;
if(x<100)
{
    UBRRH=0x00;
    UBRRL=x;
}
else
{
    a=x/100;
    b=x%100;
    UBRRH=a;
    UBRRL=b;
}
UCSRA=(0<<RXC) | (0<<TXC) | (0<<UDRE) | (0<<FE) | (0<<DOR) | (0<<UPE) | (0<<U2X) | (0<<MPCM);
UCSRB=(c<<RXCIE) | (e<<TXCIE) | (0<<UDRIE) | (d<<RXEN) | (f<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);
UCSRC=(1<<URSEL) | (0<<UMSEL) | (0<<UPM1) | (0<<UPM0) | (0<<USBS) | (1<<UCSZ1) | (1<<UCSZ0) | (0<<UCPOL);

 }