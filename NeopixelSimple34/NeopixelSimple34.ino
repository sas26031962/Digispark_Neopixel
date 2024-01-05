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
int x = NUMPIXELS / 2;
int Brightness = 128;


cBody Body1;
cBody Body2;
cBody Body3;

//----------------------------------------------------------------
// Программа начальной установки
//----------------------------------------------------------------
void setup() 
{
  Sofon.install(DELAY_1, x, 0, 0, 0);
  
  Sofon.X = x;
  cPixel::R = 0;
  cPixel::G = 0;
  cPixel::B = Brightness;
  Sofon.draw();
  
  Sofon.X++;
  cPixel::R = 0;
  cPixel::G = Brightness;
  cPixel::B = 0;
  Sofon.draw();
  
  Sofon.X++;
  cPixel::R = Brightness;
  cPixel::G = 0;
  cPixel::B = 0;
  Sofon.draw();
  
  delay(START_DELAY);

  Body1.born(NUMPIXELS / 2 + 15, true, 0);
  Body2.born((NUMPIXELS / 2) - 15, true, 1);
  Body3.born((NUMPIXELS / 2) - 5, true, 2);
  Body3.SpeedVal = 3;

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
    Body3.move();
    Body3.transform();
    
  }
  
} 
