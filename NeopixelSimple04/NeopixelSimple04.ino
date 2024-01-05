#include <Adafruit_NeoPixel.h>
#include "cTiming.h"
#include "cSofon.h"

#define START_DELAY 1000
#define DELAY_1 20

// Объект управления NeoPixels
cSofon Sofon;

//----------------------------------------------------------------
// Программа начальной установки
//----------------------------------------------------------------
void setup() 
{

  //Sofon.install(DELAY_1, 1, true);
  Sofon.install(DELAY_1, 31, true);
  delay(START_DELAY);
}

//----------------------------------------------------------------
// Главный цикл программы
//----------------------------------------------------------------
void loop() 
{
  Sofon.operate();

}//End of void loop() 
