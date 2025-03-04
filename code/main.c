/**
  @Date
  20 fevrier 2025

  @Nom du fichier
    main.c

  @Auteur
    Adriana Giselle Bardales Lazo
   
  @Sommaire
    Programme qui écrit et qui lit a une memoire EEPROM.

*/

#include "mcc_generated_files/mcc.h"

#define ADDRESSE_I2C_ECRAN  40			//0x28
#define ADDRESSE_I2C_EEPROM  0x50 //A0, A1 et A2 connectées a GND

void CCP_Capture(uint16_t capturedValue);
uint16_t H_Duree;
/*
    Début de l'application principale
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    uint8_t message[20];
    uint8_t addr[5];
    uint8_t addre[5];

    message[0]='0';
    
    for(int i=0; i<3; i++) 
    {
        message[1]='1';
        message[2]='2';
        
        addr[1] = 0x48; //'H'
        addr[2] = 0x69; //'i'
        
        addre[0] = 0x04;
        addre[1] = 0x30;
        addre[2] = 0x48; //'H'
        addre[3] = 0x69; //'i'
        
        /*//Code qui écrit 3 caractères sur l'écran
        while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY); //Passage de l'adresse
        I2C_SetBuffer(message, 3); //lit l'endroit des octets (3) de l'adresse messages
        I2C_MasterOperation(0);  //Démarrer une opération d'écriture
        while (I2C_Close() == I2C_BUSY); //Attendre que l'opération soit complète    
*/
        __delay_ms(1000);
        
        // Code qui lit 3 octets de la mémoire EEPROM
        
        // ÉCriture de deux octets de données à la EEPROM
        while(I2C_Open(ADDRESSE_I2C_EEPROM) == I2C_BUSY);   //passage de l?adresse I2C
        I2C_SetBuffer(addre, 4); //passage de l'adresse interne 0X0A30 sur 2 octet
        I2C_MasterOperation(0);	//opération d?écriture pour l?adresse interne
        while (I2C_Close() == I2C_BUSY);
        __delay_ms(1000);

        // Lecture de 3 octets de la EEPROM
        while(I2C_Open(ADDRESSE_I2C_EEPROM) == I2C_BUSY);	//passage de l?adresse I2C
        I2C_SetBuffer(addre, 2);	//High Byte and Low Byte addr
        I2C_MasterOperation(0);	//on fait un write
        I2C_SetBuffer(addr, 2);	//passage du tampon et du nombre de //lectures à faire
        I2C_MasterOperation(1);	//opération de lecture
        while (I2C_Close() == I2C_BUSY);  //on fait un write
        __delay_ms(1000     );
        
        //code qui ecrit les caracters sur l'ecran
        while(I2C_Open(ADDRESSE_I2C_ECRAN) == I2C_BUSY);   //passage de l?adresse de l'ecran
        I2C_SetBuffer(addr, 2);  //High Byte and Low Byte addr
        I2C_MasterOperation(0);
        while (I2C_Close() == I2C_BUSY); 
   
        
    }
    /**
 End of File
*/
}

void CCP_Capture(uint16_t capturedValue){
    H_Duree = capturedValue;
    TMR1_WriteTimer(0); //met le timer1 a 0
}