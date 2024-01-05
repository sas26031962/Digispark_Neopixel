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
int Braightness = 128;
unsigned char Color1 = 0b10000000;
unsigned char Color2 = Color1 >> 2; 
unsigned char Color3 = Color1 >> 5; 

cPixel Pixel1 = cPixel(Color1, 0, 0);
cPixel Pixel2 = cPixel(0, Color1, 0);
cPixel Pixel3 = cPixel(0, 0, Color1);


cBody Body1;
cBody Body2;
//----------------------------------------------------------------
// Программа начальной установки
//----------------------------------------------------------------
void setup() 
{
  Sofon.install(DELAY_1, x, 0, 0, 0);
  
  Sofon.X = x;
  Pixel1.decode();
  Sofon.draw();
  
  Sofon.X++;
  Pixel2.decode();
  Sofon.draw();
  
  Sofon.X++;
  Pixel3.decode();
  Sofon.draw();
  
  delay(START_DELAY);

  //Body1.born(NUMPIXELS / 2 + 5, true, 0);
  //Body2.born((NUMPIXELS / 2) - 5, true, 1);
}

//----------------------------------------------------------------
// Главный цикл программы
//----------------------------------------------------------------
void loop() 
{
  /*
  Sofon.operate();
  if(Sofon.IsFinish)
  {
    Sofon.IsFinish = false;

    Body1.move();
    Body1.transform();
    Body2.move();
    Body2.transform();
    
  }
  */
} 
