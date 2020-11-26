void EEPROMWritelong(int address, long value)
{
  //Decomposition from a long to 4 bytes by using bitshift.
  //One = Most significant -> Four = Least significant byte
  byte four = (value & 0xFF);
  byte three = ((value >> 8) & 0xFF);
  byte two = ((value >> 16) & 0xFF);
  byte one = ((value >> 24) & 0xFF);

  //Write the 4 bytes into the eeprom memory.
  EEPROM.write(address, four);
  EEPROM.write(address + 1, three);
  EEPROM.write(address + 2, two);
  EEPROM.write(address + 3, one);
}
long EEPROMReadlong(long address)
{
  //Read the 4 bytes from the eeprom memory.
  long four = EEPROM.read(address);
  long three = EEPROM.read(address + 1);
  long two = EEPROM.read(address + 2);
  long one = EEPROM.read(address + 3);

  //Return the recomposed long by using bitshift.
  return ((four << 0) & 0xFF) + ((three << 8) & 0xFFFF) + ((two << 16) & 0xFFFFFF) + ((one << 24) & 0xFFFFFFFF);
}




void readeprom()
{
  Max = EEPROMReadlong(MaxAdd);
  Serial.print("read Max=");
  Serial.println(Max);
  Min = EEPROMReadlong(MinAdd);
  Serial.print("read Min=");
  Serial.println(Min);
  IOMax = EEPROMReadlong(IOMaxAdd);
  Serial.print("read IOMax=");
  Serial.println(IOMax);
  IOMin = EEPROMReadlong(IOMinAdd);
  Serial.print("read IOMin=");
  Serial.println(IOMin);
  DeviceID = EEPROMReadlong(DeviceIDAdd);
  Serial.print("read DeviceID=");
  Serial.println(DeviceID);
  Total = EEPROMReadlong(TotalAdd);
   Brightness = EEPROMReadlong(BrightnessAdd);
  Serial.print("read Total =");
  Serial.println(Brightness );

}


void DefaultEprom()
{
  EEPROMWritelong( MaxAdd,  100);
  EEPROMWritelong( MinAdd,  0);
  EEPROMWritelong( IOMaxAdd,  32059);
  EEPROMWritelong( IOMinAdd,  6380);
  EEPROMWritelong( DeviceIDAdd,  0);
  EEPROMWritelong( TotalAdd,  0);
  EEPROMWritelong( BrightnessAdd,  100);
 readeprom();
}



void WriteEprom()
{
  long a = 0;
  a = EEPROMReadlong( TotalAdd);
  if (a != Total)
  {
    EEPROMWritelong( TotalAdd,  Total);
    Serial.print(" weitten Total=");
    Serial.println(Total);
  }


  a = EEPROMReadlong( MaxAdd);
  if (a != Max)
  {
    EEPROMWritelong( MaxAdd,  Max);
    Serial.print(" written Max=");
    Serial.println(Max);
  }
  a = EEPROMReadlong( MinAdd);
  if (a != Min)
  {

    EEPROMWritelong( MinAdd,  Min);
    Serial.print(" written Min=");
    Serial.println(Min);
  }
  a = EEPROMReadlong( IOMaxAdd);
  if (a != IOMax)
  {
    EEPROMWritelong( IOMaxAdd,  IOMax);
    Serial.print(" written IOMax=");
    Serial.println(IOMax);
  }

  a = EEPROMReadlong( IOMinAdd);
  if (a != IOMin)
  {
    EEPROMWritelong( IOMinAdd,  IOMin);
     Serial.print(" written IOMin=");
    Serial.println(IOMin);
  }

  a = EEPROMReadlong( DeviceIDAdd);
  if (a != DeviceID)
  {
    EEPROMWritelong( DeviceIDAdd,  DeviceID);
    Serial.print(" written DeviceID=");
    Serial.println(DeviceID);
  }

   a = EEPROMReadlong( BrightnessAdd);
  if (a != Brightness)
  {
    EEPROMWritelong( Brightness,  BrightnessAdd);
    Serial.print(" written BrightnessAdd=");
    Serial.println(Brightness);
  }







}
