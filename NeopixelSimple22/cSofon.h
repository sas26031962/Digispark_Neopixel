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
//#define PIN            D2

// Количество NeoPixels, подключённых к контроллеу Arduino
//#define NUMPIXELS      24
#define NUMPIXELS      32
//#define NUMPIXELS      48
//#define NUMPIXELS      62
//#define NUMPIXELS      8

 //========================================================================
 //--------------------------- ОБЪЯВЛЕНИЕ КЛАССОВ -------------------------
 //========================================================================
class cSofon{
 //------------------------------------------------------------------------
 // Атрибуты
 //------------------------------------------------------------------------
int X = 0;
cTiming Timing;

// Объект управления NeoPixels
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
cPixel Field[NUMPIXELS];

public:

bool IsFinish = false;



 //------------------------------------------------------------------------
 // Конструктор
 //------------------------------------------------------------------------
  cSofon();
 //------------------------------------------------------------------------
 // Методы
 //------------------------------------------------------------------------
 void install(int t, int x, unsigned char r, unsigned char g, unsigned char b);
 void set(int x, unsigned char r, unsigned char g, unsigned char b);
 void operate();
 void draw(unsigned char r, unsigned char g, unsigned char b);
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
  draw(r, g, b); 
  
  Timing.start(t);
}

void cSofon::draw(unsigned char r, unsigned char g, unsigned char b)
{
  pixels.setPixelColor(X, pixels.Color(r, g, b)); 
  pixels.show(); 
}

void cSofon::set(int x, unsigned char r, unsigned char g, unsigned char b)
{
   Field[x].R = r;
   Field[x].G = g;
   Field[x].B = b;
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
  draw(Field[X].R, Field[X].G, Field[X].B);
  X++;
  if(X == NUMPIXELS)
  {
    X = 0;
    IsFinish = true;
  }
}

#endif
