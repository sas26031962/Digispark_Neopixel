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
#define NUMPIXELS      62
//#define NUMPIXELS      8

 //========================================================================
 //--------------------------- ОБЪЯВЛЕНИЕ КЛАССОВ -------------------------
 //========================================================================
class cSofon{
 //------------------------------------------------------------------------
 // Атрибуты
 //------------------------------------------------------------------------
public:

// Объект управления NeoPixels
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int R = 0;
int G = 0;
int B = 150;

int X = 1;
int PreX = 0;
bool Direction = true;
bool IsRefraction = false;
cTiming Timing;


 //------------------------------------------------------------------------
 // Конструктор
 //------------------------------------------------------------------------
  cSofon();
 //------------------------------------------------------------------------
 // Методы
 //------------------------------------------------------------------------
 void install(int t, int x, bool d);
 void operate();
 void setColor();
 void draw();
 void move();
 
};//End of class cSofon

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

void cSofon::install(int t, int x, bool d)
{
  X = x;
  Direction = d;
  pixels.begin(); // Инициализация объекта NeoPixel
  
  pixels.setPixelColor(X, pixels.Color(R,G,B));
  pixels.show(); 
  
  Timing.start(t);
}

void cSofon::operate()
{
  if(Timing.check())
  {
    setColor(); 
    draw();
    move();
  }   
}

void cSofon::setColor()
{
  if(X % 2) R = 150; else R = 0;
  if(X % 3) G = 150; else G = 0;
  if(X % 5) B = 150; else B = 0;
}

void cSofon::draw()
{
  if(Direction)
  {
    if(IsRefraction)
    {
      IsRefraction = false;  
    }
    else
    {
      pixels.setPixelColor(X - 1, pixels.Color(0,0,0));
    } 
    pixels.setPixelColor(X, pixels.Color(R,G,B)); 
  }
  else
  {
    if(IsRefraction)
    {
      IsRefraction = false;  
    }
    else
    {
      pixels.setPixelColor(X + 1, pixels.Color(0,0,0));
    } 
    pixels.setPixelColor(X, pixels.Color(R,G,B)); 
  }
    pixels.show(); 
}

void cSofon::move()
{
  if(Direction)
  {
    X++;
    if(X == NUMPIXELS - 1)
    {
      Direction = !Direction;
      IsRefraction = true;
    }
  }
  else
  {
    X--;
    if(X == 0)
    {
      Direction = !Direction;
      IsRefraction = true;
    }
  }
}//End of void move()

#endif
