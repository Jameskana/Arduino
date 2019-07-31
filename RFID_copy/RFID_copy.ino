    #include <SPI.h>
    #include <RFID.h>

    RFID monModuleRFID(10,5);

    int UID[5];

    void setup()
    {
      Serial.begin(9600);
      SPI.begin();
      monModuleRFID.init();  

    }

    void loop()
    {
        if (monModuleRFID.isCard()) {  
              if (monModuleRFID.readCardSerial()) {        
                Serial.print("L'UID est: ");
                for(int i=0;i<=4;i++)
                {
                  UID[i]=monModuleRFID.serNum[i];
                  Serial.print(UID[i],DEC);
                  Serial.print(".");
                }
                Serial.println("");
              }          
              monModuleRFID.halt();
        }
        delay(1);    
    }
