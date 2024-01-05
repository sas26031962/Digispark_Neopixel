/*
 Класс одного софона
 */
#ifndef C_SOFON_H
#define C_SOFON_H
//========================================================================
 //---------------------------- ПОДКЛЮЧАЕМЫЕ ФАЙЛЫ ------------------------
 //========================================================================
#include <Adafruit_NeoPixel.h>
#include "cSofon.h"

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
int R = 0;
int G = 0;
int B = 150;

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
	//...
}

void cSofon::install(int t, int x)
{
  X = x;
  pixels.begin(); // Инициализация объекта NeoPixel
  
  pixels.setPixelColor(X, pixels.Color(R,G,B));
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
//  if(X % 2) R = 150; else R = 0;
//  if(X % 3) G = 150; else G = 0;
//  if(X % 5) B = 150; else B = 0;
  int W = 120;
  W = W / 2;
  R = 0;
  G = 0;
  B = 0; 
  if(X & 1) R += W;
  if(X & 2) G += W;
  if(X & 4) B += W;
  
  if(X & 8) R += W;
  if(X & 16) G += W;
  if(X & 32) B += W;
} 

void cSofon::view()
{
  setColor();
  if(Field[X])
    pixels.setPixelColor(X, pixels.Color(R,G,B)); 
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
