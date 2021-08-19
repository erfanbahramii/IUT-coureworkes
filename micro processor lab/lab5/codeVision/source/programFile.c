#include <headerFile.h>

char flag=1;
char shift = 0x01;

void changeDutyCycle(void)
{
    unsigned char in;
    int ocr;
    in = PINA;
    ocr = (18*in+265)/20;
    OCR0 = ocr;
}

void stepperMotorSignal(void)
{
    PORTB = shift<<4;
    if (flag==1)
    { 
        shift = shift<<1;              
        if (shift==0x10)
            shift = 0x01; 
    }
    else if (flag==2)
    {         
        shift = shift>>1;
        if (shift==0x00)
            shift = 0x08;
    }
        
}
