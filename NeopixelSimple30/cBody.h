/*
 Класс одного элемента софона
 */
#ifndef C_BODY_H
#define C_BODY_H
//========================================================================
 //---------------------------- ПОДКЛЮЧАЕМЫЕ ФАЙЛЫ ------------------------
 //========================================================================
#include "cSofon.h"

 //========================================================================
 //-------------------------------- КОНСТАНТЫ -----------------------------
 //========================================================================
#define MAX_PHASE 11
//#define MAX_PHASE 5

#define BODY_LEN 3
#define BOTTOM_EDGE 0
#define TOP_EDGE NUMPIXELS - 4


 //========================================================================
 //--------------------------- ОБЪЯВЛЕНИЕ КЛАССОВ -------------------------
 //========================================================================
class cBody
{
 //------------------------------------------------------------------------
 // Атрибуты
 //------------------------------------------------------------------------
public:
  bool Direction = true;
  int Head;
  int Len = BODY_LEN;
  cPixel Bones[BODY_LEN]; 
  int Phase = 0; 
  unsigned char Brightness = 0b10000000;

 //------------------------------------------------------------------------
 // Методы
 //------------------------------------------------------------------------
  void blank();
  void draw();
  void goDown();
  void goUp();
  void next();
  void reverse();

public:
  void transform();

 //------------------------------------------------------------------------
 // Конструктор
 //------------------------------------------------------------------------
  cBody();
  
 //------------------------------------------------------------------------
 // Методы
 //------------------------------------------------------------------------
 void born(int x, bool d, int p);
 void move();
};

cBody::cBody()
{
  Bones[0].code(Brightness, 0, 0);
  Bones[1].code(0, Brightness / 2, 0);
  Bones[2].code(0, 0, Brightness / 2);
}

void cBody::reverse()
{
  cPixel P;
  P = Bones[0];
  Bones[0] = Bones[2];
  Bones[2] = P;
}

void cBody::move()
{
  Direction ? goUp() : goDown();
}

void cBody::goUp()
{

    blank();
    Head++;
    if(Head == TOP_EDGE)
    {
      Direction = !Direction;
      //reverse();
      //next();
    }
    draw();
     
}

void cBody::goDown()
{
  blank();
  Head--;
  if(Head == BOTTOM_EDGE)
  {
    Direction = !Direction;
    //reverse();
    next();
  }
  draw(); 
 
}

void cBody::draw()
{
  Bones[0].decode();
  Sofon.set(Head + 0, cPixel::R, cPixel::G, cPixel::B);
  Bones[1].decode();
  Sofon.set(Head + 1, cPixel::R, cPixel::G, cPixel::B);
  Bones[2].decode();
  Sofon.set(Head + 2, cPixel::R, cPixel::G, cPixel::B);
}

void cBody::blank()
{
  Sofon.set(Head + 0, 0, 0, 0);
  Sofon.set(Head + 1, 0, 0, 0);
  Sofon.set(Head + 2, 0, 0, 0);
}

void cBody::born(int x, bool d, int p)
{
  
  Head = x;
  Direction = d;
  Phase = p;
  
  draw();
}

void cBody::next()
{
  Phase ++;
  if(Phase == MAX_PHASE) Phase = 0;
}

void cBody::transform()
{
  unsigned char Value = 128;
  int DeviderTail = 4;
  int DeviderHead = 2;
  cPixel Pixel, Pixel1, Pixel2;
  Pixel1 = cPixel(Value / DeviderTail, Value / DeviderTail, Value / DeviderTail);
  Pixel2 = Pixel1;
  
  switch(Phase)
  {
    case 0: Pixel = cPixel(Value, 0, 0); break;
    case 1: Pixel = cPixel(0, Value, 0); break;
    case 2: Pixel = cPixel(0, 0, Value); break;
    case 3: Pixel = cPixel(Value, Value, Value); break;
    case 4: Pixel = cPixel(Value, Value / DeviderHead, Value / DeviderHead); break;
    case 5: Pixel = cPixel(Value / DeviderHead, Value, Value / DeviderHead); break;
    case 6: Pixel = cPixel(Value / DeviderHead, Value / DeviderHead, Value); break;
    case 7: Pixel = cPixel(Value, Value, Value / DeviderHead); break;
    case 8: Pixel = cPixel(Value / DeviderHead, Value, Value); break;
    case 9: Pixel = cPixel(Value, Value / DeviderHead, Value); break;

    default:
      Pixel = cPixel(0, 0, 0);
      Pixel1 = Pixel;
      Pixel2 = Pixel;
    break;
  }
  if(Direction)
  {
    Bones[0] = Pixel2;
    Bones[1] = Pixel1;
    Bones[2] = Pixel;
  }
  else
  {
    Bones[0] = Pixel;
    Bones[1] = Pixel1;
    Bones[2] = Pixel2;
  }
  draw();
  
}//End of void cBody::transform()

#endif
