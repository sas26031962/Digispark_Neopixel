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
#define DELAY_1 2
//#define DELAY_1 100


//----------------------------------------------------------------
// Глобальные переменные
//----------------------------------------------------------------
cBody Body1;
cBody Body2;
//cBody Body3;
//----------------------------------------------------------------
// Программа начальной установки
//----------------------------------------------------------------
void setup() 
{
  Sofon.install(DELAY_1, NUMPIXELS / 2, 0, 0, 150);
  delay(START_DELAY);

  Body1.born(NUMPIXELS / 2 + 5, true, 0, 1);
  Body2.born((NUMPIXELS / 2) - 5, true, 1, 2);
  
  //Body3.born((NUMPIXELS / 2), true, 1, 3);
  //Body3.setMobility(false);
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
    Body1.transform();
    Body2.move();
    Body2.transform();
    //Body3.move();
    //Body3.transform();
  }
} 
