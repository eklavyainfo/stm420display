


void Setting()
{
  while ( SettingFlag == 1)
  {

    Serial.println(menucount);
    MenuSetting();
    if (digitalRead(BtnUp))
    {
      while (digitalRead(BtnUp)) {}
      dmd.clearScreen(true);
      if (menucount > 3)
      {
        menucount = 0;

        dmd.clearScreen(true);
      }
      else
      {
        menucount  ++;

        dmd.clearScreen(true);
      }


    }

    if (digitalRead(BtnMode))
    {
      while (digitalRead(BtnMode)) {}
      dmd.clearScreen(true);
      SettingFlag = 0;
    }
    if (digitalRead(BtnEnter))
    {
      Serial.print("ENTER KEY PRESSED");
      while (digitalRead(BtnEnter)) {}
      if (menucount == 2)
      {
        Serial.print("PARAMETER SELECTION");
        ParameterFlag = 1;
        dmd.clearScreen(true);
        ParameterSetting();
      }

      if (menucount == 3)
      {
        Serial.print("Reset");

        dmd.clearScreen(true);
        dmd.drawString( 0,  0, "Reset", 10, GRAPHICS_NORMAL );
        DefaultEprom();
        readeprom();
        SettingFlag = 0;
        delay(1000);
      }

      if (menucount == 4)
      {
        Serial.print("Brightness");

        dmd.clearScreen(true);
        dmd.drawString( 0,  0, "Brightness", 10, GRAPHICS_NORMAL );
        BrightnessFlag = 1;
        BrightnessSetting();

      }

      else
      {

        SetDevice();
        SettingFlag = 0;

        dmd.clearScreen(true);
      }



    }
  }

}
void MenuSetting()
{


  if (menucount == 0)
  {

    //    displayDMDstring(" 4-20 ");
    dmd.drawString( 0,  0, " 4-20", 5, GRAPHICS_NORMAL );
    Serial.println("4-20 ma");
  }


  if (menucount == 1)
  {

    //    displayDMDstring("Totalizer");

    dmd.drawString( 0,  0, "Totalizer", 10, GRAPHICS_NORMAL );
    Serial.println("Totalizer");
  }

  if (menucount == 2)
  {

    //    displayDMDstring("Parameter");

    dmd.drawString( 0,  0, "Parameter", 10, GRAPHICS_NORMAL );
    Serial.println("Parameter");
  }

  if (menucount == 3)
  {

    //    displayDMDstring("Parameter");

    dmd.drawString( 0,  0, "Reset", 10, GRAPHICS_NORMAL );
    Serial.println("Reset");
  }


  if (menucount == 4)
  {

    //    displayDMDstring("Parameter");

    dmd.drawString( 0,  0, "Brightness", 10, GRAPHICS_NORMAL );
    Serial.println("Reset");
  }



}


void SetDevice()
{


  if (menucount == 0)
  {

    DeviceID = 0;
    Serial.println("device as 4-20");
  }


  if (menucount == 1)
  {

    DeviceID = 1;
    Serial.println("device as TOtalizer");
  }




}



void  ParameterSetting()
{
  int p = 0;
  while (ParameterFlag == 1)
  {
    if (p == 0)
    {
      //      displayDMDstring("MIN");

      dmd.drawString( 0,  0, "  MIN", 6, GRAPHICS_NORMAL );
      Serial.println("MIN");
    }

    if (p == 1)
    {


      dmd.drawString( 0,  0, "  MAX", 6, GRAPHICS_NORMAL );
      Serial.println("MAX");
    }

    if (p == 2)
    {

      dmd.drawString( 0,  0, "IO MIN", 6, GRAPHICS_NORMAL );
      Serial.println("IO MIN");
    }

    if (p == 3)
    {

      dmd.drawString( 0,  0, "IO MAX", 6, GRAPHICS_NORMAL );
      Serial.println("IO MAX");
    }

    if (digitalRead(BtnEnter))
    {

      while (digitalRead(BtnEnter))
      {}

      Serial.println("BTN Enter");
      if (p == 0)
      {

        //        MinSplit();
        dmd.clearScreen(true);
        Digit = 0;
        MinSetFlag = 1;
        MinSet();
      }

      if (p == 1)
      {
        // MaxSplit();
        dmd.clearScreen(true);
        Digit = 0;
        MaxSetFlag = 1;
        MaxSet();
      }

      if (p == 2)
      { dmd.clearScreen(true);
        Digit = 0;
        IOMinSetFlag = 1;
        IOMinSet();
      }

      if (p == 3)
      {
        dmd.clearScreen(true);
        Digit = 0;
        IOMaxSetFlag = 1;
        IOMaxSet();
      }



    }

    if (digitalRead(BtnUp))
    {
      while (digitalRead(BtnUp))
      {}
      if (p == 3)
      {
        p = 0;
      }
      else
      {
        p++;
      }

      dmd.clearScreen(true);

    }


    if (digitalRead(BtnMode))
    {
      while (digitalRead(BtnMode))
      {}
      WriteEprom();
      dmd.clearScreen(true);
      ParameterFlag = 0;

    }

  }






}



