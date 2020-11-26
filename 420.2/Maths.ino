void Convert()
{
  int a = 10;

  char b;

  a = b - '0';
}


void MinSplit()
{
  i = 0;
   Serial.println("BTN Enter");
  while (Min > 0 && i < 15) {
    MinArray[i++] = Min % 10; // you can change the 10 here and below to any number base
   
   
    Min /= 10;
  }
 

 
}



void MaxSplit()
{
  i = 0;
  while (Max > 0 && i < 15) {
    MaxArray[i++] = Max % 10; // you can change the 10 here and below to any number base
    Max /= 10;
  }
 
}




 
void MyClear( int piArray[], int length ) 
{ 
    // The Array Has Degraded Into A Pointer 
    // So The Size Of The Array It Points To 
    // Is UNKNOWN To This Function, So sizeof 
    // Would Return The Size Of The POINTER, 
    // Not What It Actually Points To 
    memset( piArray, 0, ( length * sizeof( int ) )); 
 
    return; 
} 


void IOMaxSplit()
{
  i=0;
   Serial.print( "Array split " );
  while (IOMax > 0 && i < 15) {
    IOMaxArray[i++] = IOMax % 10; // you can change the 10 here and below to any number base
     Serial.println( IOMaxArray[i] );
    IOMax /= 10;
  }
 

  
}

void IOMinSplit()
{
  i = 0;
   Serial.print( "Array split " );
  while (IOMin > 0 && i < 15) {
    IOMinArray[i++] = IOMin % 10; // you can change the 10 here and below to any number base
     Serial.println( IOMinArray[i] );
    IOMin /= 10;
  }

 
  
}
