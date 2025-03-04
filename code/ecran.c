#include "ecran.h"
#include "mcc_generated_files/eusart2.h"

void ecranAllume(void)
{
    EUSART2_Write(0xFE);
    EUSART2_Write(0x41);
}

void ecranEteint(void)
{
    EUSART2_Write(0xFE);
    EUSART2_Write(0x42);
}

void cursorPosition(int position)
{
    EUSART2_Write(0xFE);
    EUSART2_Write(0x45);
    EUSART2_Write(position);
    
}

void videEcran(void)
{
    EUSART2_Write(0xFE);
    EUSART2_Write(0x51);
    
}

void ecrireCaracter(char caracter)
{
    EUSART2_Write(caracter);
    
}

void espaceD(void)
{
    EUSART2_Write(0xFE);
    EUSART2_Write(0x56);
}