void MinSet()
{
  dmd.clearScreen(true);
  while (MinSetFlag == 1)
  {



    LetDisplay(Min);

    if (digitalRead(BtnShift))
    {
      int k = 0;
      while (digitalRead(BtnShift))
      {
        LetDisplay(Min);

        if (Min <= 0)
        {
          Min = 0;
        }
        else
        {
          Min--;

          if (k < 10)
          {
            Min--;
          }
          else if (k < 20)
          {
            Min = Min - 10;
          }
          else if (k < 30)
          {
            Min = Min - 100;
          }
          else if (k < 40)
          {
            Min = Min - 1000;
          }
          else if (k < 50)
          {
            Min = Min - 10000;
          }
          k++;
          Serial.println(Min);
          delay(250);
          dmd.clearScreen(true);
        }
      }

      Serial.println(Min);
      //delay(250);

    }



    if (digitalRead(BtnUp))
    {
      int k = 0;
      // dmd.clearScreen(true);
      while (digitalRead(BtnUp))
      {
        LetDisplay(Min);


        if (k < 10)
        {
          Min++;
        }
        else if (k < 20)
        {
          Min = Min + 10;
        }
        else if (k < 30)
        {
          Min = Min + 100;
        }
        else if (k < 40)
        {
          Min = Min + 1000;
        }
        else if (k < 50)
        {
          Min = Min + 10000;
        }
        k++;
        Serial.println(Min);
        delay(250);
        dmd.clearScreen(true);

      }

    }


    if (digitalRead(BtnEnter))
    {
      while (digitalRead(BtnEnter))
      {}
      //   dmd.clearScreen(true);


      MinSetFlag = 0;
      WriteEprom();
      dmd.clearScreen(true);
    }

  }

}




void MaxSet()
{
  dmd.clearScreen(true);
  while (MaxSetFlag == 1)
  {



    LetDisplay(Max);

    if (digitalRead(BtnShift))
    {
      int k = 0;
      while (digitalRead(BtnShift))
      {
        LetDisplay(Max);

        if (Max <= 0)
        {
          Max = 0;
        }
        else
        {
          Max--;

          if (k < 10)
          {
            Max--;
          }
          else if (k < 20)
          {
            Max = Max - 10;
          }
          else if (k < 30)
          {
            Max = Max - 100;
          }
          else if (k < 40)
          {
            Max = Max - 1000;
          }
          else if (k < 50)
          {
            Max = Max - 10000;
          }
          k++;
          Serial.println(Max);
          delay(250);
          dmd.clearScreen(true);
        }
      }

      Serial.println(Max);
      //delay(250);

    }



    if (digitalRead(BtnUp))
    {
      int k = 0;
      // dmd.clearScreen(true);
      while (digitalRead(BtnUp))
      {
        LetDisplay(Max);


        if (k < 10)
        {
          Max++;
        }
        else if (k < 20)
        {
          Max = Max + 10;
        }
        else if (k < 30)
        {
          Max = Max + 100;
        }
        else if (k < 40)
        {
          Max = Max + 1000;
        }
        else if (k < 50)
        {
          Max = Max + 10000;
        }
        k++;
        Serial.println(Max);
        delay(250);
        dmd.clearScreen(true);

      }

    }

    if (digitalRead(BtnEnter))
    {

      while (digitalRead(BtnEnter))
      {}
      //   dmd.clearScreen(true);

      WriteEprom();
      MaxSetFlag = 0;
      dmd.clearScreen(true);
    }

  }

}










