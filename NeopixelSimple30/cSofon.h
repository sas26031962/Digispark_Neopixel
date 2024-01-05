/*
 Класс одного софона
 */
#ifndef C_SOFON_H
#define C_SOFON_H
//========================================================================
 //---------------------------- ПОДКЛЮЧАЕМЫЕ ФАЙЛЫ ------------------------
 //========================================================================
#include <Adafruit_NeoPixel.h>
#include "cPixel.h"

 //========================================================================
 //-------------------------------- КОНСТАНТЫ -----------------------------
 //========================================================================
// Вывод контроллера Arduino к которому подключён NeoPixels
#define PIN            0

// Количество NeoPixels, подключённых к контроллеу Arduino
//#define NUMPIXELS      24
//#define NUMPIXELS      32
//#define NUMPIXELS      48
#define NUMPIXELS      62
//#define NUMPIXELS      8

 //========================================================================
 //--------------------------- ОБЪЯВЛЕНИЕ КЛАССОВ -------------------------
 //========================================================================
class cSofon{
 //------------------------------------------------------------------------
 // Атрибуты
 //------------------------------------------------------------------------
cTiming Timing;

// Объект управления NeoPixels
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
cPixel Field[NUMPIXELS];

public:

int X = 0;
bool IsFinish = false;
int Color1 = 0b10000000;



 //------------------------------------------------------------------------
 // Конструктор
 //------------------------------------------------------------------------
  cSofon();
 //------------------------------------------------------------------------
 // Методы
 //------------------------------------------------------------------------
 
 void install(
  int t,          //Время обновления 
  int x,          //Координата одной точки 
  unsigned char r,//Цвет этой точки 
  unsigned char g,// 
  unsigned char b //
  );

 // Нарисовать точку с коодинатой Х 
 void draw();
 void set(int x, unsigned char r, unsigned char g, unsigned char b);
 void operate();
 void view();
 
}Sofon;//End of class cSofon

 //========================================================================
 //--------------------------- РЕАЛИЗАЦИЯ МЕТОДОВ -------------------------
 //========================================================================

//
// Конструктор
//
cSofon::cSofon()
{
  for(int i = 0; i < NUMPIXELS; i++)
  {
    set(i, 0, 0, 0);   
  }
}  
void cSofon::install(int t, int x, unsigned char r, unsigned char g, unsigned char b)
{
  X = x;
  pixels.begin(); // Инициализация объекта NeoPixel
  cPixel::R = r;
  cPixel::G = g;
  cPixel::B = b;
  draw(); 
  
  Timing.start(t);
}

void cSofon::draw()
{
  pixels.setPixelColor(X, pixels.Color(cPixel::R, cPixel::G, cPixel::B)); 
  pixels.show(); 
}

void cSofon::set(int x, unsigned char r, unsigned char g, unsigned char b)
{
   Field[x].code(r, g, b);
}

void cSofon::operate()
{
  if(Timing.check())
  {
    view();
  }   
}

void cSofon::view()
{
  Field[X].decode();
  draw();
  X++;
  if(X == NUMPIXELS)
  {
    X = 0;
    IsFinish = true;
  }
}

#endif
