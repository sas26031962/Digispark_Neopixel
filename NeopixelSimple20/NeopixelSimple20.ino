//----------------------------------------------------------------
// Подключаемые файлы
//----------------------------------------------------------------
#include "cTiming.h"
#include "cBody.h"

//----------------------------------------------------------------
// Константы
//----------------------------------------------------------------
#define START_DELAY 1000
//#define DELAY_1 20
//#define DELAY_1 2
#define DELAY_1 1
//#define DELAY_1 100


//----------------------------------------------------------------
// Глобальные переменные
//----------------------------------------------------------------
cBody Body1;
cBody Body2;
//----------------------------------------------------------------
// Программа начальной установки
//----------------------------------------------------------------
void setup() 
{
  Sofon.install(DELAY_1, NUMPIXELS / 2);
  delay(START_DELAY);

  Body1.install(NUMPIXELS / 2 + 15, false);
  Body2.install((NUMPIXELS / 2) - 15, true);

//  Body1.install(NUMPIXELS / 2 + 15, true);
//  Body2.install((NUMPIXELS / 2) - 15, true);

//  Body1.install(NUMPIXELS - 4, false);
//  Body2.install(3, true);
}

//----------------------------------------------------------------
// Главный цикл программы
//----------------------------------------------------------------
void loop() 
{
  Sofon.operate();
  if(Sofon.IsFinish)
  {
    Sofon.IsFinish = false;

    Body1.move();
    Body2.move();
  }
} 
