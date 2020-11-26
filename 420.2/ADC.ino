 void GetAdc()
 {
  byte error, address;
  int nDevices;

 
  float Vs, Vch1, Vch2, X, denom, Rtherm, Tc;


  ADVal_1 = ad_convert(0x68, 1); // 16-bit measurments on both channels
 // ADVal_2 = ad_convert(0x68, 2);

  Serial.print(ADVal_1); Serial.print("    ");
  Serial.println(ADVal_2);
}



int ad_convert(byte adr, byte channel)
{
     int ADVal;
     byte Hi, Lo, Config;
     
     SWire.beginTransmission(adr);
     if (channel == 1)
     {    
         Config = 0x88;
        // config register %1010 1000
        // /RDY = 1, One Conversion, 15 samples per, PGA = X1
     }
     else
     {
         Config = 0x88 | 0x20; // 1 in bit 5 position
     }
     SWire.write(Config);
     SWire.endTransmission();
   
     delay(70);
     
     SWire.requestFrom((int)adr, (int) 3);
     Hi = SWire.read();
     Lo = SWire.read();
     Config = SWire.read();  // for possible debugging
     SWire.endTransmission();
   
     ADVal = Hi;
     ADVal = ADVal * 256 + Lo;
     return(ADVal);
}
