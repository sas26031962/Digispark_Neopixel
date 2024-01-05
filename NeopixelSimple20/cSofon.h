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
#define NUMPIXELS      62
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
cPixel Pixel;

public:
bool Field[NUMPIXELS];
bool IsFinish = false;



 //------------------------------------------------------------------------
 // Конструктор
 //------------------------------------------------------------------------
  cSofon();
 //------------------------------------------------------------------------
 // Методы
 //------------------------------------------------------------------------
 void install(int t, int x);
 void operate();
 void setColor();
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
  Pixel = cPixel(0, 0, 150);}

void cSofon::install(int t, int x)
{
  X = x;
  pixels.begin(); // Инициализация объекта NeoPixel
  
  pixels.setPixelColor(X, pixels.Color(Pixel.R, Pixel.G, Pixel.B));
  pixels.show(); 
  
  Timing.start(t);
}

void cSofon::operate()
{
  if(Timing.check())
  {
    view();
  }   
}

void cSofon::setColor()
{
  int W = 120;
  W = W / 2;
  Pixel.R = 0;
  Pixel.G = 0;
  Pixel.B = 0; 
  if(X & 1) Pixel.R += W;
  if(X & 2) Pixel.G += W;
  if(X & 4) Pixel.B += W;
  
  if(X & 8) Pixel.R += W;
  if(X & 16) Pixel.G += W;
  if(X & 32) Pixel.B += W;
} 

void cSofon::view()
{
  setColor();
  if(Field[X])
    pixels.setPixelColor(X, pixels.Color(Pixel.R, Pixel.G, Pixel.B)); 
  else
    pixels.setPixelColor(X, pixels.Color(0,0,0));    
  pixels.show(); 
  X++;
  if(X == NUMPIXELS)
  {
    X = 0;
    IsFinish = true;
  }
}

#endif
