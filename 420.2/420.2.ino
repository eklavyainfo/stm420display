 

#include <SoftWire.h>
#include <EEPROM.h>
  double ADVal_1, ADVal_2;

SoftWire SWire(PB10, PB11, SOFT_FAST);

int ad_convert(byte channel);
void print_float(float f, int num_digits);




#include <DMD_STM32.h>
//#include "st_fonts/SystemFont5x7.h"
//#include "st_fonts/Arial_Black_16_ISO_8859_1.h"
#include "st_fonts/UkrRusArial14.h";
#include "gfx_fonts/GlametrixLight12pt7b.h"
#include "gfx_fonts/GlametrixBold12pt7b.h"
//#include "fonts/Arial_Black_16.h"

#include "st_fonts/SystemFont5x7.h"
#include "st_fonts/Arial_black_16.h"
#include "st_fonts/Arial_Black_16_ISO_8859_1.h"

// We'll use SPI 2
SPIClass dmd_spi(2);


//Fire up the DMD library as dmd
#define DISPLAYS_ACROSS 2
#define DISPLAYS_DOWN 1

// ----- Select pins for P10 matrix connection ------------
// pins A, B, SCLK may be any digital I/O, pin nOE should be PWM pin as PB1,PA8

// SPI specific pins as CLK and R_DATA has predefined values:
//   for SPI(1) CLK = PA5  R_DATA = PA7
//   for SPI(2) CLK = PB13  R_DATA = PB15
// --------------------------------------------------------
double  Value = 123;
char result[15];

#define DMD_PIN_A PA7

#define DMD_PIN_B PB12
#define DMD_PIN_nOE PB1
#define DMD_PIN_SCLK PB0

DMD dmd(DMD_PIN_A, DMD_PIN_B, DMD_PIN_nOE, DMD_PIN_SCLK, DISPLAYS_ACROSS, DISPLAYS_DOWN, dmd_spi );
//
//
//// --- Define fonts ----
//// DMD.h old style font
//DMD_Standard_Font UkrRusArial_F(UkrRusArial_14);
//
//// GFX font with sepatate parts for Latin and Cyrillic chars
////DMD_GFX_Font GlametrixL((uint8_t*)&GlametrixLight12pt7b,(uint8_t*)&GlametrixLight12pt8b_rus,0x80,13);
//DMD_GFX_Font GlametrixBold((uint8_t*)&GlametrixBold12pt7b, (uint8_t*)&GlametrixBold12pt8b_rus, 0x80, 13);
//


// DMD.h old style font
DMD_Standard_Font Arial_F(Arial_Black_16);
DMD_Standard_Font System5x7_F(System5x7);


////////////////////button/////////////

#define BtnMode PA6
#define BtnUp PA5
#define BtnShift PA4
#define BtnEnter PA3


int menucount = 0, BTNDELAY = 500, BTNDELAYSHORT = 250, DeviceID , ParameterFlag = 0;
/////////////////////////////////////////////////
/////////////////////////////////////////////////
int MinArray[7];
int MaxArray[7];
int IOMinArray[7];
int IOMaxArray[7];
long Min = 0;
long Max = 9000;
long IOMin = 6940;
long changeval = 0;
long Flaotchangeval = 0;
long  IOMax = 31637;

long PrvValue=0;

int Limit = 0;

int Digit = 0, i = 0, MinSetFlag = 0, MaxSetFlag = 0, IOMinSetFlag = 0, IOMaxSetFlag = 0, IOMinFlag = 0, IOMaxFlag = 0;
////////////////////////////////////////eprom/////////////////////
int MinAdd = 15;
int MaxAdd = 20;
int IOMinAdd = 25;
int IOMaxAdd = 35;
int DeviceIDAdd = 40;
int TotalAdd = 45;
int BrightnessAdd=50;
///////////////////////Variables//////////////////
int SettingFlag = 0;
int MenuFlag = 0;
int BrightnessFlag = 0;
int PrgCounter = 0;
double LowerLimit = 0;
double UpperLimit = 100;
unsigned long Total = 0;
float totalize = 0;
int Brightness=100;
//double  Value = 1234;


long s0, s1, s2, s3, s4, s5, s6, s7, s00, s11, s22, s33, s44, s55, s66, s77;



unsigned long DisplayValue2 = 0;



/*--------------------------------------------------------------------------------------
  UTF8 char recoding

  --------------------------------------------------------------------------------------*/
int utf8_rus(char* dest, const unsigned char* src) {

  uint8_t i, j;
  for ( i = 0, j = 0; src[i]; i++) {
    if ((src[i] == 0xD0 ) && src[i + 1])  {
      dest[j++] = src[++i] - 0x10;
    }
    else if ((src[i] == 0xD1 ) && src[i + 1]) {
      dest[j++] = src[++i] + 0x30;
    }
    else dest[j++] = src[i];
  }
  dest[j] = '\0';
  return j;
}


unsigned int Count = 1;


/*--------------------------------------------------------------------------------------
  setup
  Called by the Arduino architecture before the main loop begins
  --------------------------------------------------------------------------------------*/
void setup(void)
{
  
  dmd.init();
  dmd.clearScreen( true );   //true is normal (all pixels off), false is negative (all pixels on)
  // set matrix brightness (0-255)
  
  Serial.begin(115200);
   SWire.begin();
 dmd.selectFont(&Arial_F);
 readeprom();
   Brightness = EEPROMReadlong( BrightnessAdd);
   if(Brightness== -1)
   {

     DefaultEprom();
   }
 dmd.setBrightness(Brightness);
}


/*--------------------------------------------------------------------------------------
  loop
  Arduino architecture main loop
  --------------------------------------------------------------------------------------*/
void loop(void)
{

 GetAdc();

    // DisplayValue2 = (input - IOMin) * (Max - Min) / (IOMax - IOMin) + Min;
   float a = ((Max - Min) );

   float b = (IOMax - IOMin);

   float m = a / b;

   float c = m * IOMin;

   long DisplayValue = (m * ADVal_1) - c;
  
//LetDisplay(DisplayValue);

DisplayFloatNumber(DisplayValue);
Serial.println(DisplayValue);
  if (digitalRead(BtnMode))
  {
    dmd.clearScreen(true);
    delay(500);
    displayDMDstring("Setting");
    Serial.print("Setting");
    delay(2000);

    SettingFlag = 1;

    dmd.clearScreen(true);
    Setting();
  

  }
 
}
