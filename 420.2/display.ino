
void LetDisplay(long a)
{


  //MyClear( result, 15 );
  dtostrf(a, 1, 0, result);
  DisplayValue(result);

}


void DisplayValue(char * thisWord) {

  //  dmd.drawString(1, 1, thisWord);
  dmd.drawString(  0 ,  0, thisWord, 15, GRAPHICS_NORMAL );
}

void DisplayFloatNumber( long uiTime )
{


  if (Flaotchangeval != uiTime)
  {
    Flaotchangeval = uiTime ;
    dmd.clearScreen(true);
  }

  //dmd.clearScreen(true);

  dmd.drawChar(  5,  0, '0' + ((uiTime % 10000) / 1000),  GRAPHICS_NORMAL ); // hundreds
  dmd.drawChar(  15,  0, '0' + ((uiTime % 1000) / 100),  GRAPHICS_NORMAL ); // hundreds
  dmd.drawChar( 25,  0, '0' + ((uiTime % 100)  / 10),   GRAPHICS_NORMAL ); // tens
  dmd.drawChar( 38,  0, '0' + (uiTime % 10),          GRAPHICS_NORMAL ); // units

  dmd.drawChar( 34 ,  0, '.', GRAPHICS_OR     );   // clock colon overlay on
}


void DisplayFloatNumber2( long uiTime )
{


  if (Flaotchangeval != uiTime)
  {
    Flaotchangeval = uiTime ;
    dmd.clearScreen(true);
  }

  //dmd.clearScreen(true);

  dmd.drawChar(  5,  0, '0' + ((uiTime % 10000) / 1000),  GRAPHICS_NORMAL ); // hundreds
  dmd.drawChar(  15,  0, '0' + ((uiTime % 1000) / 100),  GRAPHICS_NORMAL ); // hundreds
  dmd.drawChar( 24,  0, '0' + ((uiTime % 100)  / 10),   GRAPHICS_NORMAL ); // tens
  dmd.drawChar( 37,  0, '0' + (uiTime % 10),          GRAPHICS_NORMAL ); // units

  dmd.drawChar( 33,  0, '.', GRAPHICS_OR     );   // clock colon overlay on
}



void DisplayFloatNumber3( long uiTime )
{


  if (Flaotchangeval != uiTime)
  {
    Flaotchangeval = uiTime ;
    dmd.clearScreen(true);
  }

  //dmd.clearScreen(true);

  dmd.drawChar(  5,  0, '0' + ((uiTime % 10000) / 1000),  GRAPHICS_NORMAL ); // hundreds
  dmd.drawChar(  15,  0, '0' + ((uiTime % 1000) / 100),  GRAPHICS_NORMAL ); // hundreds
  dmd.drawChar( 24,  0, '0' + ((uiTime % 100)  / 10),   GRAPHICS_NORMAL ); // tens
  dmd.drawChar( 37,  0, '0' + (uiTime % 10),          GRAPHICS_NORMAL ); // units

  dmd.drawChar( 33,  0, '.', GRAPHICS_OR     );   // clock colon overlay on
}



void displayDMDstring(char * thisWord) {

  dmd.drawString(  0 ,  0, thisWord, 15, GRAPHICS_NORMAL );

}


void Display( long a)
{

  if (changeval != a)
  {
    changeval = a;
    dmd.clearScreen(true);
  }
}

//void LetDisplay(long a)
//{
//
//dtostrf(a, 1, 0, result);
//DisplayValue(result);
//
//}
//
//
