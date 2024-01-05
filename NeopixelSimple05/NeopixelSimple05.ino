#include <Adafruit_NeoPixel.h>
#include "cTiming.h"
#include "cSofon.h"

#define START_DELAY 1000
#define DELAY_1 20

// Объект управления NeoPixels
cSofon Sofon1;

//----------------------------------------------------------------
// Программа начальной установки
//----------------------------------------------------------------
void setup() 
{

  //Sofon1.install(DELAY_1, 31, true);
  Sofon1.install(DELAY_1, 31, false
  );
  delay(START_DELAY);
}

//----------------------------------------------------------------
// Главный цикл программы
//----------------------------------------------------------------
void loop() 
{
  Sofon1.operate();
} 