void BrightnessSetting()
{
  dmd.clearScreen(true);
  while (BrightnessFlag == 1)
  {



    LetDisplay(Brightness);

    if (digitalRead(BtnShift))
    {
      LetDisplay(Brightness);

      if (Brightness <= 0)
      {
        Brightness = 0;
      }
      else
      {
        Brightness--;

        Serial.println(Brightness);
        delay(250);
        dmd.clearScreen(true);
      }

      dmd.setBrightness(Brightness);

      Serial.println(Brightness);
      delay(250);

    }



    if (digitalRead(BtnUp))
    {

      LetDisplay(Brightness);
      if (Brightness < 250)
      {
        Brightness++;
      }
      Serial.println(Brightness);
      delay(250);
      dmd.clearScreen(true);
      dmd.setBrightness(Brightness);


    }

    if (digitalRead(BtnEnter))
    {

      while (digitalRead(BtnEnter))
      {}
      //   dmd.clearScreen(true);

      WriteEprom();
      BrightnessFlag = 0;
      dmd.clearScreen(true);
    }

  }

}
void IOMinSet()
{
  dmd.clearScreen(true);
  while (IOMinSetFlag == 1)
  {



    LetDisplay(IOMin);

    if (digitalRead(BtnShift))
    {
      int k = 0;
      while (digitalRead(BtnShift))
      {
        LetDisplay(IOMin);

        if (IOMin <= 0)
        {
          IOMin = 0;
        }
        else
        {
          IOMin--;

          if (k < 10)
          {
            IOMin--;
          }
          else if (k < 20)
          {
            IOMin = IOMin - 10;
          }
          else if (k < 30)
          {
            IOMin = IOMin - 100;
          }
          else if (k < 40)
          {
            IOMin = IOMin - 1000;
          }
          else if (k < 50)
          {
            IOMin = IOMin - 10000;
          }
          k++;
          Serial.println(IOMin);
          delay(250);
          dmd.clearScreen(true);
        }
      }

      Serial.println(IOMin);
      //delay(250);

    }



    if (digitalRead(BtnUp))
    {
      int k = 0;
      // dmd.clearScreen(true);
      while (digitalRead(BtnUp))
      {
        LetDisplay(IOMin);


        if (k < 10)
        {
          IOMin++;
        }
        else if (k < 20)
        {
          IOMin = IOMin + 10;
        }
        else if (k < 30)
        {
          IOMin = IOMin + 100;
        }
        else if (k < 40)
        {
          IOMin = IOMin + 1000;
        }
        else if (k < 50)
        {
          IOMin = IOMin + 10000;
        }
        k++;
        Serial.println(IOMin);
        delay(250);
        dmd.clearScreen(true);

      }

    }


    if (digitalRead(BtnEnter))
    {
      while (digitalRead(BtnEnter))
      {}


      WriteEprom();
      IOMinSetFlag = 0;
      dmd.clearScreen(true);
    }

  }

}




void IOMaxSet()
{
  dmd.clearScreen(true);
  while (IOMaxSetFlag == 1)
  {



    LetDisplay(IOMax);

    if (digitalRead(BtnShift))
    {
      int k = 0;
      while (digitalRead(BtnShift))
      {
        LetDisplay(IOMax);

        if (IOMax <= 0)
        {
          IOMax = 0;
        }
        else
        {
          IOMax--;

          if (k < 10)
          {
            IOMax--;
          }
          else if (k < 20)
          {
            IOMax = IOMax - 10;
          }
          else if (k < 30)
          {
            IOMax = IOMax - 100;
          }
          else if (k < 40)
          {
            IOMax = IOMax - 1000;
          }
          else if (k < 50)
          {
            IOMax = IOMax - 10000;
          }
          k++;
          Serial.println(IOMax);
          delay(250);
          dmd.clearScreen(true);
        }
      }

      Serial.println(IOMax);
      //delay(250);

    }



    if (digitalRead(BtnUp))
    {
      int k = 0;
      // dmd.clearScreen(true);
      while (digitalRead(BtnUp))
      {
        LetDisplay(IOMax);


        if (k < 10)
        {
          IOMax++;
        }
        else if (k < 20)
        {
          IOMax = IOMax + 10;
        }
        else if (k < 30)
        {
          IOMax = IOMax + 100;
        }
        else if (k < 40)
        {
          IOMax = IOMax + 1000;
        }
        else if (k < 50)
        {
          IOMax = IOMax + 10000;
        }
        k++;
        Serial.println(IOMax);
        delay(250);
        dmd.clearScreen(true);

      }

    }


    if (digitalRead(BtnEnter))
    {
      while (digitalRead(BtnEnter))
      {}
      WriteEprom();
      IOMaxSetFlag = 0;
      dmd.clearScreen(true);
    }

  }
}
